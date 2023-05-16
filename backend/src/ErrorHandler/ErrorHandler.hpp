#ifndef ErrorHandler_hpp
#define ErrorHandler_hpp

#include "DTOs/StatusDto.hpp"

#include <oatpp/web/server/handler/ErrorHandler.hpp>
#include <oatpp/web/protocol/http/outgoing/ResponseFactory.hpp>

class ErrorHandler : public oatpp::web::server::handler::ErrorHandler
{
private:
    using OutgoingResponse = oatpp::web::protocol::http::outgoing::Response;
    using Status = oatpp::web::protocol::http::Status;
    using ResponseFactory = oatpp::web::protocol::http::outgoing::ResponseFactory;
    
    std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;

public:
    ErrorHandler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper> &objectMapper);

    std::shared_ptr<OutgoingResponse> handleError(const Status &status, const oatpp::String &message, const Headers &headers) override;
};

#endif /* ErrorHandler_hpp */