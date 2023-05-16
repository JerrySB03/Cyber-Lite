#include "Tasks.hpp"

namespace file
{
    oatpp::String readFile(std::filesystem::path filePath)
    {
        std::ifstream file(filePath);
        std::stringstream fileContentsStream;
        fileContentsStream << file.rdbuf();
        return (fileContentsStream.str());
    }
}

Tasks::Tasks(const oatpp::String &sourceFolder)
{
    std::filesystem::path tasksDir(sourceFolder + "/");
    if (std::filesystem::is_directory(tasksDir))
    {
        for (const auto &taskData : std::filesystem::directory_iterator(tasksDir))
        {
            if (std::filesystem::path(taskData).filename().string()[0] == '#') // If the task starts with #, skip it
            {
                OATPP_LOGV("Tasks", "Skipping task \"%s\"", std::filesystem::path(taskData).filename().string().erase(0, 1).c_str());
                continue;
            }
            auto dto = dbTaskDTO::createShared();
            auto rc = getTaskData(taskData.path(), dto);
            if (rc) // Will return 0 if successfull
            {
                exit(rc);
            }
            auto dbResult = database->createTask(dto);
            if (dbResult->isSuccess())
            {
                OATPP_LOGV("Tasks", "Succesfully loaded task \"%s\"", dto->name->c_str());
            }
            else
            {
                if (dbResult->getErrorMessage()->find("UNIQUE constraint failed: tasks.name") == std::string::npos) // If the error is is that the task already exists, skip it
                {
                    continue;
                }
                OATPP_LOGE("Tasks", "Failed to create task \"%s\"", dto->name->c_str());
                exit(0b10000000 | 0b00100000); // Database | Tasks
            }
        }
    }
    else
    {
        OATPP_LOGE(sourceFolder + "/", "Directory doesn't exist");
        exit(0b00100000 | 0b00000001); // Tasks | doesn't exist
    }
    auto dto = dbTaskDTO::createShared();
    database->createTask(dto);
}
int Tasks::getTaskData(std::filesystem::path taskDataPath, oatpp::Object<dbTaskDTO> &dto)
{
    if (!std::filesystem::is_directory(taskDataPath))
    {
        OATPP_LOGE("Tasks", "Task \"%s\" is not a directory", taskDataPath.filename().string().c_str());
        return 1;
    }
    auto outDto = dbTaskDTO::createShared();
    outDto->name = taskDataPath.filename().string();
    OATPP_LOGV("Tasks", "Loading task \"%s\"", outDto->name->c_str())
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
                    else
                    {
                        OATPP_LOGE("Tasks", "Unknown file in %s/files/%s", taskDataPath.filename().string().c_str(), std::filesystem::path(file).filename().string().c_str());
                    }
                }
            }
            else
            {
                OATPP_LOGW("Tasks", "Unknown directory %s/%s/%s/", TASKS_FOLDER, taskDataPath.filename().string().c_str(), std::filesystem::path(taskData).filename().string().c_str());
            }
        }
        else
        { // Iterating through config files
            oatpp::String filename = std::filesystem::path(taskData).filename().string();
            if (std::filesystem::is_regular_file(taskData))
            {
                if (filename == "CATEGORIES")
                {
                    outDto->categories = file::readFile(std::filesystem::path(taskData));
                }
                else if (filename == "CONTENT.md")
                {
                    outDto->content = file::readFile(std::filesystem::path(taskData));
                }
                else if (filename == "DESCRIPTION.md")
                {
                    outDto->description = file::readFile(std::filesystem::path(taskData));
                }
                else if (filename == "QUESTIONS.json")
                {
                }
                else
                {
                    OATPP_LOGW("Tasks", "Unknown file %s/%s/%s", TASKS_FOLDER, taskDataPath.filename().string().c_str(), filename->c_str());
                }
            }
            else
            {
                OATPP_LOGE("Tasks", "Unknown file %s/%s/%s", TASKS_FOLDER, taskDataPath.filename().string().c_str(), filename->c_str());
            }
        }
    }
    if (outDto->content == nullptr || outDto->description == nullptr || outDto->categories == nullptr)
    {
        OATPP_LOGE("Tasks", "Task \"%s\" is missing data", outDto->name->c_str());
        return (0b00100000 | 0b00000010);
    }
    dto = outDto;
    return 0;
}
oatpp::List<oatpp::Object<webTaskDTO>> Tasks::getAll()
{
    auto dbResult = database->getAllTasks();
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::List<oatpp::Object<dbTaskDTO>>>();
    oatpp::List<oatpp::Object<webTaskDTO>> outDto = oatpp::List<oatpp::Object<webTaskDTO>>::createShared();
    for (auto dto : *result)
    {
        outDto->push_back(this->convertToWebDTO(dto));
    }
    return outDto;
}

oatpp::Object<webTaskDTO> Tasks::getById(const oatpp::UInt32 &id)
{
    auto dbResult = database->getTaskById(id);

    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Task with id " + std::to_string(id) + " doesn't exist");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<dbTaskDTO>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return this->convertToWebDTO(result[0]);
}
oatpp::Object<webTaskDTO> Tasks::convertToWebDTO(const oatpp::Object<dbTaskDTO> &dto)
{
    auto outDto = webTaskDTO::createShared();
    outDto->id = dto->id;
    outDto->name = dto->name;
    outDto->description = dto->description;
    outDto->content = dto->content;
    outDto->categories = oatpp::List<oatpp::String>::createShared(); // Initialize categories list
    std::string current;
    for (const char &c : *dto->categories)
    {
        if (c == ';')
        {
            outDto->categories->push_back(current);
            current = "";
        }
        else
        {
            current += c;
        }
    }
    return outDto;
}