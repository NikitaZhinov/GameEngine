#include <Window/Window.hpp>

namespace Engine {
    // public
    void Window::set_size(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void Window::set_title(const char* title) { this->title = title; }

    Point2D Window::get_size() { return { width, height }; }

    std::string Window::get_title() { return title; }

    // private
    int Window::width = 800;
    int Window::height = 600;
    std::string Window::title = "Hello, World!";
}