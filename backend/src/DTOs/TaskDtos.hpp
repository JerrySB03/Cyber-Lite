#ifndef TaskDtos_hpp
#define TaskDtos_hpp

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class dbTaskDTO : public oatpp::DTO
{
    DTO_INIT(dbTaskDTO, DTO)

    DTO_FIELD_INFO(id) { info->description = "Task identifier"; }
    DTO_FIELD_INFO(name) { info->description = "Task display name"; }
    DTO_FIELD_INFO(categories) { info->description = "Task categories"; };
    DTO_FIELD_INFO(description)
    {
        info->description = "Task description";
        info->required = false;
    }
    DTO_FIELD_INFO(content) { info->description = "Task displayed formatted content"; };
    DTO_FIELD(Int32, id);
    DTO_FIELD(String, name);
    DTO_FIELD(String, description);
    DTO_FIELD(String, categories);
    DTO_FIELD(String, content);
};
class webTaskDTO : public oatpp::DTO
{
    DTO_INIT(webTaskDTO, DTO)

    DTO_FIELD_INFO(id) { info->description = "Task identifier"; }
    DTO_FIELD_INFO(name) { info->description = "Task display name"; }
    DTO_FIELD_INFO(categories) { info->description = "Task categories"; };
    DTO_FIELD_INFO(description)
    {
        info->description = "Task description";
        info->required = false;
    }
    DTO_FIELD_INFO(content) { info->description = "Task displayed formatted content"; };
    DTO_FIELD(Int32, id);
    DTO_FIELD(String, name);
    DTO_FIELD(String, description);
    DTO_FIELD(List<String>, categories);
    DTO_FIELD(String, content);
};
class NestedTasksDTO : public oatpp::DTO
{
    DTO_INIT(NestedTasksDTO, DTO)

    DTO_FIELD(List<oatpp::Object<webTaskDTO>>, Tasks);
};
#include OATPP_CODEGEN_END(DTO)

#endif /* TaskDtos_hpp */