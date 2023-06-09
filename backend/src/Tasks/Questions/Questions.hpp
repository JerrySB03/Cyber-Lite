#include "Database/Database.hpp"
#include "DTOs/TaskDtos.hpp"

#include <oatpp/core/data/mapping/type/Vector.hpp>
#include <oatpp/core/Types.hpp>
#include <oatpp/web/protocol/http/Http.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/core/data/mapping/ObjectMapper.hpp>
#include <oatpp/parser/json/Utils.hpp>
#include <sstream>
#include <filesystem>

class Questions
{
public:
    using Status = oatpp::web::protocol::http::Status;

    OATPP_COMPONENT(std::shared_ptr<Database>, database); // Get database component
private:
    oatpp::Object<dbQuestionDTO> convertToDbQuestions(const oatpp::Object<QuestionDTO> &dto);
    oatpp::Object<QuestionDTO> convertFromDbQuestions(const oatpp::Object<dbQuestionDTO> &dto);

public:
    oatpp::Object<QuestionDTO> getQuestionsById(const oatpp::UInt32 &id);
    int insertQuestions(const oatpp::Object<QuestionDTO> &dto);
};