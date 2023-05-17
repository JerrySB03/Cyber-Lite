add_library(${project_name}-core
        Controller/Controller.hpp
        DTOs/Dtos.hpp
        AppComponent.hpp
        Database/Database.hpp
        Database/DatabaseComponent.hpp
        SwaggerComponent.hpp
        DTOs/Dtos.hpp
        DTOs/StatusDto.hpp
        DTOs/UserDtos.hpp
        DTOs/TaskDtos.hpp
        ErrorHandler/ErrorHandler.hpp
        ErrorHandler/ErrorHandler.cpp
        Users/Users.hpp
        Users/Users.cpp
        Tasks/Tasks.hpp
        Tasks/Tasks.cpp
        Tasks/Questions/Questions.cpp
        Tasks/Questions/Questions.hpp
)


add_executable(${project_name}-exe
    App.cpp    
)

target_link_libraries(${project_name}-core
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-sqlite
        PUBLIC oatpp::oatpp-swagger
        argon2
)



target_include_directories(${project_name}-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${project_name}-exe ${project_name}-core) 
add_dependencies(${project_name}-exe ${project_name}-core)

include_directories(${OATPP_INCLUDE_DIRS})