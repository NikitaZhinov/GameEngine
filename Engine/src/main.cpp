#include <Engine/Engine.hpp>

int main() {
    GLFWwindow* window;
    Engine::Window WindowSettings;
    scripts::MainScript Script;

    Script.Start();

    if (!glfwInit()) {
        std::cout << "Can't init GLFW!" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(WindowSettings.get_size().x, WindowSettings.get_size().y, WindowSettings.get_title().c_str(), NULL, NULL);
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