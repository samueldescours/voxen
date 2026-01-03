/*
 * Copyright (C) 2026 Samuel DESCOURS
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This file is part of: https://github.com/samueldescours/voxen
 */

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
    GLFWwindow *m_window = nullptr;
    inline static bool s_glew_initialized = false;
    inline static bool s_glfw_initialized = false;
    inline static unsigned int s_living_windows = 0;
};

}
