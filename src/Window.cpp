#include "Window.hpp"

#include <GL/gl.h>
#include <GLFW/glfw3.h>

using namespace voxen;

Window::Window() {
    if (!glfw_initialized)
        if (!glfwInit())
            return;
    glfw_initialized = true;
    window = glfwCreateWindow(250, 250, "", nullptr, nullptr);
    if (!window)
        return;
    valid = true;
    living_windows++;
    glfwMakeContextCurrent(window);
    if (!glew_initialized) {
        glewInit();
        glew_initialized = true;
    }
}

Window::Window(unsigned int width, unsigned int height, char const *title) {
    if (!glfw_initialized)
        if (!glfwInit())
            return;
    glfw_initialized = true;
    living_windows++;
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window)
        valid = true;
    glfwMakeContextCurrent(window);
    if (!glew_initialized) {
        glewInit();
        glew_initialized = true;
    }
}

Window::~Window() {
    if (valid)
        living_windows--;
    if (!living_windows) {
        glfwTerminate();
        glfw_initialized = false;
    }
    if (window)
        glfwDestroyWindow(window);
}

void Window::Update() {
    glfwPollEvents();
    std::array<float, 4> cc = clear_color.GetFloating();
    glClearColor(cc[0], cc[1], cc[2], cc[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
    should_close = glfwWindowShouldClose(window);
}

void Window::MakeCurrent() {
    glfwMakeContextCurrent(window);
}
