#include "Database/Database.hpp"
#include "DTOs/TaskDtos.hpp"
#include "Questions/Questions.hpp"

#include <oatpp/core/data/mapping/type/Vector.hpp>
#include <oatpp/core/Types.hpp>
#include <oatpp/web/protocol/http/Http.hpp>
#include <oatpp/core/macro/component.hpp>   
#include <oatpp/core/data/mapping/ObjectMapper.hpp>
#include <oatpp/parser/json/Utils.hpp>
#include <sstream>
#include <filesystem>
#include <fstream>

class Tasks
{
private:
    using Status = oatpp::web::protocol::http::Status;

    OATPP_COMPONENT(std::shared_ptr<Database>, database); // Get database component

    int getTaskData(std::filesystem::path taskDataPath, oatpp::Object<dbTaskDTO> &dto);
    oatpp::Object<webTaskDTO> convertToWebDTO(const oatpp::Object<dbTaskDTO> &dto);

    Questions m_Questions;
public:
    Tasks(const oatpp::String &sourceFolder);
    oatpp::List<oatpp::Object<webTaskDTO>> getAll();
    oatpp::Object<webTaskDTO> getById(const oatpp::UInt32 &id);
    oatpp::String getQuestionsById(const oatpp::UInt32 &id);  
};