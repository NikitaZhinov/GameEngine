#pragma once

#include <iostream>
#include <string>
#include <vector>

struct Size {
    int x, y;
};

struct Point {
    float x, y, z;
};

struct Color {
    int r, g, b;
    float a;
};

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <MainScript.hpp>
#include <Objects/Objects.hpp>
#include <Window/Window.hpp>
