#include <gtest/gtest.h>

#include "PolyCube.hpp"

TEST(PolyCube_Translate, TranslateZero)
{
    PolyCube::PointList cubes{{1, 1, 1}, {2, 2, 2}, {-8, 10, 5}};

    PolyCube::translate(cubes, Coord(0, 0, 0));

    ASSERT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(1, 1, 1), cubes[0]);
    EXPECT_EQ(Coord(2, 2, 2), cubes[1]);
    EXPECT_EQ(Coord(-8, 10, 5), cubes[2]);
}

TEST(PolyCube_Translate, TranslateUniformNegative)
{
    PolyCube::PointList cubes{{1, 1, 1}, {2, 2, 2}, {-8, 10, 5}};

    PolyCube::translate(cubes, Coord(-5, -5, -5));

    ASSERT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(-4, -4, -4), cubes[0]);
    EXPECT_EQ(Coord(-3, -3, -3), cubes[1]);
    EXPECT_EQ(Coord(-13, 5, 0), cubes[2]);
}

TEST(PolyCube_Translate, TranslateUniform)
{
    PolyCube::PointList cubes{{1, 1, 1}, {2, 2, 2}, {-8, 10, 5}};

    PolyCube::translate(cubes, Coord(5, 5, 5));

    ASSERT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(6, 6, 6), cubes[0]);
    EXPECT_EQ(Coord(7, 7, 7), cubes[1]);
    EXPECT_EQ(Coord(-3, 15, 10), cubes[2]);
}

TEST(PolyCube_Translate, TranslateUnequalNegative)
{
    PolyCube::PointList cubes{{1, 1, 1}, {2, 2, 2}, {-8, 10, 5}};

    PolyCube::translate(cubes, Coord(-3, -8, -100));

    ASSERT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(-2, -7, -99), cubes[0]);
    EXPECT_EQ(Coord(-1, -6, -98), cubes[1]);
    EXPECT_EQ(Coord(-11, 2, -95), cubes[2]);
}

TEST(PolyCube_Translate, TranslateUnequal)
{
    PolyCube::PointList cubes{{1, 1, 1}, {2, 2, 2}, {-8, 10, 5}};

    PolyCube::translate(cubes, Coord(3, 8, 100));

    ASSERT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(4, 9, 101), cubes[0]);
    EXPECT_EQ(Coord(5, 10, 102), cubes[1]);
    EXPECT_EQ(Coord(-5, 18, 105), cubes[2]);
}

TEST(PolyCube_Translate, TranslateMixedNegPos)
{
    PolyCube::PointList cubes{{1, 1, 1}, {2, 2, 2}, {-8, 10, 5}};

    PolyCube::translate(cubes, Coord(4, -8, 30));

    ASSERT_EQ(3, cubes.size());
    EXPECT_EQ(Coord(5, -7, 31), cubes[0]);
    EXPECT_EQ(Coord(6, -6, 32), cubes[1]);
    EXPECT_EQ(Coord(-4, 2, 35), cubes[2]);
}
