#include "Tasks.hpp"
oatpp::List<oatpp::Object<TaskDTO>> Tasks::getAll()
{
    auto dbResult = database->getAllTasks();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::List<oatpp::Object<TaskDTO>>>();

    return result;
}

oatpp::Object<TaskDTO> Tasks::getById(const oatpp::UInt32 &id)
{
    auto dbResult = database->getTaskById(id);

    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Task with id " + std::to_string(id) + " doesn't exist");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<TaskDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];
}
void Tasks::createTask(const oatpp::Object<TaskDTO> &task)
{
    auto dbResult = database->createTask(task);
    if (!dbResult->isSuccess())
    {
        OATPP_LOGE("Task-" + task->name, dbResult->getErrorMessage()->c_str());
    }
    return;
}