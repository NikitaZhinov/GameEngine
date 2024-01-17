#pragma once

#include <iostream>
#include <string>
#include <vector>

typedef struct {
	int x, y;
} Size;

typedef struct {
	float x, y, z;
} Point;

typedef struct {
	int r, g, b;
	float a;
} Color;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Window/Window.hpp>
#include <Objects/Objects.hpp>
#include <MainScript.hpp>