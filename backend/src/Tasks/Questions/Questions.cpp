#include "Questions.hpp"
oatpp::String Questions::getQuestionsById(const oatpp::UInt32 &id)
{
    auto dbResult = database->getTaskById(id);

    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Task with id " + std::to_string(id) + " doesn't exist");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<dbTaskDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0]->questions;
}
oatpp::Object<dbQuestionDTO> Questions::convertToDbQuestions(const oatpp::Object<QuestionDTO> &dto)
{
    oatpp::List<oatpp::Object<dbQuestionDTO>> outDto = oatpp::List<oatpp::Object<dbQuestionDTO>>::createShared();
    oatpp::Object<dbQuestionDTO> dbQuestion = dbQuestionDTO::createShared();
    oatpp::List<oatpp::String> currentAnswers;
    oatpp::List<oatpp::String> currentCopyAnswers;
    for (auto &answersList : *dto->answers->answers)
    {
        currentAnswers = oatpp::List<oatpp::String>::createShared();
        for (auto &answer : *answersList->answers)
        {
            currentAnswers->push_back(answer);
        }
        dbQuestion->answers->push_back(database->DeserializeString(currentAnswers, dbQuestionDTO::customSeparator));
    }
    OATPP_LOGD("Questions", "Deleting");
    delete &dbQuestion;
    delete &currentAnswers;
    return outDto;
}

oatpp::List<oatpp::Object<QuestionDTO>> convertFromDbQuestions(const oatpp::List<oatpp::Object<dbQuestionDTO>> &dto)
{
}