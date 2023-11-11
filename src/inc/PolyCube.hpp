#pragma once
#ifndef POLYCUBES_POLYCUBE_HPP
#define POLYCUBES_POLYCUBE_HPP
#include <vector>
#include "Coord.hpp"

namespace PolyCube
{
    using PointList = std::vector<Coord>;

    struct center_info
    {
        Coord center;
        Coord min;
        Coord max;

        center_info(Coord center, Coord min, Coord max) : center(center), min(min), max(max)
        {
        }
    };

    center_info compute_center(const PointList &coords);

    void sort(PointList &cubes, const Coord &center);

    void translate(PointList &cubes, const Coord &center);

    std::size_t compute_hash(const PointList &cubes);

    namespace helpers
    {
        enum class Axis : uint8_t
        {
            Y = 1,
            X = 2,
            Z = 4
        };

        void mirror(PointList &cubes, Axis mirrorAxis, Coord center = Coord(0, 0, 0));
    }
} // namespace PolyCube

#endif // POLYCUBES_POLYCUBE_HPP
