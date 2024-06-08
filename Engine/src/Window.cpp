#include "Engine/Window/Window.hpp"

// public
void Window::set_size(int width_, int height_) {
    width = (float)width_;
    height = (float)height_;
}

void Window::set_size(Size size) {
    width = size.x;
    height = size.y;
}

void Window::set_title(const char *title_) {
    title = title_;
}

void Window::set_title(const std::string &title_) {
    title = title_;
}

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

void Window::set_background_color(const Color &color) {
    background_color = color;
}

void Window::set_transparency(float a) {
    background_color.a = a;
}

void Window::set_FPS(int fps) {
    FPS = fps;
}

Size Window::get_size() {
    return { width, height };
}

std::string Window::get_title() {
    return title;
}

Color Window::get_background_color() {
    return background_color;
}

float Window::get_transparency() {
    return background_color.a;
}

int Window::get_FPS() {
    return FPS;
}

void Window::viewport(int x, int y, int width, int height) {
    glViewport(x, y, width, height);
}

void Window::viewport(int x, int y, Size size) {
    viewport(x, y, size.x, size.y);
}

void Window::viewport(Point pos, Size size) {
    viewport(pos.x, pos.y, size.x, size.y);
}

void Window::viewport(Point pos, int width, int height) {
    viewport(pos.x, pos.y, width, height);
}

// private
float Window::width = 800;
float Window::height = 600;
std::string Window::title = "Hello, World!";
Color Window::background_color = { 0, 0, 0, 0 };
int Window::FPS = 0;
