#include <gtest/gtest.h>

#include "CubeSet.hpp"
#include "PolyCube.hpp"

using namespace PolyCube;

TEST(CubeSet, FindSingleCubeInSingleMap)
{
    CubeSet set;
    PointList cube{{1, 1, 1}, {2, 2, 2}};
    center_info info = process_cube(cube);
    set.add_cube(cube, info.center, cube[cube.size() - 1]);

    EXPECT_TRUE(set.contains_cube(cube, info.center, cube[cube.size() - 1]));
}

TEST(CubeSet, FindSingleCubeInSingleMapButDifferentFurthest)
{
    CubeSet set;
    PointList cube{{1, 1, 1}, {2, 2, 2}};
    center_info info = process_cube(cube);
    set.add_cube(cube, info.center, cube[0]);

    EXPECT_FALSE(set.contains_cube(cube, info.center, cube[cube.size() - 1]));
}

TEST(CubeSet, FindSingleCubeInMultiMapButDifferentCubesFurthest)
{
    CubeSet set;
    PointList cube1{{1, 1, 1}, {2, 2, 2}};
    PointList cube2{{3, 3, 3}, {6, 6, 6}};
    center_info info1 = process_cube(cube1);
    center_info info2 = process_cube(cube2);
    set.add_cube(cube1, info1.center, cube1[0]);
    set.add_cube(cube2, info2.center, cube2[0]);

    EXPECT_FALSE(set.contains_cube(cube1, info1.center, cube2[cube2.size() - 1]));
}

TEST(CubeSet, FindSingleCubeInSingleMapButDifferentCenter)
{
    CubeSet set;
    PointList cube{{1, 1, 1}, {2, 2, 2}};
    center_info info = process_cube(cube);
    center_info fake_info = info;
    fake_info.center.setX(info.center.getX() + 10);
    set.add_cube(cube, fake_info.center, cube[0]);

    EXPECT_FALSE(set.contains_cube(cube, info.center, cube[cube.size() - 1]));
}

TEST(CubeSet, FindSingleCubeInSingleMapDoesntExist)
{
    CubeSet set;
    PointList cube{{1, 1, 1}, {2, 2, 2}};
    center_info info = process_cube(cube);
    set.add_cube(cube, info.center, cube[cube.size() - 1]);

    PointList cube_reverse{{2, 2, 2}, {1, 1, 1}};
    EXPECT_FALSE(set.contains_cube(cube_reverse, info.center, cube[cube.size() - 1])); // Use from cube on purpose so the hash value is the same but the actual list itself is not.
}

TEST(CubeSet, AddSeveralDozenAndQueryAll)
{
    CubeSet set;
    srand(500); // Always seed with the same number otherwise the test is not repeatable.
    std::vector<std::tuple<PointList, center_info>> cubes;

    constexpr long kCubeCount = 1000UL;

    while (cubes.size() < kCubeCount)
    {
        int n = (rand() % 14) + 1; // +1 so n can never be 0.
        PointList cube;
        for (int j = 0; j < n; j++)
        {
            cube.push_back(Coord(rand() % n, rand() % n, rand() % n));
        }
        center_info info = compute_center(cube);
        sort(cube, info.center);
        translate(cube, info.center);
        if (!set.contains_cube(cube, info.center, cube[cube.size() - 1]))
        {
            set.add_cube(cube, info.center, cube[cube.size() - 1]);
            cubes.push_back(std::make_tuple(cube, info));
        }
    }

    for (std::size_t i = 0; i < cubes.size(); i = i + 2)
    {
        PointList &points = std::get<0>(cubes[i]);
        center_info info = std::get<1>(cubes[i]);
        EXPECT_TRUE(set.contains_cube(points, info.center, points[points.size() - 1])) << "Failed for cube nr: " << i;
    }
    for (std::size_t i = 1; i < cubes.size(); i = i + 2)
    {
        PointList &points = std::get<0>(cubes[i]);
        center_info info = std::get<1>(cubes[i]);
        EXPECT_TRUE(set.contains_cube(points, info.center, points[points.size() - 1])) << "Failed for cube nr: " << i;
    }
}
