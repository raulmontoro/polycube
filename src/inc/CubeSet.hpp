#pragma once
#ifndef POLYCUBE_CUBESET_HPP
#define POLYCUBE_CUBESET_HPP

#include "HashedList.hpp"
#include "PolyCube.hpp"
#include <vector>

class SubCubeSet
{
    private:
        HashedList<PolyCube::PointList> cubesets;
    
    public:
        Coord furthest;
        Coord center;
    
        SubCubeSet(Coord center, Coord furthest) : center(center), furthest(furthest)
        {
        }
    
    
        
        /*  pre:
            post:
        */
        void add_cube(const PolyCube::PointList &cube);
    
        /*  pre:
            post:   return
                    cube present
                        true
                        false
        */
        bool contains_cube(const PolyCube::PointList &cube) const;
        
        /*  pre:
            post:
        */
        std::size_t compute_hash() const
        {
            return std::hash<Coord>()(center, furthest);
        };
};
    
    
    
    
    
    
    
    
    
class CubeSet
{
private:
    HashedList<SubCubeSet> map;

public:
    CubeSet()
    {
    }

    void add_cube(const PolyCube::PointList &cube, Coord center, Coord furthest);

    bool contains_cube(const PolyCube::PointList &cube, Coord center, Coord furthest) const;
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
