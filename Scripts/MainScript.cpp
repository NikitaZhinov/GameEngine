#include "Engine/Scripts/MainScript.hpp"

namespace scripts {
    Point v[5] = {
        {    0,    0, 0 },
        {    1,    0, 0 },
        {    1,   -1, 0 },
        {    0,   -1, 0 },
        { -0.3, -0.5, 0 }
    };
    Size s = { 1, 1 };
    Square tr(v, 5);
    Rectangle tr1(s);

    void start() {
        Window::set_size(800, 600);
        Window::set_title("shiiiiii");
        Window::set_background_color(255, 255, 255);
        tr.set_color({ 255, 0, 0, 0 });
        tr1.set_color({ 0, 255, 0, 0 });
        tr.set_position(-1, 0.5, 0);
        tr1.set_position(0, 0.5, 0);
    }

    void update() {
        // std::println("{}", Window::get_FPS());

        tr.draw();
        tr1.draw();
    }
} // namespace scripts
