#pragma once
#ifndef POLYCUBE_CUBESET_HPP
#define POLYCUBE_CUBESET_HPP

#include <vector>
#include "HashedList.hpp"
#include "PolyCube.hpp"

class SubCubeSet
{
public:
    Coord furthest;
    Coord center;

private:
    HashedList<PolyCube::PointList> cubesets;

public:
    SubCubeSet(Coord center, Coord furthest) : center(center), furthest(furthest)
    {
    }

    bool contains_cube(const PolyCube::PointList &cube) const;
    void add_cube(const PolyCube::PointList &cube);

    std::size_t compute_hash() const
    {
        return std::hash<Coord>()(center, furthest);
    };

private:
};

class CubeSet
{
private:
    HashedList<SubCubeSet> map;

public:
    CubeSet()
    {
    }

    bool contains_cube(const PolyCube::PointList &cube, Coord center, Coord furthest) const;
    void add_cube(const PolyCube::PointList &cube, Coord center, Coord furthest);
};

template <>
struct std::hash<SubCubeSet>
{
    std::size_t operator()(const SubCubeSet &obj) const
    {
        return obj.compute_hash();
    }
};

#endif // POLYCUBE_CUBESET_HPP
