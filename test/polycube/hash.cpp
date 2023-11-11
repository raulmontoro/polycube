#include <gtest/gtest.h>
#include "PolyCube.hpp"
#include "Helpers.hpp"

TEST(PolyCube_Hash, SingleCubeHash)
{
    PolyCube::PointList cubes{{1,1,1}};
    
    EXPECT_EQ(cubes[0].compute_hash(), PolyCube::compute_hash(cubes));
}

TEST(PolyCube_Hash, MultiCubeHash)
{
    PolyCube::PointList cubes{{1,1,1}, {-5, 8, 1}, {5, -9, 100}};

    std::size_t hash = helpers::add_to_hash(cubes[0].compute_hash(), cubes[1].compute_hash(), cubes[2].compute_hash());

    EXPECT_EQ(hash, PolyCube::compute_hash(cubes));
}

TEST(PolyCube_Hash, MultiCubeHashDifferentOrder)
{
    PolyCube::PointList cubes{{1,1,1}, {-5, 8, 1}, {5, -9, 100}};

    std::size_t hash = helpers::add_to_hash(cubes[2].compute_hash(), cubes[0].compute_hash(), cubes[1].compute_hash());

    EXPECT_EQ(hash, PolyCube::compute_hash(cubes));
}
