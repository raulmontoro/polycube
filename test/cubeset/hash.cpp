#include <gtest/gtest.h>
#include "CubeSet.hpp"
#include "Helpers.hpp"

TEST(CubeSet_Hash, SingleCubeHash)
{
    CubeSet::CubeList cubes{{1,1,1}};
    
    EXPECT_EQ(cubes[0].compute_hash(), CubeSet::compute_hash(cubes));
}

TEST(CubeSet_Hash, MultiCubeHash)
{
    CubeSet::CubeList cubes{{1,1,1}, {-5, 8, 1}, {5, -9, 100}};

    std::size_t hash = helpers::add_to_hash(cubes[0].compute_hash(), cubes[1].compute_hash(), cubes[2].compute_hash());

    EXPECT_EQ(hash, CubeSet::compute_hash(cubes));
}

TEST(CubeSet_Hash, MultiCubeHashDifferentOrder)
{
    CubeSet::CubeList cubes{{1,1,1}, {-5, 8, 1}, {5, -9, 100}};

    std::size_t hash = helpers::add_to_hash(cubes[2].compute_hash(), cubes[0].compute_hash(), cubes[1].compute_hash());

    EXPECT_EQ(hash, CubeSet::compute_hash(cubes));
}
