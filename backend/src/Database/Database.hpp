#ifndef Database_hpp
#define Database_hpp

#include "DTOs/UserDtos.hpp"
#include "DTOs/TaskDtos.hpp"
#include <oatpp-sqlite/orm.hpp>

#include OATPP_CODEGEN_BEGIN(DbClient)

class Database : public oatpp::orm::DbClient
{
public:
      Database(const std::shared_ptr<oatpp::orm::Executor> &executor)
          : oatpp::orm::DbClient(executor)
      {
            oatpp::orm::SchemaMigration migration(executor);
            migration.addFile(1, DATABASE_MIGRATIONS "/001_init.sql");
            migration.migrate();

            auto version = executor->getSchemaVersion();
            OATPP_LOGD("Database", "Migration - OK. Version=%lld.", version);
      }
      QUERY(createUser,
            "INSERT INTO Users"
            "(username, email, hash, salt) VALUES "
            "(:user.username, :user.email, :hash.hash, :hash.salt);",
            PARAM(oatpp::Object<UserDTO>, user),
            PARAM(oatpp::Object<HashDTO>, hash))

      QUERY(updateUser,
            "UPDATE Users "
            "SET "
            " username=:user.username, "
            " email=:user.email, "
            " password=:user.password, "
            " token=:user.token "
            "WHERE "
            " id=:user.id;",
            PARAM(oatpp::Object<UserDTO>, user))

      QUERY(getUserById,
            "SELECT "
            " id, "
            " username, "
            " email, "
            " token "
            "FROM Users "
            "WHERE id=:id;",
            PARAM(oatpp::UInt32, id))

      QUERY(getUserId,
            "SELECT id FROM "
            "Users WHERE "
            " username=:user.username "
            "AND "
            " email=:user.email;",
            PARAM(oatpp::Object<UserDTO>, user))
      QUERY(deleteUserById,
            "DELETE FROM Users WHERE id=:id;",
            PARAM(oatpp::UInt32, id))
      QUERY(getHashData,
            "SELECT hash, salt FROM Users "
            "WHERE "
            " email=:user.email "
            "OR "
            " username=:user.username;",
            PARAM(oatpp::Object<UserDTO>, user))
      
      QUERY(createTask,
            "INSERT INTO Tasks"
            "(name, description, categories) VALUES "
            "(:task.name, :task.description, :categories);",
            PARAM(oatpp::Object<TaskDTO>, task),
            PARAM(oatpp::String, categories))
      QUERY(getTaskById,
            "SELECT * "
            " FROM TASKS "
            "WHERE "
            " id=:id;",
            PARAM(oatpp::UInt32, id))

      QUERY(getAllTasks,
            "SELECT * "
            " FROM Tasks;")
};

#include OATPP_CODEGEN_END(DbClient)

#endif /* Database_hpp */