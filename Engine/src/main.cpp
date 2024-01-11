#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    GLFWwindow* window;

    if (!glfwInit())
        std::runtime_error("Can't init GLFW!\n");

    if (glewInit() != GLEW_OK)
        std::runtime_error("Can't init GLEW!\n");

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::runtime_error("Can't created window!\n");
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // code

        glBegin(GL_TRIANGLES);

        glVertex3f(0, 0.5, 0);      glColor3f(1, 0, 0);
        glVertex3f(0.5, -0.5, 0);   glColor3f(0, 1, 0);
        glVertex3f(-0.5, -0.5, 0);  glColor3f(0, 0, 1);

        glEnd();

        // end code

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}