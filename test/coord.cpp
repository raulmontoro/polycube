#include <gtest/gtest.h>
#include <functional>

#include "Coord.hpp"

TEST(Coord, ComputeDistanceToOneAbove)
{
    Coord a (10, 10, 10);
    Coord b(10, 11, 10);
    EXPECT_EQ(1, a.distance_to(b));
}

TEST(Coord, ComputeDistanceToOneBelow)
{
    Coord a (10, 10, 10);
    Coord b(10, 11, 10);
    EXPECT_EQ(1, a.distance_to(b));
}

TEST(Coord, ComputeDistanceToOneRight)
{
    Coord a (10, 10, 10);
    Coord b(11, 10, 10);
    EXPECT_EQ(1, a.distance_to(b));
}

TEST(Coord, ComputeDistanceToOneLeft)
{
    Coord a (10, 10, 10);
    Coord b(9, 10, 10);
    EXPECT_EQ(1, a.distance_to(b));
}

TEST(Coord, ComputeDistanceToOneBehind)
{
    Coord a (10, 10, 10);
    Coord b(10, 10, 11);
    EXPECT_EQ(1, a.distance_to(b));
}

TEST(Coord, ComputeDistanceToOneInFront)
{
    Coord a (10, 10, 10);
    Coord b(10, 10, 9);
    EXPECT_EQ(1, a.distance_to(b));
}

TEST(Coord, ComputeHashToSameCoord)
{
    Coord a(10, 10, 10);
    Coord b(10, 10, 10);
    EXPECT_EQ(a.compute_hash(), b.compute_hash());
}

TEST(Coord, ComputeHashForSameCoordInstance)
{
    Coord a(10, 10, 10);
    EXPECT_EQ(a.compute_hash(), a.compute_hash());
}

TEST(Coord, ComputeHashUsingStdHashStruc)
{
    Coord a(55, 20, 10);
    std::hash<Coord> hasher;
    EXPECT_EQ(hasher(a), a.compute_hash());
}

TEST(Coord, ComputeHashOfTwoCoordsCombined)
{
    Coord a(55, 20, 10);
    Coord b(-10, 5, -33);
    std::hash<Coord> hasher;
    EXPECT_NE(hasher(a), hasher(b));
    EXPECT_NE(hasher(a), hasher(a, b));
    EXPECT_NE(hasher(b), hasher(a, b));
    EXPECT_EQ(hasher(b, a), hasher(a, b));
}

TEST(Coord, SubtractPoint)
{
    Coord a(40, 10, 10);
    Coord b(10, 1, 1);
    Coord result = a - b;
    EXPECT_EQ(Coord(30, 9, 9), result) << std::to_string(result.getX()) << "," << std::to_string(result.getY()) << "," << std::to_string(result.getZ());
}

TEST(Coord, SubtractAssignPoint)
{
    Coord a(10, 50, 10);
    Coord b(1, 41, 1);
    a -= b;
    EXPECT_EQ(Coord(9, 9, 9), a);
}

TEST(Coord, AdditionPoint)
{
    Coord a(10, 10, 10);
    Coord b(1, 20, 1);
    Coord result = a + b;
    EXPECT_EQ(Coord(11, 30, 11), result);
}

TEST(Coord, AdditionAssignPoint)
{
    Coord a(10, 10, 10);
    Coord b(1, 1, 40);
    a += b;
    EXPECT_EQ(Coord(11, 11, 50), a);
}

TEST(Coord, EqualComparision)
{
    Coord a(10, 10, 10);
    Coord b(1, 1, 40);
    Coord c(10, 10, 10);

    EXPECT_TRUE(a == a);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a == c);

    EXPECT_FALSE(b == c);
}

TEST(Coord, InequalComparision)
{
    Coord a(10, 10, 10);
    Coord b(1, 1, 40);
    Coord c(10, 10, 10);

    EXPECT_FALSE(a != a);
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != c);

    EXPECT_TRUE(b != c);
}
