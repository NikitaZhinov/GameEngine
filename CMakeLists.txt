cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT WIN32)
    if(NOT CMAKE_BUILD_TYPE)
      set(CMAKE_BUILD_TYPE Release)
        set(CMAKE_CXX_FLAGS_DEBUG "-DNDEBUG")
    endif()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

include(FetchContent)
FetchContent_Declare(
    GLFW
    GIT_REPOSITORY "https://github.com/glfw/glfw.git"
    GIT_TAG 3.3.9
)
FetchContent_Declare(
    GLAD
    GIT_REPOSITORY "https://github.com/Dav1dde/glad.git"
    GIT_TAG c
)
FetchContent_MakeAvailable(GLFW GLAD)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

file(GLOB SCRIPTS_SRC Scripts/*.cpp)
file(GLOB ENGINE_SRC Engine/src/*.cpp)
add_executable(GameEngine ${ENGINE_SRC} ${SCRIPTS_SRC})

target_include_directories(GameEngine PUBLIC Engine/include/)

target_include_directories(GameEngine PUBLIC ${GLFW_SOURCE_DIR}/include)
target_link_libraries(GameEngine PUBLIC glfw)

add_library(glad STATIC ${glad_SOURCE_DIR}/include/glad/glad.h ${glad_SOURCE_DIR}/src/glad.c)
target_include_directories(glad PUBLIC ${glad_SOURCE_DIR}/include)
target_link_libraries(GameEngine PUBLIC glad)
