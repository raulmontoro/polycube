#include "PolyCube.hpp"

#include <tuple>
#include <algorithm>

#include "Helpers.hpp"
namespace PolyCube
{
    std::size_t compute_hash(const PolyCube::PointList &cubes)
    {
        if (cubes.size() == 0)
        {
            return 0;
        }
        std::size_t hash = cubes[0].compute_hash();
        for (auto it = std::next(cubes.begin()); it != cubes.cend(); it++)
        {
            hash = ::helpers::add_to_hash(hash, it->compute_hash());
        }
        return hash;
    }

    center_info compute_center(const PolyCube::PointList &coords) {
        int16_t total_x = 0;
        int16_t total_y = 0;
        int16_t total_z = 0;
        
        int8_t min_x = INT8_MAX;
        int8_t min_y = INT8_MAX;
        int8_t min_z = INT8_MAX;

        int8_t max_x = INT8_MIN;
        int8_t max_y = INT8_MIN;
        int8_t max_z = INT8_MIN;

        for (const auto &val : coords) {
            total_x += val.getX();
            total_y += val.getY();
            total_z += val.getZ();
            
            min_x = std::min(min_x, val.getX());
            min_y = std::min(min_y, val.getY());
            min_z = std::min(min_z, val.getZ());
            
            max_x = std::max(max_x, val.getX());
            max_y = std::max(max_y, val.getY());
            max_z = std::max(max_z, val.getZ());
        }
        
        // number of cubes in a polycubes
        size_t total = coords.size();
        
        total_x = ::helpers::idiv_roundup(total_x, total);
        total_y = ::helpers::idiv_roundup(total_y, total);
        total_z = ::helpers::idiv_roundup(total_z, total);
        
        Coord center(total_x, total_y, total_z);
        
        Coord min(min_x, min_y, min_z);
        Coord max(max_x, max_y, max_z);
        
        return center_info(center, min, max);
    }

    void sort(PolyCube::PointList &cubes, const Coord &center)
    {
        std::sort(
            cubes.begin(),
            cubes.end(),
            [&center](const Coord &a, const Coord &b)
            {
                return a.distance_to(center) < b.distance_to(center);
            });
    }

    void translate(PointList &cubes, const Coord &center)
    {
        for (auto &val : cubes)
        {
            val = val + center;
        }
    }

    center_info process_cube(PointList &cube)
    {
        center_info center = compute_center(cube);
        sort(cube, center.center);
        translate(cube, center.center);
        return center;
    }

    void rotate_up(PolyCube::PointList &set, const Coord &center)
    {
    }

    bool point_in_list(const PointList& cube, const Coord& point)
    {
        for (const auto& cube_point : cube)
        {
            if (cube_point == point) {
                return true;
            }
        }
        return false;
    }

    namespace helpers
    {
        void mirror(PointList &cubes, Axis mirrorAxis, Coord center)
        {
            for (auto &cube : cubes)
            {
                if (((int)mirrorAxis & (int)Axis::X) == (int)Axis::X)
                {
                    cube.setX(cube.getX() - ((cube.getX() - center.getX()) * 2));
                }
                if (((int)mirrorAxis & (int)Axis::Y) == (int)Axis::Y)
                {
                    cube.setY(cube.getY() - ((cube.getY() - center.getY()) * 2));
                }
                if (((int)mirrorAxis & (int)Axis::Z) == (int)Axis::Z)
                {
                    cube.setZ(cube.getZ() - ((cube.getZ() - center.getZ()) * 2));
                }
            }
        }
    } // namespace helpers
} // namespace PolyCube
