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
