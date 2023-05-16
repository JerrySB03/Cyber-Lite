add_executable(${project_name}-test
        test.cpp
)

enable_testing()

add_test(project-tests ${project_name}-test)