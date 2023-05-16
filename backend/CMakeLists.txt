cmake_minimum_required(VERSION 3.11)

set(project_name cyber-lite) ## setting the project name

project(${project_name} CXX)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Find dependencies
find_package(oatpp REQUIRED)
find_package(oatpp-sqlite REQUIRED)
find_package(oatpp-swagger REQUIRED)
find_package(oatpp-zlib REQUIRED)
find_package(SQLite3 REQUIRED)

add_definitions(
        ## define path to swagger-ui static resources folder
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"
        
        ## SQLite database file
        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"
        
        ## SQLite database test file
        -DTESTDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/test-db.sqlite"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"

        ## Path to tasks folder
        -DTASKS_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/../tasks"
)
include(CTest)
#enable_testing()

#add_subdirectory(tests)
add_subdirectory(src)

set_target_properties(${project_name}-core ${project_name}-exe PROPERTIES
        CXX_STANDARD 17
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
)

