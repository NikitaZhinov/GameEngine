#pragma once

#include <Engine/Engine.hpp>

class Window {
   public:
    void set_size(int width, int height);
    void set_title(const char *title);
    void set_background_color(int r, int g, int b);
    void set_background_color(int r, int g, int b, float a);
    void set_transparency(int a);

    Size get_size();
    std::string get_title();
    Color get_background_color();
    float get_transparency();

   private:
    static int width;
    static int height;
    static std::string title;
    static Color background_color;
};
