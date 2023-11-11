// #include <gtest/gtest.h>

// #include "CubeSet.hpp"

// TEST(CubeSet, HashOfSameInstance)
// {
//     CubeSet set({{1,1,1}, {2,2,2}});
//     EXPECT_EQ(set.compute_hash(), set.compute_hash());
// }

// TEST(CubeSet, HashOfDiffInstanceButSamePoints)
// {
//     CubeSet set1({{1,1,1}, {2,2,2}});
//     CubeSet set2({{1,1,1}, {2,2,2}});
//     EXPECT_EQ(set1.compute_hash(), set2.compute_hash());
// }

// TEST(CubeSet, HashOfDiffInstanceButSamePointsInDifferentOrder)
// {
//     CubeSet set1({{1,1,1}, {2,2,2}});
//     CubeSet set2({ {2,2,2}, {1,1,1}});
//     EXPECT_EQ(set1.compute_hash(), set2.compute_hash());
// }

// TEST(CubeSet, HashOfDiffInstanceButSameTwoPointsOffset)
// {
//     CubeSet set1({{1,1,1}, {2,2,2}});
//     CubeSet set2({{5,5,5}, {6,6,6}});
//     EXPECT_EQ(set1.compute_hash(), set2.compute_hash());
// }

// TEST(CubeSet, HashOfDiffInstanceButSameTwoPointsOffsetInDifferentOrientation)
// {
//     CubeSet set1({{1,1,1}, {2,2,2}});
//     CubeSet set2({{6,6,6}, {5,5,5}});
//     EXPECT_EQ(set1.compute_hash(), set2.compute_hash());
// }

// TEST(CubeSet, CenterOfBasicTriangle2D)
// {
//     CubeSet set1({{1,1,1}, {2,1,1}, {1,2,1}});
//     EXPECT_EQ(Coord(0, 0, 0), set1.cubes[0]);
//     EXPECT_EQ(Coord(1, 0, 0), set1.cubes[1]);
//     EXPECT_EQ(Coord(0, 1, 0), set1.cubes[2]);
// }

// TEST(CubeSet, CenterOfBasicOffsetTriangle2D)
// {
//     CubeSet set1({{5,5,5}, {6,5,5}, {5,6,5}});
//     EXPECT_EQ(Coord(0, 0, 0), set1.cubes[0]);
//     EXPECT_EQ(Coord(1, 0, 0), set1.cubes[1]);
//     EXPECT_EQ(Coord(0, 1, 0), set1.cubes[2]);
// }

// TEST(CubeSet, CenterOfBasicOffsetRotatedTriangle2D)
// {
//     CubeSet set1({{5,5,5}, {4,5,5}, {5,4,5}});
//     EXPECT_EQ(Coord(0, 0, 0), set1.cubes[0]);
//     EXPECT_EQ(Coord(-1, 0, 0), set1.cubes[1]);
//     EXPECT_EQ(Coord(0, -1, 0), set1.cubes[2]);
// }

// TEST(CubeSet, HashOfDiff2DTragInstanceButDifferentOrientation)
// {
//     CubeSet set1({{1,1,1}, {2,1,1}, {1,2,1}});
//     CubeSet set2({{5,5,5}, {5,4,5}, {4,5,5}});
//     EXPECT_EQ(set1.compute_hash(), set2.compute_hash());
// }
// /*
// TEST(CubeSet, HashOfDiff3DTraigInstanceButDifferentOrientation)
// {
//     CubeSet set1({{1,1,1}, {1,1,2}, {2,1,1}, {1,2,1}});
//     CubeSet set2({{5,5,5}, {5,5,4}, {5,4,5}, {4,5,5}});
//     EXPECT_EQ(set1.compute_hash(), set2.compute_hash());
// }
// */
