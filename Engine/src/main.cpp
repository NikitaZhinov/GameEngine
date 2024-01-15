#include <Engine/Engine.hpp>

int main() {
    GLFWwindow* window;
    scripts::MainScript Script;

    Script.Start();

    if (!glfwInit()) {
        std::cout << "Can't init GLFW!" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(Script.WIDTH_WINDOW, Script.HEIGHT_WINDOW, Script.TITLE_WINDOW.c_str(), NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cout << "Can't created window!" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cout << "Can't load GLAD!" << std::endl;
        return -1;
    }

#ifndef NDEBUG
    std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GPU " << glGetString(GL_RENDERER) << std::endl;
#endif

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        Script.Update();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}