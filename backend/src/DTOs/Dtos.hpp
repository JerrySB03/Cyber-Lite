#ifndef Dtos_hpp
#define Dtos_hpp

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and validation
 */
class HelloDto : public oatpp::DTO
{

    DTO_INIT(HelloDto, DTO)

    DTO_FIELD_INFO(message) { info->description = "Message"; }
    DTO_FIELD_INFO(userAgent) { info->description = "User agent"; }
    DTO_FIELD_INFO(server) { info->description = "Server name and version"; }
    DTO_FIELD_INFO(host) { info->description = "Server IP address and port"; }
    DTO_FIELD(String, message);
    DTO_FIELD(String, userAgent, "user-agent");
    DTO_FIELD(String, host);
    DTO_FIELD(String, server);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* Dtos_hpp */