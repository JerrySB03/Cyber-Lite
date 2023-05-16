#include "Tasks.hpp"

Tasks::Tasks(const oatpp::String &sourceFolder)
{
    std::filesystem::path tasksDir(sourceFolder);
    if (std::filesystem::exists(tasksDir) && std::filesystem::is_directory(tasksDir))
    {
        for (const auto &taskData : std::filesystem::directory_iterator(tasksDir))
        {
            auto dto = TaskDTO::createShared();
            oatpp::String categories;
            getTaskData(taskData.path(), dto, categories);
        }
    }
    else
    {
        OATPP_LOGE(sourceFolder, "Directory doesn't exist");
        delete (&database);            // Exit database
        exit(0b00100000 | 0b00000001); // Tasks | doesn't exist
    }
    auto dto = TaskDTO::createShared();
    oatpp::String categories = oatpp::String();
    database->createTask(dto, categories);
    OATPP_LOGD("Tasks", "Succesfully loaded");
}
int Tasks::getTaskData(std::filesystem::path taskDataPath, oatpp::Object<TaskDTO> &dto, oatpp::String &categories)
{
    for (const auto &taskData : std::filesystem::directory_iterator(taskDataPath))
    {
        if (std::filesystem::is_directory(taskData))
        {
            if (taskData.path().filename() == "files")
            {
                for (const auto &file : std::filesystem::directory_iterator(taskData))
                {
                    if (std::filesystem::is_regular_file(file))
                    {
                    }
                }
            }
            else
            {
                OATPP_LOGD("%s/%s/%s", "Unknown directory",
                           TASKS_FOLDER,
                           taskDataPath.filename().string().c_str(),
                           std::filesystem::path(taskData).filename().string().c_str());
            }
        }
        else
        { // Iterating through config files
        }
    }
    return 0;
}
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