#pragma once
#ifndef POLYCUBES_CUBESPACE_HPP
#define POLYCUBES_CUBESPACE_HPP

#ifndef POLYCUBES_SAFTEY_TESTS
#define POLYCUBES_SAFTEY_TESTS 0 
#endif // POLYCUBES_SAFTEY_TESTS

#include "Coord.hpp"
#include "PolyCube.hpp"

#if defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1
#include <cassert>
#endif // defined(POLYCUBES_SAFTEY_TESTS) && POLYCUBES_SAFTEY_TESTS == 1

#include <bitset>
using namespace std;

class CubeSpace
{

    public:
        constexpr static size_t kMaxDimSize = 32;
        constexpr static size_t kBitCount = kMaxDimSize * kMaxDimSize * kMaxDimSize;
    
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
            size_t pos = coord_to_pos(coord);
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
            size_t pos = coord_to_pos(coord);
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
            for (size_t i = 0; i < kBitCount; i++)
            {
                if (bits.test(i))
                {
                    list.push_back(pos_to_coord(i));
                }
            }
        }


    private:
        bitset<kBitCount> bits;
    
        static size_t coord_to_pos(const Coord &coord)
        {
            size_t x = intToSizet(coord.getX());
            size_t y = intToSizet(coord.getY()) * kMaxDimSize;
            size_t z = intToSizet(coord.getZ()) * kMaxDimSize * kMaxDimSize;
            return x + y + z;
        }
    
        static Coord pos_to_coord(size_t pos)
        {
            size_t left = pos;
            constexpr size_t kZDivider = (kMaxDimSize * kMaxDimSize);
            constexpr size_t kYDivider = (kMaxDimSize);
            constexpr size_t kXDivider = 1;
    
            size_t z = left / kZDivider;
            left -= (kZDivider * z);
            size_t y = left / kYDivider;
            left -= (kYDivider * y);
            size_t x = left / kXDivider;
            return Coord(
                x - (kMaxDimSize / 2),
                y - (kMaxDimSize / 2),
                z - (kMaxDimSize / 2)
            );
        }
    
        static size_t intToSizet(int8_t value)
        {
            return ((int16_t)value + (kMaxDimSize / 2));
        }
    

};

#endif // POLYCUBES_CUBESPACE_HPP
