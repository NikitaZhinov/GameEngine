#include "Engine/Engine.hpp"

int main() {
    GLFWwindow *window;
    Window WindowSettings;
    scripts::MainScript Script;

    Script.Start();

    if (!glfwInit()) {
        std::cout << "Can't init GLFW!" << std::endl;
        return -1;
    }

    Size ws = WindowSettings.get_size();
    window = glfwCreateWindow(ws.x, ws.y, WindowSettings.get_title().c_str(), NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cout << "Can't created window!" << std::endl;
        return -2;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        glfwTerminate();
        std::cout << "Can't load GLAD!" << std::endl;
        return -3;
    }

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GPU " << glGetString(GL_RENDERER) << std::endl;
#endif // NDEBUG

    Color bc = WindowSettings.get_background_color();
    glClearColor(bc.r / 255.0, bc.g / 255.0, bc.b / 255.0, bc.a);

    glScalef(ws.y / ws.x, 1, 1);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        Script.Update();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}