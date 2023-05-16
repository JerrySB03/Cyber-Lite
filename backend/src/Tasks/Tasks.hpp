#include "Database/Database.hpp"
#include "DTOs/TaskDtos.hpp"

#include <oatpp/core/data/mapping/type/Vector.hpp>
#include <oatpp/core/Types.hpp>
#include <oatpp/web/protocol/http/Http.hpp>
#include <oatpp/core/macro/component.hpp>   

class Tasks
{
private:
    using Status = oatpp::web::protocol::http::Status;

    OATPP_COMPONENT(std::shared_ptr<Database>, database); // Get database component
public:
    oatpp::List<oatpp::Object<TaskDTO>> getAll();
    oatpp::Object<TaskDTO> getById(const oatpp::UInt32 &id);
    void createTask(const oatpp::Object<TaskDTO> &task);
};