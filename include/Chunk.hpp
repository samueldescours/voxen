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
#include <vector>

namespace voxen {

template <typename T>
struct PositionedLocalVoxel {
    std::uint64_t x;
    std::uint64_t y;
    std::uint64_t z;
    T value;
};

/// Make sure the block type is an integer and 0 is reserved for air
template<std::uint64_t width, std::uint64_t height, std::uint64_t depth, typename T>
class Chunk {
public:
    Chunk(std::vector<PositionedLocalVoxel<T>> voxels);
    ~Chunk();
    
    /// /!\ WARNING : Sets the postion of the corner away from the center of the
    /// block at local coordinates 0, 0, 0
    void SetGlobalPosition(std::uint64_t x, std::uint64_t y, std::uint64_t z);
    /// /!\ WARNING : NOT IMPLEMENTED
    void Draw();
    void AddVoxel(PositionedLocalVoxel<T> voxel);
    void RemoveVoxelAt(std::uint64_t x, std::uint64_t y, std::uint64_t z);
public:
private:
private:
    std::array<T, width * height * depth> m_chunk;
    std::uint64_t m_global_x = 0;
    std::uint64_t m_global_y = 0;
    std::uint64_t m_global_z = 0;
};

}
