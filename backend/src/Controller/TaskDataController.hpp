#ifndef TaskDataController_hpp
#define TaskDataController_hpp

#include "Tasks/Tasks.hpp"

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/web/mime/multipart/FileProvider.hpp>
#include <oatpp/web/mime/multipart/InMemoryDataProvider.hpp>
#include <oatpp/web/mime/multipart/Reader.hpp>
#include <oatpp/web/mime/multipart/PartList.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class TaskDataController : public oatpp::web::server::api::ApiController // Static controller for static resources
{
public:
    TaskDataController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper)
    {
    }

private:
    Tasks m_Tasks; // Create tasks object
public:
    static std::shared_ptr<TaskDataController> createShared(
        OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    )
    {
        return std::make_shared<TaskDataController>(objectMapper);
    }
    ENDPOINT_INFO(root)
    {
        info->summary = "Test root endpoint";

        info->addResponse<Object<UserDTO>>(Status::CODE_200, "application/json");
    }
    ENDPOINT("GET", "/data/", root)
    {
        return createResponse(Status::CODE_200, "<h1>Here are the data stored for the tasks</h1>");
    }
    ENDPOINT_INFO(getTaskData)
    {
        info->addResponse<Object<TaskDTO>>(Status::CODE_200, "application/json");
    }
    ENDPOINT("GET", "/data/tasks/{id}/{filename}", getTaskData,
        PATH(Int32, id, "id"),
        PATH(String, filename, "filename"))
    {
            
    }
};
#include OATPP_CODEGEN_END(ApiController) //<- Begin Codegen

#endif /* TaskDataController_hpp */