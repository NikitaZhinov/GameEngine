#pragma once

#include <iostream>
#include <string>

typedef struct {
	int x, y;
} Point2D;

typedef struct {
	int r, g, b;
} Color;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Window/Window.hpp>
#include <MainScript.hpp>