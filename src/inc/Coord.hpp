#pragma once
#ifndef POLYCUBES_COORD_HPP
#define POLYCUBES_COORD_HPP
#include <cstdint>
#include <cmath>
#include <functional>

#ifndef POLYCUBES_COORD_ENABLE_MULTI_HASH
#define POLYCUBES_COORD_ENABLE_MULTI_HASH 1
#endif // POLYCUBES_COORD_ENABLE_MULTI_HASH

struct Coord
{
private:
    int8_t x;
    int8_t y;
    int8_t z;

public:
    constexpr Coord(int8_t x, int8_t y, int8_t z) : x(x), y(y), z(z)
    {
    }

    // https://stackoverflow.com/questions/55051882/use-a-uint32-t-to-store-four-separate-uint8-t-values
    // https://stackoverflow.com/questions/3117822/generate-uint64-t-hash-key-with-several-uint32-t-integers
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

    bool operator==(const Coord &a) const
    {
        return (a.x == x) && (a.y == y) && (a.z == z);
    }

    bool operator!=(const Coord &a) const
    {
        return !(a == *this);
    }

    Coord &operator-=(const Coord &a)
    {
        x -= a.x;
        y -= a.y;
        z -= a.z;
        return *this;
    }
    Coord &operator+=(const Coord &a)
    {
        x += a.x;
        y += a.y;
        z += a.z;
        return *this;
    }

    Coord operator-(const Coord &a)
    {
        return Coord(x - a.x, y - a.y, z - a.z);
    };

    Coord operator+(const Coord &a)
    {
        return Coord(x + a.x, y + a.y, z + a.z);
    };

    inline int8_t getX() const
    {
        return x;
    }

    inline int8_t getY() const
    {
        return y;
    }

    inline int8_t getZ() const
    {
        return z;
    }

    inline void setX(int8_t value)
    {
        this->x = value;
    }
    inline void setY(int8_t value)
    {
        this->y = value;
    }
    inline void setZ(int8_t value)
    {
        this->z = value;
    }
};

template <>
struct std::hash<Coord>
{
    std::size_t operator()(const Coord &coord) const
    {
        return coord.compute_hash();
    };

#if defined(POLYCUBES_COORD_ENABLE_MULTI_HASH) && POLYCUBES_COORD_ENABLE_MULTI_HASH == 1
    std::size_t operator()(const Coord &a, const Coord &b) const
    {
        static_assert(sizeof(std::size_t) >= (sizeof(uint32_t) * 2));

        uint32_t hash_a = a.compute_hash();
        uint32_t hash_b = b.compute_hash();
        if (hash_a > hash_b)
        {
            std::swap(hash_a, hash_b);
        }
        return (hash_a) | ((std::size_t)hash_b << 32);
    }
#endif // defined(POLYCUBES_COORD_ENABLE_MULTI_HASH) && POLYCUBES_COORD_ENABLE_MULTI_HASH == 1
};

#endif // POLYCUBES_COORD_HPP
