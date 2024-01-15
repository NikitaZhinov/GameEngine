cmake_minimum_required(VERSION 3.8)

project(GameEngine)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

file(GLOB scripts_src Scripts/src/*.cpp)

add_executable(GameEngine Engine/src/main.cpp ${scripts_src})

target_include_directories(GameEngine PUBLIC Engine/include/)

add_subdirectory(GLFW)
target_link_libraries(GameEngine PUBLIC glfw)

add_subdirectory(GLAD)
target_link_libraries(GameEngine PUBLIC glad)
