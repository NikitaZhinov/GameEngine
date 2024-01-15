#include <Scripts/MainScript.hpp>

namespace scripts {
	void MainScript::Start() {
		
	}

	void MainScript::Update() {
		glBegin(GL_TRIANGLES);

		glVertex3f(0, 0.5, 0);      glColor3f(1, 0, 0);
		glVertex3f(0.5, -0.5, 0);   glColor3f(0, 1, 0);
		glVertex3f(-0.5, -0.5, 0);  glColor3f(0, 0, 1);

		glEnd();
	}
}