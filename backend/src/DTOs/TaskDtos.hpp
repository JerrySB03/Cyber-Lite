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
    DTO_FIELD_INFO(tasks)
    {
        info->description = "Task description";
        info->required = false;
    }
    DTO_FIELD_INFO(content) { info->description = "Task displayed formatted content"; };
    DTO_FIELD(Int32, id);
    DTO_FIELD(String, name);
    DTO_FIELD(String, tasks);
    DTO_FIELD(String, categories);
    DTO_FIELD(String, content);
};
class webTaskDTO : public oatpp::DTO
{
    DTO_INIT(webTaskDTO, DTO)

    DTO_FIELD_INFO(id) { info->description = "Task identifier"; }
    DTO_FIELD_INFO(name) { info->description = "Task display name"; }
    DTO_FIELD_INFO(categories) { info->description = "Task categories"; };
    DTO_FIELD_INFO(tasks)
    {
        info->description = "Task description";
        info->required = false;
    }
    DTO_FIELD_INFO(content) { info->description = "Task displayed formatted content"; };
    DTO_FIELD_INFO(questions) { info->description = "Task questions"; };
    DTO_FIELD(Int32, id);
    DTO_FIELD(String, name);
    DTO_FIELD(String, tasks);
    DTO_FIELD(List<String>, categories);
    DTO_FIELD(String, content);
    DTO_FIELD(String, questions);
};
class NestedTasksDTO : public oatpp::DTO
{
    DTO_INIT(NestedTasksDTO, DTO)

    DTO_FIELD(List<oatpp::Object<webTaskDTO>>, Tasks);
};
class AnswerDTO : public oatpp::DTO
{
    DTO_INIT(AnswerDTO, DTO)

    DTO_FIELD_INFO(answer) { info->description = "Answer"; }
    DTO_FIELD_INFO(correct) { info->description = "Boolean if the answer is correct"; }
    DTO_FIELD(String, answer);
    DTO_FIELD(Boolean, correct);
};
class AnswersDTO : public oatpp::DTO
{
    DTO_INIT(AnswersDTO, DTO)

    DTO_FIELD(List<oatpp::Object<AnswerDTO>>, answers);
    const static char customSeparator = '+';
};
class QuestionDTO : public oatpp::DTO
{
    DTO_INIT(QuestionDTO, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(String, type);
    DTO_FIELD(Object<AnswersDTO>, answers);
    DTO_FIELD(String, correct);
};
class dbQuestionDTO : public oatpp::DTO
{
    DTO_INIT(dbQuestionDTO, DTO)

    DTO_FIELD(Int32, task_id);
    DTO_FIELD(String, type);
    DTO_FIELD(String, answers);
    DTO_FIELD(String, correct);
    const static char customSeparator = ';';
};
#include OATPP_CODEGEN_END(DTO)

#endif /* TaskDtos_hpp */