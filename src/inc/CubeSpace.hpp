#pragma once
#ifndef POLYCUBES_CUBESPACE_HPP
#define POLYCUBES_CUBESPACE_HPP

#ifndef POLYCUBES_SAFTEY_TESTS
#define POLYCUBES_SAFTEY_TESTS 0 
#endif // POLYCUBES_SAFTEY_TESTS

#include <bitset>
#include "PolyCube.hpp"

#if defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1
#include <cassert>
#endif // defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1

#include "Coord.hpp"

class CubeSpace
{
public:
    constexpr static std::size_t kMaxDimSize = 32;
    constexpr static std::size_t kBitCount = kMaxDimSize * kMaxDimSize * kMaxDimSize;

private:
    std::bitset<kBitCount> bits;

public:
    CubeSpace()
    {
        reset();
    }

    explicit CubeSpace(const PolyCube::PointList& points)
    {
        for (auto& point : points)
        {
            set(point);
        }
    }

    void reset()
    {
        bits.reset();
    }

    bool is_set(const Coord &coord) const
    {
        std::size_t pos = coord_to_pos(coord);
        #if defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1
        if (pos >= kBitCount)
        {
            assert(pos < kBitCount);
            return false;
        }
        #endif // defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1
        return bits.test(pos);
    }

    void set(const Coord &coord)
    {
        std::size_t pos = coord_to_pos(coord);
        #if defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1
        if (pos >= kBitCount)
        {
            assert(pos < kBitCount);
            return;
        }
        #endif // defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1
        bits.set(pos);
    }

    void to_point_list(PolyCube::PointList& list) const
    {
        for (std::size_t i = 0; i < kBitCount; i++)
        {
            if (bits.test(i))
            {
                list.push_back(pos_to_coord(i));
            }
        }
    }

private:
    static std::size_t coord_to_pos(const Coord &coord)
    {
        std::size_t x = intToSizet(coord.getX());
        std::size_t y = intToSizet(coord.getY()) * kMaxDimSize;
        std::size_t z = intToSizet(coord.getZ()) * kMaxDimSize * kMaxDimSize;
        return x + y + z;
    }

    static Coord pos_to_coord(std::size_t pos)
    {
        std::size_t left = pos;
        constexpr std::size_t kZDivider = (kMaxDimSize * kMaxDimSize);
        constexpr std::size_t kYDivider = (kMaxDimSize);
        constexpr std::size_t kXDivider = 1;

        std::size_t z = left / kZDivider;
        left -= (kZDivider * z);
        std::size_t y = left / kYDivider;
        left -= (kYDivider * y);
        std::size_t x = left / kXDivider;
        return Coord(
            x - (kMaxDimSize / 2),
            y - (kMaxDimSize / 2),
            z - (kMaxDimSize / 2)
        );
    }

    static std::size_t intToSizet(int8_t value)
    {
        return ((int16_t)value + (kMaxDimSize / 2));
    }
};

#endif // POLYCUBES_CUBESPACE_HPP
