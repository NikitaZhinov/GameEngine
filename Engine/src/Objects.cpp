#include <Objects/Objects.hpp>

IObject::~IObject() {
    delete[] vertices;
}

void IObject::draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColor3f(color.r / 255.0, color.g / 255.0, color.b / 255.0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, count_vertices);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void IObject::set_color(Color color) {
    this->color.r = color.r;
    this->color.g = color.g;
    this->color.b = color.b;
    this->color.a = color.a;
}

void IObject::set_position(float x, float y) {
    position.x = x;
    position.y = y;
    position.z = 0;
}

void IObject::set_position(float x, float y, float z) {
    position.x = x;
    position.y = y;
    position.z = z;
}

void IObject::set_position(Point position) {
    this->position.x = position.x;
    this->position.y = position.y;
    this->position.z = position.z;
}

void IObject::set_vertices(Point *vertices) {
    this->vertices = new Point[count_vertices];
    for (int i = 0; i < count_vertices; i++) {
        this->vertices[i].x = vertices[i].x;
        this->vertices[i].y = vertices[i].y;
        this->vertices[i].z = vertices[i].z;
    }
}

Point *IObject::get_vertices() {
    return vertices;
}

Color IObject::get_color() {
    return color;
}

Line::Line() {
    Point ver[2] = { { 0 } };
    count_vertices = 2;
    set_vertices(ver);
    set_color({ 0 });
}

Line::Line(Point vertices[2]) {
    count_vertices = 2;
    set_vertices(vertices);
    set_color({ 0 });
}

Triangle::Triangle() {
    Point ver[3] = { { 0 } };
    count_vertices = 3;
    set_vertices(ver);
    set_color({ 0 });
}

Triangle::Triangle(Point vertices[3]) {
    count_vertices = 3;
    set_vertices(vertices);
    set_color({ 0 });
}

Rectangle::Rectangle() {
    Point ver[4] = { { 0 } };
    count_vertices = 4;
    set_vertices(ver);
    set_color({ 0 });
}

Rectangle::Rectangle(Size size) {
    Point ver[4] = {
        {     0,       0, 0},
        {size.x,       0, 0},
        {size.x, -size.y, 0},
        {     0, -size.y, 0}
    };
    count_vertices = 4;
    set_vertices(ver);
    set_color({ 0 });
}

void Rectangle::set_size(Size size) {
    Point ver[4] = {
        {     0,       0, 0},
        {size.x,       0, 0},
        {size.x, -size.y, 0},
        {     0, -size.y, 0}
    };
    set_vertices(ver);
}

Square::Square(Point *vertices, int n) {
    count_vertices = n;
    set_vertices(vertices);
    set_color({ 0 });
}
