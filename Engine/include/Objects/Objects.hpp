#pragma once

#include <Engine/Engine.hpp>

class IObject {
   public:
    virtual void draw() = 0;

    virtual void set_vertices(Point *vertices) = 0;

    virtual Point *get_vertices() = 0;
    virtual Color get_color() = 0;

    void set_color(Color color);

   protected:
    void draw_obj(Point *vertices, int n, Color color);
    Color color;
};

class Line : public IObject {
   public:
    Line();
    Line(Point vertices[2]);
    void draw() override;

    void set_vertices(Point vertices[2]) override;

    Point *get_vertices() override;
    Color get_color() override;

   private:
    Point vertices[2];
};

class Triangle : public IObject {
   public:
    Triangle();
    Triangle(Point vertices[3]);
    void draw() override;

    void set_vertices(Point vertices[3]) override;

    Point *get_vertices() override;
    Color get_color() override;

   private:
    Point vertices[3];
};

class Rectangle : public IObject {
   public:
    Rectangle();
    Rectangle(Size size);

    void draw() override;
    void set_size(Size size);

    Point *get_vertices() override;
    Color get_color() override;

   private:
    Point vertices[4];

    void set_vertices(Point vertices[4]) override;
};

class Square : public IObject {
   public:
    Square();
    Square(Point vertices[4]);
    void draw() override;

    void set_vertices(Point vertices[4]) override;

    Point *get_vertices() override;
    Color get_color() override;

   private:
    Point vertices[4];
};
