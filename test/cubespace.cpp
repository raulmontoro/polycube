#include <gtest/gtest.h>
#include <iostream>
#include "HashedList.hpp"
#include "PolyCube.hpp"

#include "CubeSpace.hpp"

constexpr std::size_t kBitCountDivision = 64;

bool is_in_set(PolyCube::PointList map, Coord value)
{
    return std::find(map.begin(), map.end(), value) != map.end();
}

Coord TranslateFromUnsigned(std::size_t x, std::size_t y, std::size_t z, std::size_t dimensionSize)
{
    return Coord(
            x - (dimensionSize / 2),
            y - (dimensionSize / 2),
            z - (dimensionSize / 2)
    );
}

Coord SelectPoint(std::size_t index, std::size_t dimensionSize)
{
    std::size_t overflow = dimensionSize;
    std::size_t left = index;
    std::size_t kZDivider = (overflow * overflow);
    std::size_t kYDivider = (overflow);
    std::size_t kXDivider = 1;

    std::size_t z = left / kZDivider;
    left -= (kZDivider * z);
    std::size_t y = left / kYDivider;
    left -= (kYDivider * y);
    std::size_t x = left / kXDivider;
    return TranslateFromUnsigned(x, y, z, dimensionSize);
}


TEST(CubeSpace, TestAllPointsManually)
{
    for (size_t i = 0; i < CubeSpace::kBitCount; i += (CubeSpace::kBitCount / kBitCountDivision))
    {
        CubeSpace space;
        PolyCube::PointList map;

        // Generate list of points and set them.
        for (std::size_t k = 0; k < i; k++)
        {
            Coord local = SelectPoint(k, CubeSpace::kMaxDimSize);
            map.push_back(local);
            space.set(local);
        }

        // Iterate through all points and check them one by one
        for (std::size_t x = 0; x < CubeSpace::kMaxDimSize; x++)
        {
            for (std::size_t y = 0; x < CubeSpace::kMaxDimSize; x++)
            {
                for (std::size_t z = 0; x < CubeSpace::kMaxDimSize; x++)
                {
                    Coord testPoint = TranslateFromUnsigned(x, y, z, CubeSpace::kMaxDimSize);
                    EXPECT_EQ(is_in_set(map, testPoint), space.is_set(testPoint)) << 
                        "Test point of (" << std::to_string(testPoint.getX()) << "," << std::to_string(testPoint.getY()) << ","<< std::to_string(testPoint.getZ()) << ") in a list of " << i << " failed.\n";
                }
            }
        }
    }
}


TEST(CubeSpace, TestAllPointsVectorGeneration)
{
    for (size_t i = 1; i < CubeSpace::kBitCount; i += (CubeSpace::kBitCount / kBitCountDivision))
    {
        CubeSpace space;
        PolyCube::PointList map;

        // Generate list of points and set them.
        for (std::size_t k = 0; k < i; k++)
        {
            Coord local = SelectPoint(k, CubeSpace::kMaxDimSize);
            map.push_back(local);
            space.set(local);
        }
        PolyCube::sort(map, PolyCube::compute_center(map).center);

        PolyCube::PointList generated;

        space.to_point_list(generated);

        PolyCube::sort(generated, PolyCube::compute_center(generated).center);

        EXPECT_EQ(generated, map);
    }
}

TEST(CubeSpace, TestConstructionFromPointList)
{
    for (size_t i = 1; i < CubeSpace::kBitCount; i += (CubeSpace::kBitCount / kBitCountDivision))
    {
        PolyCube::PointList map;

        // Generate list of points and set them.
        for (std::size_t k = 0; k < i; k++)
        {
            Coord local = SelectPoint(k, CubeSpace::kMaxDimSize);
            map.push_back(local);
        }
        CubeSpace space(map);
        PolyCube::PointList generated;
        space.to_point_list(generated);
        PolyCube::sort(map, PolyCube::compute_center(map).center);
        PolyCube::sort(generated, PolyCube::compute_center(generated).center);

        EXPECT_EQ(generated, map);
    }
}
