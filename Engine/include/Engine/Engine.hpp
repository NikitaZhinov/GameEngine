#pragma once

#include <iostream>
#include <string>
#include <vector>

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

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Window/Window.hpp>
#include <Objects/Objects.hpp>
#include <MainScript.hpp>