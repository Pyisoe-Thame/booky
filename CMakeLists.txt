cmake_minimum_required(VERSION 3.5.1)
project(BOOKY VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CTest)
include(CPack)

enable_testing()

add_library(BOOKY booky.c)

# Add executable target and specify the source files
add_executable(main main.c)  # name of target, followed by list of source files

# Link library to the executable
target_link_libraries(main BOOKY)
