#ifndef UserDtos_hpp
#define UserDtos_hpp

#define HASHLEN 64
#define SALTLEN 32

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class UserDTO : public oatpp::DTO
{
    DTO_INIT(UserDTO, DTO)

    DTO_FIELD_INFO(id) { info->description = "User identifier"; }
    DTO_FIELD_INFO(username) { info->description = "username";  }
    DTO_FIELD_INFO(email) { info->description = "User email"; }
    DTO_FIELD_INFO(password) { info->description = "User password"; }
    DTO_FIELD_INFO(token) { info->description = "User token for authentication"; }
    DTO_FIELD(UInt32, id);
    DTO_FIELD(String, username, "username");
    DTO_FIELD(String, email, "email");
    DTO_FIELD(String, password, "password");
    DTO_FIELD(String, token, "token");
};

class HashDTO : public oatpp::DTO
{
    DTO_INIT(HashDTO, DTO)

    DTO_FIELD_INFO(hash) { info->description = "Password hash"; }
    DTO_FIELD_INFO(salt) { info->description = "Password salt"; }
    
    DTO_FIELD(oatpp::String, hash);
    DTO_FIELD(oatpp::String, salt);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDtos_hpp */