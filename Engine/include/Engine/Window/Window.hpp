#pragma once

#include "Engine/Engine.hpp"

class Window {
public:
    static void set_size(int width_, int height_);
    static void set_size(Size size);
    static void set_title(const char *title_);
    static void set_title(const std::string &title_);
    static void set_background_color(int r, int g, int b);
    static void set_background_color(int r, int g, int b, float a);
    static void set_background_color(const Color &color);
    static void set_transparency(float a);
    static void set_FPS(int fps);

    static Size get_size();
    static std::string get_title();
    static Color get_background_color();
    static float get_transparency();
    static int get_FPS();

    static void viewport(int x, int y, int width, int height);
    static void viewport(int x, int y, Size size);
    static void viewport(Point pos, Size size);
    static void viewport(Point pos, int width, int height);

private:
    static float width;
    static float height;
    static std::string title;
    static Color background_color;
    static int FPS;
};
