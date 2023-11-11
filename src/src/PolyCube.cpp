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

    center_info compute_center(const PolyCube::PointList &coords)
    {
        int16_t total_x = 0;
        int16_t total_y = 0;
        int16_t total_z = 0;
        int8_t min_x = INT8_MAX;
        int8_t min_y = INT8_MAX;
        int8_t min_z = INT8_MAX;

        int8_t max_x = INT8_MIN;
        int8_t max_y = INT8_MIN;
        int8_t max_z = INT8_MIN;

        for (const auto &val : coords)
        {
            total_x += val.x;
            total_y += val.y;
            total_z += val.z;
            min_x = std::min(min_x, val.x);
            min_y = std::min(min_y, val.y);
            min_z = std::min(min_z, val.z);
            max_x = std::max(max_x, val.x);
            max_y = std::max(max_y, val.y);
            max_z = std::max(max_z, val.z);
        }
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

    void rotate_up(PolyCube::PointList &set, const Coord &center)
    {
    }

    namespace helpers
    {
        void mirror(PointList &cubes, Axis mirrorAxis, Coord center)
        {
            for (auto &cube : cubes)
            {
                if (((int)mirrorAxis & (int)Axis::X) == (int)Axis::X)
                {
                    cube.x = cube.x - ((cube.x - center.x) * 2);
                }
                if (((int)mirrorAxis & (int)Axis::Y) == (int)Axis::Y)
                {
                    cube.y = cube.y - ((cube.y - center.y) * 2);
                }
                if (((int)mirrorAxis & (int)Axis::Z) == (int)Axis::Z)
                {
                    cube.z = cube.z - ((cube.z - center.z) * 2);
                }
            }
        }
    } // namespace helpers
} // namespace PolyCube