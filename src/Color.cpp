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

#include "Color.hpp"
#include <array>

using namespace voxen;

Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
    m_r = r;
    m_g = g;
    m_b = b;
    m_a = a;
}

std::array<std::uint8_t, 4> Color::GetInt() {
    return {m_r, m_g, m_b, m_a};
}

std::array<float, 4> Color::GetFloating() {
    return {(float)m_r / 255.0f, (float)m_g / 255.0f, (float)m_b / 255.0f, (float)m_a / 255.0f};
}
