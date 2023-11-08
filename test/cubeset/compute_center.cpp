#include <gtest/gtest.h>
#include "CubeSet.hpp"

TEST(CubeSet_ComputeCenter, CenterOfSingleCubeOnOrigin)
{
    CubeSet::CubeList cubes{{0, 0, 0}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(0, 0, 0), info.center);
}

TEST(CubeSet_ComputeCenter, CenterOfSingleCubeOffset)
{
    CubeSet::CubeList cubes{{3, 5, 7}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(3, 5, 7), info.center);
}

TEST(CubeSet_ComputeCenter, CenterOfMultiCubeOnOrigin)
{
    CubeSet::CubeList cubes{{0, 0, 0}, {2, -2, 6}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(1, -1, 3), info.center);
}

TEST(CubeSet_ComputeCenter, CenterOfMultiCubeOffset)
{
    CubeSet::CubeList cubes{{3, 5, 7}, {6, 7, 8}, {8, 8, 8}, {10, -40, -30}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(7, -5, -2), info.center);
}

TEST(CubeSet_ComputeCenter, MinOfSingleCube)
{
    CubeSet::CubeList cubes{{3, -5, 7}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(3, -5, 7), info.min);
}

TEST(CubeSet_ComputeCenter, MaxOfSingleCube)
{
    CubeSet::CubeList cubes{{3, -5, 7}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(3, -5, 7), info.max);
}

TEST(CubeSet_ComputeCenter, MinOfMultiCubeSingleCubeIsMin)
{
    CubeSet::CubeList cubes{{3, -5, 7}, {5, 7, 8}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(3, -5, 7), info.min);
}

TEST(CubeSet_ComputeCenter, MaxOfMultiCubeSingleCubeIsMax)
{
    CubeSet::CubeList cubes{{3, -5, 7}, {5, 7, 8}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(5, 7, 8), info.max);
}

TEST(CubeSet_ComputeCenter, MinOfMultiCubeMultiCubeIsMin)
{
    CubeSet::CubeList cubes{{3, -5, 7}, {-5, 7, 8}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(-5, -5, 7), info.min);
}

TEST(CubeSet_ComputeCenter, MaxOfMultiCubeMultiCubeIsMax)
{
    CubeSet::CubeList cubes{{30, -5, -7}, {5, 7, -8}};

    CubeSet::center_info info = CubeSet::compute_center(cubes);
    EXPECT_EQ(Coord(30, 7, -7), info.max);
}
