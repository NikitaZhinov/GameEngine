#pragma once

#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <chrono>
#include <glad/glad.h>
#include <print>
#include <string>

struct Size {
    float x, y;
};

struct Point {
    float x, y, z;
};

struct Color {
    int r, g, b;
    float a;
};

#include "Objects/Objects.hpp"
#include "Scripts/MainScript.hpp"
#include "Window/Window.hpp"
