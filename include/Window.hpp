#pragma once

#include "Color.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace voxen {

class Window {
public:
    Window();
    Window(unsigned int width, unsigned int height, char const *title);

    void MakeCurrent();
    void Update();

    ~Window();
public:
    Color clear_color = Color(0, 0, 0);
    bool valid = false;
    bool should_close = false;
private:
private:
    GLFWwindow *window = nullptr;
    inline static bool glew_initialized = false;
    inline static bool glfw_initialized = false;
    inline static unsigned int living_windows = 0;
};

}
