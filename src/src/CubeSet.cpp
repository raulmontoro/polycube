#include "CubeSet.hpp"

#include "PolyCube.hpp"

bool CubeSet::contains_cube(const PolyCube::PointList &cube, Coord center, Coord furthest) const
{
    std::hash<Coord> hasher;
    std::size_t hash = hasher(center, furthest);
    auto it = this->map.find_by_hash(hash);
    if (it != this->map.end())
    {
        return it->second.contains_cube(cube);
    }
    return false;
}

bool SubCubeSet::contains_cube(const PolyCube::PointList &cube) const
{
    return (cubesets.find(cube) != cubesets.end());
}

void CubeSet::add_cube(const PolyCube::PointList &cube, Coord center, Coord furthest)
{
    std::hash<Coord> hasher;
    auto it = this->map.find_by_hash(hasher(center, furthest));
    if (it != this->map.end())
    {
        it->second.add_cube(cube);
    }
    else
    {
        SubCubeSet subset(center, furthest);
        subset.add_cube(cube);
        this->map.add(subset);
    }
}

void SubCubeSet::add_cube(const PolyCube::PointList &cube)
{
    if (contains_cube(cube))
    {
        return;
    }
    cubesets.add(cube);
}
