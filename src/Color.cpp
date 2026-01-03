#include "Color.hpp"
#include <array>

using namespace voxen;

Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
    m_r = r;
    m_g = g;
    m_b = b;
    m_a = a;
}

Color::Color(float r, float g, float b, float a) {
    m_r = (std::uint8_t)(r * 255);
    m_g = (std::uint8_t)(g * 255);
    m_b = (std::uint8_t)(b * 255);
    m_a = (std::uint8_t)(a * 255);
}

std::array<std::uint8_t, 4> Color::GetInt() {
    return {m_r, m_g, m_b, m_a};
}

std::array<float, 4> Color::GetFloating() {
    return {(float)m_r / 255.0f, (float)m_g / 255.0f, (float)m_b / 255.0f, (float)m_a / 255.0f};
}
