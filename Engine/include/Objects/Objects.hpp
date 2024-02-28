#pragma once

#include <Engine/Engine.hpp>

class IObject {
public:
    ~IObject();

    void draw();

    void set_vertices(Point *vertices);
    void set_color(Color color);
    void set_position(float x, float y);
    void set_position(float x, float y, float z);
    void set_position(Point position);

    Point *get_vertices();
    Color get_color();

protected:
    Color color;
    Point position;
    int count_vertices;
    Point *vertices;
};

class Line : public IObject {
public:
    Line();
    Line(Point vertices[2]);
};

class Triangle : public IObject {
public:
    Triangle();
    Triangle(Point vertices[3]);
};

class Rectangle : public IObject {
public:
    Rectangle();
    Rectangle(Size size);

    void set_size(Size size);
};

class Square : public IObject {
public:
    Square(Point *vertices, int n);
};
