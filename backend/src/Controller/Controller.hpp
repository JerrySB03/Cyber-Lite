#ifndef Controller_hpp
#define Controller_hpp

#include "DTOs/Dtos.hpp"
#include "DTOs/StatusDto.hpp"
#include "Users/Users.hpp"
#include "Tasks/Tasks.hpp"

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/web/protocol/http/incoming/SimpleBodyDecoder.hpp>
#include <oatpp/web/protocol/http/incoming/BodyDecoder.hpp>
#include <oatpp/web/protocol/http/Http.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * User REST API controller.
 */
class Controller : public oatpp::web::server::api::ApiController
{
public:
  Controller(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
      : oatpp::web::server::api::ApiController(objectMapper)
  {
  }

private:
  Users m_Users;                       // Create users object
  Hash m_Hash;                         // Create hash object
  Tasks m_Tasks = Tasks(TASKS_FOLDER); // Create tasks object
public:
  static std::shared_ptr<Controller> createShared(
      OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  )
  {
    return std::make_shared<Controller>(objectMapper);
  }
  ENDPOINT_INFO(root)
  {
    info->summary = "Test root endpoint";

    info->addResponse<Object<UserDTO>>(Status::CODE_200, "application/json");
  }
  ENDPOINT("GET", "/", root,
           HEADER(String, userAgent, "User-Agent"),
           HEADER(String, host, "Host"))
  {
    auto dto = HelloDto::createShared();
    dto->message = "/api GET request is working!";
    dto->server = Header::Value::SERVER;
    dto->userAgent = userAgent;
    dto->host = host;
    return createDtoResponse(Status::CODE_200, dto);
  }

  ENDPOINT_INFO(createUser)
  {
    info->summary = "Create new user";

    info->addConsumes<Object<UserDTO>>("application/json");

    info->addResponse<Object<UserDTO>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "/api/users", createUser,
           BODY_DTO(Object<UserDTO>, user))
  {
    oatpp::Object<HashDTO> hash = m_Hash.generateHash(user->password);
    return createDtoResponse(Status::CODE_200, m_Users.createUser(user, hash));
  }

  ENDPOINT_INFO(validateUser)
  {
    info->summary = "Validate user login";

    info->addResponse<Object<UserDTO>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_401, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "/api/users/login", validateUser,
           BODY_DTO(Object<UserDTO>, user))
  {
    oatpp::Object<HashDTO> hashData = m_Users.getHashData(user);
    if (m_Hash.verifyPassword(hashData, user->password))
    {
      return createDtoResponse(Status::CODE_200, user->id);
    }
    else
    {
      return createDtoResponse(Status::CODE_401, StatusDto::createShared());
    }
  }

  ENDPOINT_INFO(putUser)
  {
    info->summary = "Update one user by their Id";

    info->addConsumes<Object<UserDTO>>("application/json");

    info->addResponse<Object<UserDTO>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["userId"].description = "User Identifier";
  }
  ENDPOINT("PUT", "/api/users/{userId}", putUser,
           PATH(UInt32, userId),
           BODY_DTO(Object<UserDTO>, user))
  {
    user->id = userId;
    return createDtoResponse(Status::CODE_200, m_Users.updateUser(user));
  }

  ENDPOINT_INFO(getUserById)
  {
    info->summary = "Get one user data by their Id";

    info->addResponse<Object<UserDTO>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

    info->pathParams["userId"].description = "User Identifier";
  }
  ENDPOINT("GET", "/api/users/{userId}", getUserById,
           PATH(UInt32, userId))
  {
    return createDtoResponse(Status::CODE_200, m_Users.getUserById(userId));
  }
  ENDPOINT_INFO(getUserId)
  {
    info->summary = "Get user Id from user DTO";
    info->addResponse<String>(Status::CODE_200, "text/plain");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("POST", "/api/users/getId", getUserId,
           BODY_DTO(Object<UserDTO>, user))
  {
    return createResponse(Status::CODE_200, std::to_string(m_Users.getUserId(user)));
  }
  ENDPOINT_INFO(validateToken)
  {
    info->summary = "Validate user cookie";
    info->addResponse<String>(Status::CODE_200, "text/plain");
    info->addResponse<Object<StatusDto>>(Status::CODE_401, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->pathParams["userId"].description = "User\'s id to validate the token";
  }
  ENDPOINT("GET", "/api/cookies/validateToken/{userId}", validateToken,
           PATH(UInt32, id, "userId"),
           HEADER(String, cookie, "Cookie"))
  {
    oatpp::String token = std::to_string(cookie->back());
    OATPP_LOGD("validateToken", "token: %s", token->c_str());
    return createResponse(Status::CODE_200, std::to_string((uint8_t)m_Users.validateToken(token, id)));
  }
  ENDPOINT_INFO(getAllTasks)
  {
    info->summary = "Get all tasks from the database";
    info->addResponse<Object<NestedTasksDTO>>(Status::CODE_200, "application/json");
  }
  ENDPOINT("GET", "/api/tasks/getall", getAllTasks)
  {
    oatpp::Object<NestedTasksDTO> dto = oatpp::Object<NestedTasksDTO>::createShared();
    dto->Tasks = m_Tasks.getAll();
    return createDtoResponse(Status::CODE_200, dto);
  }
  ENDPOINT_INFO(getTaskById)
  {
    info->summary = "Get one task by its id";
    info->addResponse<Object<webTaskDTO>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "/api/tasks/{taskId}", getTaskById,
           PATH(UInt32, id, "taskId"))
  {
    return createDtoResponse(Status::CODE_200, m_Tasks.getById(id));
  }
  ENDPOINT_INFO(taskQuestionsByID){
    info->summary = "Get all questions from a task by its id";
    info->addResponse<String>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    info->pathParams["taskId"].description = "Task\'s id to get the questions";
  }
  ENDPOINT("GET", "/api/tasks/{taskId}/questions", taskQuestionsByID,
           PATH(UInt32, id, "taskId"))
  {
    return createResponse(Status::CODE_200, m_Tasks.getQuestionsById(id));
  }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* Controller_hpp */