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

#include <cstdio>

#include "Chunk.hpp"

using namespace voxen;

template<std::uint64_t width, std::uint64_t height, std::uint64_t depth, typename T>
Chunk<width, height, depth, T>::Chunk(std::vector<PositionedLocalVoxel<T>> voxels) {
    m_chunk.fill(0);
    for (PositionedLocalVoxel<T> voxel : voxels) {
        if (voxel.x + width * (voxel.y + voxel.z * height) > width * height * depth - 1) {
            std::printf("Chunk does not allow for a block at position : %llu, %llu, %llu\n", voxel.x, voxel.y, voxel.z);
            continue;
        }
        m_chunk[voxel.x + width * (voxel.y + height * voxel.z)] = voxel.value;
    }
}

template<std::uint64_t width, std::uint64_t height, std::uint64_t depth, typename T>
Chunk<width, height, depth, T>::~Chunk() {

}

template<std::uint64_t width, std::uint64_t height, std::uint64_t depth, typename T>
void Chunk<width, height, depth, T>::SetGlobalPosition(std::uint64_t x, std::uint64_t y) {
    m_global_x = x;
    m_global_y = y;
}
