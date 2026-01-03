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

#include "Window.hpp"

#include <GL/gl.h>
#include <GLFW/glfw3.h>

using namespace voxen;

Window::Window() {
    if (!s_glfw_initialized)
        if (!glfwInit())
            return;
    s_glfw_initialized = true;
    m_window = glfwCreateWindow(250, 250, "", nullptr, nullptr);
    if (!m_window)
        return;
    valid = true;
    s_living_windows++;
    glfwMakeContextCurrent(m_window);
    if (!s_glew_initialized) {
        glewInit();
        s_glew_initialized = true;
    }
}

Window::Window(unsigned int width, unsigned int height, char const *title) {
    if (!s_glfw_initialized)
        if (!glfwInit())
            return;
    s_glfw_initialized = true;
    s_living_windows++;
    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (m_window)
        valid = true;
    glfwMakeContextCurrent(m_window);
    if (!s_glew_initialized) {
        glewInit();
        s_glew_initialized = true;
    }
}

Window::~Window() {
    if (valid)
        s_living_windows--;
    if (!s_living_windows) {
        glfwTerminate();
        s_glfw_initialized = false;
    }
    if (m_window)
        glfwDestroyWindow(m_window);
}

void Window::Update() {
    glfwPollEvents();
    std::array<float, 4> cc = clear_color.GetFloating();
    glClearColor(cc[0], cc[1], cc[2], cc[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(m_window);
    should_close = glfwWindowShouldClose(m_window);
}

void Window::MakeCurrent() {
    glfwMakeContextCurrent(m_window);
}
