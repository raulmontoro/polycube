#pragma once
#ifndef POLYCUBES_CUBE_HPP
#define POLYCUBES_CUBE_HPP
#include <vector>
#include "Coord.hpp"

namespace CubeSet
{
    using CubeList = std::vector<Coord>;

    struct center_info
    {
        Coord center;
        Coord min;
        Coord max;

        center_info(Coord center, Coord min, Coord max) : center(center), min(min), max(max)
        {
        }
    };

    center_info compute_center(const CubeList &coords);

    void sort(CubeList &cubes, const Coord &center);

    void translate(CubeList &cubes, const Coord &center);

    std::size_t compute_hash(const CubeList &cubes);

    namespace helpers {
        enum class Axis : uint8_t {
            Y = 1,
            X = 2,
            Z = 4
        };

        void mirror(CubeList& cubes, Axis mirrorAxis, Coord center = Coord(0, 0, 0));
    }

} // namespace CubeSet

#endif // POLYCUBES_CUBE_HPP
