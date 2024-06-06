#pragma once

#include <glad/glad.h>
#include <iostream>
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

#include "GLFW/glfw3.h"
#include "MainScript.hpp"
#include "Objects/Objects.hpp"
#include "Window/Window.hpp"
