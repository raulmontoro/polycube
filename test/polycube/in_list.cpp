#include <gtest/gtest.h>

#include "Coord.hpp"
#include "PolyCube.hpp"

using namespace PolyCube;

TEST(PolyCube_InList, NotInListEmptyList)
{
    PointList list;
    EXPECT_FALSE(point_in_list(list, Coord(0, 0, 0)));
    EXPECT_FALSE(point_in_list(list, Coord(1, 1, 1)));
}

TEST(PolyCube_InList, NotInListList)
{
    PointList list {{1,1,1}, {3,3,3}};
    EXPECT_FALSE(point_in_list(list, Coord(0, 0, 0)));
    EXPECT_FALSE(point_in_list(list, Coord(2, 2, 2)));
    EXPECT_FALSE(point_in_list(list, Coord(0, 1, 1)));
}

TEST(PolyCube_InList, InListList)
{
    PointList list {{1,1,1}, {3,3,3}};
    EXPECT_TRUE(point_in_list(list, Coord(1, 1, 1)));
    EXPECT_TRUE(point_in_list(list, Coord(3, 3, 3)));
}
