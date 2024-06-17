#include "Engine/Engine.hpp"

namespace Time {
    namespace {
        double _time;
        double _deltaTime;
    } // namespace

    double time() {
        return _time;
    }

    double deltaTime() {
        return _deltaTime;
    }

    void update() {
        std::chrono::duration<double> t = std::chrono::system_clock::now().time_since_epoch();
        _deltaTime = t.count() - _time;
        _time = t.count();
    }
} // namespace Time

int main() {
    if (!glfwInit()) {
        std::cout << "Couldn't init GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(Window::get_size().x, Window::get_size().y, Window::get_title().c_str(), NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cout << "Couldn't created window!" << std::endl;
        return -2;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        std::cout << "Couldn't load GLAD!" << std::endl;
        return -3;
    }

#ifdef DEBUG
    std::cout << "GLFW " << glfwGetVersionString() << std::endl;
    std::cout << "OpenGL " << (const char *)glGetString(GL_VERSION) << std::endl;
    std::cout << "GPU " << (const char *)glGetString(GL_RENDERER) << std::endl;
#endif // NDEBUG

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    glViewport(0, 0, Window::get_size().x, Window::get_size().y);
    glScalef(Window::get_size().y / Window::get_size().x, 1, 1);

    scripts::start();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(Window::get_background_color().r / 255.0, Window::get_background_color().g / 255.0, Window::get_background_color().b / 255.0, Window::get_background_color().a);

        Time::update();
        Window::set_FPS(1 / Time::deltaTime());

        scripts::update();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
