cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -DDEBUG") # use for develop
# set(CMAKE_CXX_FLAGS "-O3") # use for release

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

file(GLOB SCRIPTS_SRC Scripts/*.cpp)
file(GLOB ENGINE_SRC Engine/src/*.cpp)
add_executable(GameEngine ${ENGINE_SRC} ${SCRIPTS_SRC})

target_include_directories(GameEngine PUBLIC Engine/include/)
target_include_directories(GameEngine PUBLIC Scripts/include/)

add_subdirectory(GLFW)
target_link_libraries(GameEngine PUBLIC glfw)

add_subdirectory(GLAD)
target_link_libraries(GameEngine PUBLIC glad)
