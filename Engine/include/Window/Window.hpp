#pragma once

#include <Engine/Engine.hpp>

namespace Engine {
    class Window {
    public:
        void set_size(int width, int height);
        void set_title(const char* title);

        Point2D get_size();
        std::string get_title();

    private:
        static int width;
        static int height;
        static std::string title;
    };
}
