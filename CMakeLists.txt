cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

file(GLOB scripts_src Scripts/src/*.cpp)
file(GLOB engine_src Engine/src/*.cpp)

add_executable(GameEngine ${engine_src} ${scripts_src})

target_include_directories(GameEngine PUBLIC Engine/include/)
target_include_directories(GameEngine PUBLIC Scripts/include/)

add_subdirectory(GLFW)
target_link_libraries(GameEngine PUBLIC glfw)

add_subdirectory(GLAD)
target_link_libraries(GameEngine PUBLIC glad)
