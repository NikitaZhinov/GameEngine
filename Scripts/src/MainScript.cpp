#include <MainScript.hpp>

void MainScript::Start() {
	Window window;

	window.set_size(800, 600);
	window.set_title("shiiiiii");
	window.set_background_color(255, 255, 255);
}

void MainScript::Update() {
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(-0.5,  0.5, 0);	glColor3f(1, 0, 0);
	glVertex3f(	0.5,  0.5, 0);	glColor3f(0, 1, 0);
	glVertex3f(	0.5, -0.5, 0);	glColor3f(0, 0, 1);
	glVertex3f(-0.5, -0.5, 0);  glColor3f(1, 1, 1);

	glEnd();
}