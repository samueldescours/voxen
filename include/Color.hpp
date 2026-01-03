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

#include <array>
#include <cstdint>

namespace voxen {

    class Color {
    public:
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
        
        std::array<float, 4> GetFloating();
        std::array<uint8_t, 4>GetInt();
    private:
        std::uint8_t m_r = 0;
        std::uint8_t m_g = 0;
        std::uint8_t m_b = 0;
        std::uint8_t m_a = 255;
    };

}
