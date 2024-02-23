#pragma once

#include <Engine/Engine.hpp>

class IObject {
public:
    ~IObject();

    virtual void draw() = 0;

    void set_vertices(Point *vertices);
    void set_color(Color color);
    void set_position(float x, float y);
    void set_position(float x, float y, float z);
    void set_position(Point position);

    Point *get_vertices();
    Color get_color();

protected:
    void draw_obj(Point *vertices, Color color);

    Color color;
    Point position;
    int count_vertices;
    Point *vertices;
};

class Line : public IObject {
public:
    Line();
    Line(Point vertices[2]);
    void draw() override;
};

class Triangle : public IObject {
public:
    Triangle();
    Triangle(Point vertices[3]);
    void draw() override;
};

class Rectangle : public IObject {
public:
    Rectangle();
    Rectangle(Size size);

    void draw() override;
    void set_size(Size size);
};

class Square : public IObject {
public:
    Square(Point *vertices, int n);
    void draw() override;
};
