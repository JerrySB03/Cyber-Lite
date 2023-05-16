#ifndef StatusDto_hpp
#define StatusDto_hpp

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class StatusDto : public oatpp::DTO
{

    DTO_INIT(StatusDto, DTO)

    DTO_FIELD_INFO(status) { info->description = "Short status text"; }
    DTO_FIELD_INFO(code) { info->description = "Status code"; }
    DTO_FIELD_INFO(message) { info->description = "Verbose message"; }

    DTO_FIELD(String, status);
    DTO_FIELD(Int32, code);
    DTO_FIELD(String, message);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* StatusDto_hpp */