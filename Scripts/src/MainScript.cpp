#include <Scripts/MainScript.hpp>

namespace scripts {
	void MainScript::Start() {
		Engine::Window window;

		window.set_size(500, 500);
		window.set_title("shiiiiii");
	}

	void MainScript::Update() {
		glBegin(GL_TRIANGLE_FAN);

		glVertex3f(-0.5, 0.5, 0);	glColor3f(1, 0, 0);
		glVertex3f(0.5, 0.5, 0);	glColor3f(0, 1, 0);
		glVertex3f(0.5, -0.5, 0);	glColor3f(0, 0, 1);
		glVertex3f(-0.5, -0.5, 0);  glColor3f(1, 1, 1);

		glEnd();
	}
}