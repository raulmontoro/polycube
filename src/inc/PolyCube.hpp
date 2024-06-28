#pragma once
#ifndef POLYCUBES_POLYCUBE_HPP
#define POLYCUBES_POLYCUBE_HPP

#include "Coord.hpp"
#include "Helpers.hpp"

#include <vector>
#include <functional>




namespace PolyCube {

    /*  polycube    */

    using PointList = std::vector<Coord>;


    /*  center  */


    struct center_info {
        Coord center;
        Coord min;
        Coord max;

        center_info(Coord center, Coord min, Coord max) : center(center), min(min), max(max) {
        }
    };

    center_info compute_center(const PointList &coords);

    void sort(PointList &cubes, const Coord &center);

    void translate(PointList &cubes, const Coord &center);






    std::size_t compute_hash(const PointList &cubes);

    center_info process_cube(PointList &cube);





    /*  cube in polycube    */

    bool point_in_list(const PointList& cube, const Coord& point);




    namespace helpers {

        enum class Axis : uint8_t {
            Y = 1,
            X = 2,
            Z = 4
        };

        void mirror(PointList &cubes, Axis mirrorAxis, Coord center = Coord(0, 0, 0));
    }
} // namespace PolyCube




template <>
struct std::hash<PolyCube::PointList> {
    std::size_t operator()(const PolyCube::PointList &other) const {
        return PolyCube::compute_hash(other);
    }
};

#endif // POLYCUBES_POLYCUBE_HPP
