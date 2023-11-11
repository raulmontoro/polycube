#include <gtest/gtest.h>
#include "PolyCube.hpp"

TEST(PolyCube_Sort, SortSingleCube)
{
    PolyCube::PointList cubes{{8, 8, 8}};

    PolyCube::sort(cubes, Coord(0, 0, 0)); // Sort compared to origin

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(8, 8, 8), cubes.at(0));
}

TEST(PolyCube_Sort, SortMultiCubeSimpleLineToOrigin)
{
    PolyCube::PointList cubes{{8, 8, 8}, {9, 8, 8}, {10, 8, 8}};

    PolyCube::sort(cubes, Coord(0, 0, 0));

    EXPECT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(8, 8, 8), cubes.at(0));
    EXPECT_EQ(Coord(9, 8, 8), cubes.at(1));
    EXPECT_EQ(Coord(10, 8, 8), cubes.at(2));
}

TEST(PolyCube_Sort, SortMultiCubeSimpleLineToCenter)
{
    PolyCube::PointList cubes{{8, 8, 8}, {9, 8, 8}, {10, 8, 8}};

    PolyCube::sort(cubes, Coord(9, 8, 8));

    EXPECT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(9, 8, 8), cubes.at(0));
    EXPECT_EQ(Coord(8, 8, 8), cubes.at(1));
    EXPECT_EQ(Coord(10, 8, 8), cubes.at(2));
}

TEST(PolyCube_Sort, SortMultiCubeSimpleLineWithSeparateLooseCubeToOffset)
{
    PolyCube::PointList cubes{{-30, 8, 0}, {9, 8, 8}, {10, 8, 8}, {8, 8, 8}};

    PolyCube::sort(cubes, Coord(-8, 8, 10));

    EXPECT_EQ(4, cubes.size());
    EXPECT_EQ(Coord(8, 8, 8), cubes.at(0));
    EXPECT_EQ(Coord(9, 8, 8), cubes.at(1));
    EXPECT_EQ(Coord(10, 8, 8), cubes.at(2));
    EXPECT_EQ(Coord(-30, 8, 0), cubes.at(3));
}
