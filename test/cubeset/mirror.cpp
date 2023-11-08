#include <gtest/gtest.h>

#include <chrono>
#include "CubeSet.hpp"

using CubeSet::helpers::Axis;

TEST(CubeSet_Mirror, SingleCubeOnOriginAxisX)
{
    CubeSet::CubeList cubes{{1,1,1}};

    CubeSet::helpers::mirror(cubes, Axis::X, Coord(0, 0, 0));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(-1, 1, 1), cubes[0]);
}

TEST(CubeSet_Mirror, SingleCubeOnOriginAxisY)
{
    CubeSet::CubeList cubes{{1,1,1}};

    CubeSet::helpers::mirror(cubes, Axis::Y, Coord(0, 0, 0));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, -1, 1), cubes[0]);
}

TEST(CubeSet_Mirror, SingleCubeOnOriginAxisZ)
{
    CubeSet::CubeList cubes{{1,1,1}};

    CubeSet::helpers::mirror(cubes, Axis::Z, Coord(0, 0, 0));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, 1, -1), cubes[0]);
}

TEST(CubeSet_Mirror, SingleCubeOffsetOriginAxisX)
{
    CubeSet::CubeList cubes{{1,1,1}};

    CubeSet::helpers::mirror(cubes, Axis::X, Coord(5, 10, -5));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(9, 1, 1), cubes[0]);
}

TEST(CubeSet_Mirror, SingleCubeOffsetOriginAxisY)
{
    CubeSet::CubeList cubes{{1,1,1}};

    CubeSet::helpers::mirror(cubes, Axis::Y, Coord(5, 10, -5));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, 19, 1), cubes[0]);
}

TEST(CubeSet_Mirror, SingleCubeOffsetOriginAxisZ)
{
    CubeSet::CubeList cubes{{1,1,1}};

    CubeSet::helpers::mirror(cubes, Axis::Z, Coord(5, 10, -5));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, 1, -11), cubes[0]);
}

TEST(CubeSet_Mirror, MultiCube_MultiAxis)
{
    CubeSet::CubeList cubes{{1,1,1}, {5,-5,10}, {8, 110, -120}};
    CubeSet::helpers::mirror(cubes, (Axis)((int)Axis::Z | (int)Axis::X), Coord(10, 30, -10));

    EXPECT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(19, 1, -21), cubes[0]);
    EXPECT_EQ(Coord(15, -5, -30), cubes[1]);
    EXPECT_EQ(Coord(12, 110, 100), cubes[2]);
}