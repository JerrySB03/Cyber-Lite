#include "Users.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>

namespace hash
{
    oatpp::String Hexify(const uint8_t bytes[], const size_t &length)
    {
        std::stringstream ss;
        for (size_t i = 0; i < length; i++)
        {
            ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]);
        }
        return ss.str();
    }

    oatpp::Vector<oatpp::UInt8> deHexify(const oatpp::String &hex)
    {

        oatpp::Vector<oatpp::UInt8> bytes = oatpp::Vector<oatpp::UInt8>::createShared();

        for (size_t i = 0; i + 2 <= hex->length(); i += 2)
        {
            // Extract two characters from the string
            std::string byteString = hex->substr(i, 2);

            // Convert the two characters to a byte
            uint8_t byte = static_cast<uint8_t>(std::stoul(byteString, nullptr, 16));
            bytes->push_back((oatpp::UInt8)byte);
        }
        return bytes;
    }
}
bool Users::validateToken(const oatpp::String &token, const oatpp::UInt32 &id){
    auto dbResult = database->getUserById(id);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error - userId returned multible outputs");

    if(result[0]->token == token){
        return true;
    }
    return false;
}
oatpp::Object<UserDTO> Users::createUser(const oatpp::Object<UserDTO> &dto, const oatpp::Object<HashDTO> &hash)
{
    auto dbResult = database->createUser(dto, hash);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto userId = oatpp::sqlite::Utils::getLastInsertRowId(dbResult->getConnection());

    return getUserById((v_int32)userId);
}
oatpp::Object<UserDTO> Users::updateUser(const oatpp::Object<UserDTO> &dto)
{
    auto dbResult = database->updateUser(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    return getUserById(dto->id);
}
oatpp::UInt32 Users::getUserId(const oatpp::Object<UserDTO> &dto)
{
    auto dbResult = database->getUserId(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_404, "Invalid username and/or email");
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User with provided credentials doesn't exist");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0]->id;
}
oatpp::Object<HashDTO> Users::getHashData(const oatpp::Object<UserDTO> &dto)
{
    auto dbResult = database->getHashData(dto);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_401, "Invalid credentials");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<HashDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];
}

oatpp::Object<UserDTO> Users::getUserById(const oatpp::UInt32 &id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection)
{

    auto dbResult = database->getUserById(id, connection);

    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "User not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<UserDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];
}

oatpp::Object<HashDTO> Hash::generateHash(const oatpp::String &password)
{
    oatpp::Object<HashDTO> outHash = HashDTO::createShared(); // Create HashDTO object

    uint8_t hash[HASHLEN];
    uint8_t salt[SALTLEN];

    argon2_context context = this->globalContext; // Copy the global context
    context.out = hash;                           // Set the output array
                                                  //
    context.pwd = (uint8_t *)password->c_str();   // Set the password
    context.pwdlen = password->length();          // Set the password length
                                                  //
    context.salt = salt;                          // Set the salt
    int rc = argon2id_ctx(&context);

    OATPP_ASSERT_HTTP(rc == ARGON2_OK, Status::CODE_500, "Error generating hash, error:" + std::to_string(rc)); // Check if there was an error creating the hash

    outHash->hash = hash::Hexify(hash, HASHLEN); // Convert the hash to a hex string
    outHash->salt = hash::Hexify(salt, SALTLEN); // Convert the salt to a hex string

    return outHash;
}
bool Hash::verifyPassword(const oatpp::Object<HashDTO> &dto, const oatpp::String &password)
{
    uint8_t hash[HASHLEN];
    uint8_t salt[SALTLEN];

    oatpp::Vector<oatpp::UInt8> saltVector = hash::deHexify(dto->salt); // Convert the salt hex string to a byte vector
    std::copy(saltVector->begin(), saltVector->end(), salt);            // Copy the salt vector to the salt array

    argon2_context context = this->globalContext; // Copy the global context
    context.out = hash;                           // Set the output array
                                                  //
    context.pwd = (uint8_t *)password->c_str();   // Set the password
    context.pwdlen = password->length();          // Set the password length
                                                  //
    context.salt = salt;                          // Set the salt
    OATPP_LOGD("Hash", "Stored hash: %s", dto->hash->c_str());

    int rc = argon2id_ctx(&context); // Hash the password

    OATPP_ASSERT_HTTP(rc == ARGON2_OK, Status::CODE_500, "Error verifying the password, error:" + std::to_string(rc)); // Check if there was an error creating the hash

    oatpp::String hashedPass = hash::Hexify(hash, HASHLEN); // Convert the hash array to a string
    OATPP_LOGD("Hash", "Hashed password: %s", hashedPass->c_str());
    return (hashedPass == dto->hash); // Compare the two strings
}
