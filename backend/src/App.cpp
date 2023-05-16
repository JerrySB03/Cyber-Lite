#include "Controller/Controller.hpp"
#include "AppComponent.hpp"

#include <oatpp/network/Server.hpp>
#include <oatpp-swagger/Controller.hpp>
#include <oatpp/core/utils/ConversionUtils.hpp>
#include <iostream>

/**
 *  run() method.
 *  1) set Environment components.
 *  2) add ApiController's endpoints to router
 *  3) run server
 */
void run(const oatpp::base::CommandLineArguments& args)
{
    AppComponent components(args); // Create scope Environment components

    /* create ApiControllers and add endpoints to router */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    oatpp::web::server::api::Endpoints docEndpoints; // Register endpoints for API documentation (swagger-ui)

    docEndpoints.append(router->addController(Controller::createShared())->getEndpoints());
    router->addController(oatpp::swagger::Controller::createShared(docEndpoints)); // Register swagger-ui endpoint
    /* create server */

    oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                  components.serverConnectionHandler.getObject());

    OATPP_LOGD("Server", "Running on port %s...", components.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());

    server.run();
}

/**
 *  main
 */
int main(int argc, const char *argv[])
{

    oatpp::base::Environment::init();
    run(oatpp::base::CommandLineArguments(argc, argv));

    /* Print how much objects were created during app running, and what have left-probably leaked */
    /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

    oatpp::base::Environment::destroy();

    return 0;
}