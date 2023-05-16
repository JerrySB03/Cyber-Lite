#ifndef Users_hpp
#define Users_hpp

#include "Database/Database.hpp"
#include "DTOs/UserDtos.hpp"

#include <oatpp/core/data/mapping/type/Vector.hpp>
#include <oatpp/core/Types.hpp>
#include <oatpp/web/protocol/http/Http.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/core/utils/Random.hpp>
#include <argon2.h>

class Users
{
private:
    using Status = oatpp::web::protocol::http::Status;

    OATPP_COMPONENT(std::shared_ptr<Database>, database); // Get database component

public:
    oatpp::Object<UserDTO> createUser(const oatpp::Object<UserDTO> &dto, const oatpp::Object<HashDTO> &hash);
    oatpp::Object<UserDTO> updateUser(const oatpp::Object<UserDTO> &dto);
    oatpp::Object<HashDTO> getHashData(const oatpp::Object<UserDTO> &dto);
    oatpp::UInt32 getUserId(const oatpp::Object<UserDTO> &dto);
    oatpp::Object<UserDTO> getUserById(const oatpp::UInt32 &id, const oatpp::provider::ResourceHandle<oatpp::orm::Connection> &connection = nullptr);
    bool validateToken(const oatpp::String &token, const oatpp::UInt32 &id);
};
class Hash
{
private:
    using Status = oatpp::web::protocol::http::Status;

    argon2_context globalContext = {
        nullptr,           // Change this to be the output array
        HASHLEN,           // Hash output length
        nullptr,           // Change this to be the password pointer
        0,                 // Password length
        nullptr,           // Change this to be the salt array
        SALTLEN,           // Salt length
        NULL, 0,           //
        NULL, 0,           //
        2,                 // 2 Iterations
        (1 << 12),         // 4 Mebibytes
        1,                 // Single-threaded
        1,                 // Single-threaded
        ARGON2_VERSION_13, // Argon2 version
        NULL, NULL,        // Custom memory allocation / deallocation functions
        ARGON2_DEFAULT_FLAGS};

public:
    oatpp::Object<HashDTO> generateHash(const oatpp::String &password);
    bool verifyPassword(const oatpp::Object<HashDTO> &dto, const oatpp::String &password);
};
#endif /* Users_hpp */