#include <gtest/gtest.h>

#include <chrono>
#include "PolyCube.hpp"

using PolyCube::helpers::Axis;

TEST(PolyCube_Mirror, SingleCubeOnOriginAxisX)
{
    PolyCube::PointList cubes{{1,1,1}};

    PolyCube::helpers::mirror(cubes, Axis::X, Coord(0, 0, 0));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(-1, 1, 1), cubes[0]);
}

TEST(PolyCube_Mirror, SingleCubeOnOriginAxisY)
{
    PolyCube::PointList cubes{{1,1,1}};

    PolyCube::helpers::mirror(cubes, Axis::Y, Coord(0, 0, 0));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, -1, 1), cubes[0]);
}

TEST(PolyCube_Mirror, SingleCubeOnOriginAxisZ)
{
    PolyCube::PointList cubes{{1,1,1}};

    PolyCube::helpers::mirror(cubes, Axis::Z, Coord(0, 0, 0));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, 1, -1), cubes[0]);
}

TEST(PolyCube_Mirror, SingleCubeOffsetOriginAxisX)
{
    PolyCube::PointList cubes{{1,1,1}};

    PolyCube::helpers::mirror(cubes, Axis::X, Coord(5, 10, -5));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(9, 1, 1), cubes[0]);
}

TEST(PolyCube_Mirror, SingleCubeOffsetOriginAxisY)
{
    PolyCube::PointList cubes{{1,1,1}};

    PolyCube::helpers::mirror(cubes, Axis::Y, Coord(5, 10, -5));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, 19, 1), cubes[0]);
}

TEST(PolyCube_Mirror, SingleCubeOffsetOriginAxisZ)
{
    PolyCube::PointList cubes{{1,1,1}};

    PolyCube::helpers::mirror(cubes, Axis::Z, Coord(5, 10, -5));

    EXPECT_EQ(1, cubes.size());
    EXPECT_EQ(Coord(1, 1, -11), cubes[0]);
}

TEST(PolyCube_Mirror, MultiCube_MultiAxis)
{
    PolyCube::PointList cubes{{1,1,1}, {5,-5,10}, {8, 110, -120}};
    PolyCube::helpers::mirror(cubes, (Axis)((int)Axis::Z | (int)Axis::X), Coord(10, 30, -10));

    EXPECT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(19, 1, -21), cubes[0]);
    EXPECT_EQ(Coord(15, -5, -30), cubes[1]);
    EXPECT_EQ(Coord(12, 110, 100), cubes[2]);
}