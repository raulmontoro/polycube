#include <gtest/gtest.h>
#include "PolyCube.hpp"

TEST(PolyCube_ComputeCenter, CenterOfSingleCubeOnOrigin)
{
    PolyCube::PointList cubes{{0, 0, 0}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(0, 0, 0), info.center);
}

TEST(PolyCube_ComputeCenter, CenterOfSingleCubeOffset)
{
    PolyCube::PointList cubes{{3, 5, 7}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(3, 5, 7), info.center);
}

TEST(PolyCube_ComputeCenter, CenterOfMultiCubeOnOrigin)
{
    PolyCube::PointList cubes{{0, 0, 0}, {2, -2, 6}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(1, -1, 3), info.center);
}

TEST(PolyCube_ComputeCenter, CenterOfMultiCubeOffset)
{
    PolyCube::PointList cubes{{3, 5, 7}, {6, 7, 8}, {8, 8, 8}, {10, -40, -30}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(7, -5, -2), info.center);
}

TEST(PolyCube_ComputeCenter, MinOfSingleCube)
{
    PolyCube::PointList cubes{{3, -5, 7}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(3, -5, 7), info.min);
}

TEST(PolyCube_ComputeCenter, MaxOfSingleCube)
{
    PolyCube::PointList cubes{{3, -5, 7}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(3, -5, 7), info.max);
}

TEST(PolyCube_ComputeCenter, MinOfMultiCubeSingleCubeIsMin)
{
    PolyCube::PointList cubes{{3, -5, 7}, {5, 7, 8}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(3, -5, 7), info.min);
}

TEST(PolyCube_ComputeCenter, MaxOfMultiCubeSingleCubeIsMax)
{
    PolyCube::PointList cubes{{3, -5, 7}, {5, 7, 8}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(5, 7, 8), info.max);
}

TEST(PolyCube_ComputeCenter, MinOfMultiCubeMultiCubeIsMin)
{
    PolyCube::PointList cubes{{3, -5, 7}, {-5, 7, 8}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(-5, -5, 7), info.min);
}

TEST(PolyCube_ComputeCenter, MaxOfMultiCubeMultiCubeIsMax)
{
    PolyCube::PointList cubes{{30, -5, -7}, {5, 7, -8}};

    PolyCube::center_info info = PolyCube::compute_center(cubes);
    EXPECT_EQ(Coord(30, 7, -7), info.max);
}
