#include <Objects/Objects.hpp>

void IObject::draw_obj(Point *vertices, int n, Color color) {
	glPushMatrix();
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(color.r / 255.0, color.g / 255.0, color.b / 255.0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, n);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void IObject::set_color(Color color) {
	this->color.r = color.r;
	this->color.g = color.g;
	this->color.b = color.b;
	this->color.a = color.a;
}


Line::Line() {
	Point ver[2] = { { 0 } };
	set_vertices(ver);
	set_color({ 0 });
}

Line::Line(Point vertices[2]) {
	set_vertices(vertices);
	set_color({ 0 });
}

void Line::draw() { draw_obj(vertices, 2, color); }

void Line::set_vertices(Point vertices[2]) {
	for (int i = 0; i < 2; i++) {
		this->vertices[i].x = vertices[i].x;
		this->vertices[i].y = vertices[i].y;
		this->vertices[i].z = vertices[i].z;
	}
}

Point *Line::get_vertices() { return vertices; }

Color Line::get_color() { return color; }


Triangle::Triangle() {
	Point ver[3] = { { 0 } };
	set_vertices(ver);
	set_color({ 0 });
}

Triangle::Triangle(Point vertices[3]) {
	set_vertices(vertices);
	set_color({ 0 });
}

void Triangle::draw() { draw_obj(vertices, 3, color); }

void Triangle::set_vertices(Point vertices[3]) {
	for (int i = 0; i < 3; i++) {
		this->vertices[i].x = vertices[i].x;
		this->vertices[i].y = vertices[i].y;
		this->vertices[i].z = vertices[i].z;
	}
}

Point *Triangle::get_vertices() { return vertices; }

Color Triangle::get_color() { return color; }


Rectangle::Rectangle() {
    Point ver[4] = {{0}};
    set_vertices(ver);
    set_color({0});
}

Rectangle::Rectangle(Size size) {
    Point ver[4] = {
        {0, 0, 0}, {size.x, 0, 0}, {size.x, size.y, 0}, {0, size.y, 0}};
    set_vertices(ver);
    set_color({0});
}

void Rectangle::draw() { draw_obj(vertices, 4, color); }

void Rectangle::set_size(Size size) {
    Point ver[4] = {
        {0, 0, 0}, {size.x, 0, 0}, {size.x, size.y, 0}, {0, size.y, 0}};
    set_vertices(ver);
}

void Rectangle::set_vertices(Point vertices[4]) {
    for (int i = 0; i < 4; i++) {
        this->vertices[i].x = vertices[i].x;
        this->vertices[i].y = vertices[i].y;
        this->vertices[i].z = vertices[i].z;
    }
}

Point *Rectangle::get_vertices() { return vertices; }

Color Rectangle::get_color() { return color; }


Square::Square() {
	Point ver[4] = { { 0 } };
	set_vertices(ver);
	set_color({ 0 });
}

Square::Square(Point vertices[4]) {
	set_vertices(vertices);
	set_color({ 0 });
}

void Square::draw() { draw_obj(vertices, 4, color); }

void Square::set_vertices(Point vertices[4]) {
	for (int i = 0; i < 4; i++) {
		this->vertices[i].x = vertices[i].x;
		this->vertices[i].y = vertices[i].y;
		this->vertices[i].z = vertices[i].z;
	}
}

Point *Square::get_vertices() { return vertices; }

Color Square::get_color() { return color; }
