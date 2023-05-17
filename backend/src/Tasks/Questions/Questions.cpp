#include "Questions.hpp"
oatpp::Object<QuestionDTO> Questions::getQuestionsById(const oatpp::UInt32 &id)
{
    auto dbResult = database->getTaskById(id);

    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Task with id " + std::to_string(id) + " doesn't exist");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<dbQuestionDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return this->convertFromDbQuestions(result[0]);
}
oatpp::Object<dbQuestionDTO> Questions::convertToDbQuestions(const oatpp::Object<QuestionDTO> &dto)
{

    oatpp::Object<dbQuestionDTO> outDto = dbQuestionDTO::createShared();
    oatpp::List<oatpp::String> currentAnswers = oatpp::List<oatpp::String>::createShared();
    oatpp::List<oatpp::String> currentAnswersList = oatpp::List<oatpp::String>::createShared();
    oatpp::List<oatpp::String> correct = oatpp::List<oatpp::String>::createShared();
    for (auto &answersList : *dto->answers->answers)
    {
        currentAnswers = oatpp::List<oatpp::String>::createShared();
        for (auto &answer : *answersList.getPtr())
        {
            currentAnswers->push_back(std::to_string(answer));
        }
        for(auto &correctAnswer : *answersList->correct)
        {
            correct->push_back(std::to_string(correctAnswer));
        }
        currentAnswersList->push_back(database->DeserializeString(currentAnswers, dbQuestionDTO::customSeparator));
    }

    outDto->answers = database->DeserializeString(currentAnswersList, dbQuestionDTO::customSeparator);
    outDto->correct = database->DeserializeString(correct, dbQuestionDTO::customSeparator);
    delete &currentAnswers;
    return outDto;
}

oatpp::Object<QuestionDTO> Questions::convertFromDbQuestions(const oatpp::Object<dbQuestionDTO> &dto)
{
    oatpp::Object<QuestionDTO> outDto = QuestionDTO::createShared();
    oatpp::List<oatpp::String> currentAnswersList = database->SerializeString(*dto->answers, dbQuestionDTO::customSeparator);
    oatpp::List<oatpp::Int32> currentAnswers = oatpp::List<oatpp::Int32>::createShared();
    for(auto &answersList : *currentAnswersList)
    {
        oatpp::List<oatpp::Int32> currentAnswers = oatpp::List<oatpp::Int32>::createShared();
        for(auto &answer : *database->SerializeString(answersList, dbQuestionDTO::customSeparator))
        {
            currentAnswers->push_back(std::stoi(answer->c_str()));
        }
        outDto->answers->answers->push_back(currentAnswers);
    }
    OATPP_LOGD("Questions", "Deleting");
    delete &currentAnswers;
    return outDto;
}
int Questions::insertQuestions(const oatpp::Object<QuestionDTO> &dto)
{
    auto dbResult = database->insertQuestion(convertToDbQuestions(dto));
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    return 0;
}