#pragma once
#ifndef POLYCUBES_COORD_HPP
#define POLYCUBES_COORD_HPP
#include <cstdint>
#include <cmath>
#include <functional>
#include <iostream>

struct Coord
{
    int8_t x;
    int8_t y;
    int8_t z;

    constexpr Coord(int8_t x, int8_t y, int8_t z) : x(x), y(y), z(z)
    {
    }

    constexpr uint32_t compute_hash() const
    {
        uint32_t _x = (uint32_t)((int)x + (-INT8_MIN));
        uint32_t _y = (uint32_t)((int)y + (-INT8_MIN));
        uint32_t _z = (uint32_t)((int)z + (-INT8_MIN));
        return _x | (_y << 8) | (_z << 16);
    };

    double distance_to(const Coord &coord) const
    {
        int16_t x2 = coord.x - x;
        int16_t y2 = coord.y - y;
        int16_t z2 = coord.z - z;
        x2 = x2 * x2;
        y2 = y2 * y2;
        z2 = z2 * z2;
        return std::sqrt(x2 + y2 + z2);
    };

    bool operator==(const Coord& a) const
    {
        return (a.x == x) && (a.y == y) && (a.z == z);
    }
    
    bool operator!=(const Coord& a) const 
    {
        return !(a == *this);
    }

    Coord& operator-=(const Coord& a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }
    Coord& operator+=(const Coord& a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }
    
    Coord operator-(const Coord& a)
    {
        return Coord(x - a.x, y - a.y, z - a.z);
    };

    Coord operator+(const Coord& a)
    {
        return Coord(x + a.x, y + a.y, z + a.z);
    };
};

template<>
struct std::hash<Coord>
{
    std::size_t operator()(const Coord& coord) const
    {
        return coord.compute_hash();
    };
};

#endif // POLYCUBES_COORD_HPP
