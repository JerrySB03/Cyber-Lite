#include "ErrorHandler.hpp"

ErrorHandler::ErrorHandler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper> &objectMapper)
    : m_objectMapper(objectMapper)
{
}

std::shared_ptr<ErrorHandler::OutgoingResponse>
ErrorHandler::handleError(const Status &status, const oatpp::String &message, const Headers &headers)
{

    auto error = StatusDto::createShared();
    error->status = "ERROR";
    error->code = status.code;
    error->message = message;

    if (error->code >= 500)
    {
        // If the error is a server error
        OATPP_LOGE(std::string("Error ") + std::to_string(error->code), error->message->c_str()); // Log the error
        error->message = "Internal server error";
    }

    auto response = ResponseFactory::createResponse(status, error, m_objectMapper);

    for (const auto &pair : headers.getAll())
    {
        response->putHeader(pair.first.toString(), pair.second.toString());
    }

    return response;
}