#include <Window/Window.hpp>

// public
void Window::set_size(int width, int height) {
    this->width = width;
    this->height = height;
}

void Window::set_title(const char *title) { this->title = title; }

void Window::set_background_color(int r, int g, int b) {
    background_color.r = r;
    background_color.g = g;
    background_color.b = b;
    background_color.a = 0;
}

void Window::set_background_color(int r, int g, int b, float a) {
    background_color.r = r;
    background_color.g = g;
    background_color.b = b;
    background_color.a = a;
}

Size Window::get_size() { return {width, height}; }

std::string Window::get_title() { return title; }

Color Window::get_background_color() { return background_color; }

// private
int Window::width = 800;
int Window::height = 600;
std::string Window::title = "Hello, World!";
Color Window::background_color = {0, 0, 0, 0};