#ifndef DatabaseComponent_hpp
#define DatabaseComponent_hpp

#include "Database.hpp"

class DatabaseComponent
{
public:
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider)
    ([]
     {
        auto connectionProvider = std::make_shared<oatpp::sqlite::ConnectionProvider>(DATABASE_FILE);

        return oatpp::sqlite::ConnectionPool::createShared(connectionProvider,
            10, // max connections
            std::chrono::seconds(5) /* Connection time to live*/); }());

    OATPP_CREATE_COMPONENT(std::shared_ptr<Database>, database)
    ([]
     {
         // Get DB ConnectionProvider

         OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);

         // Create Db executor
         auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
         return std::make_shared<Database>(executor);
     }());
};

#endif /* DatabaseComponent_hpp */