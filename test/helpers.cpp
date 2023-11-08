#include <gtest/gtest.h>

#include "Helpers.hpp"

TEST(IntegerRoundDivision, Divide5By5) // 5/5   = 1.00 --> 1
{
    constexpr int a = 5;
    constexpr int b = 5;
    constexpr int result = 1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide5By4) // 5/4   = 1.25 --> 2
{
    constexpr int a = 5;
    constexpr int b = 4;
    constexpr int result = 2;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide6By4) // 6/4   = 1.50 --> 2
{
    constexpr int a = 6;
    constexpr int b = 4;
    constexpr int result = 2;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide7By4) // 7/4   = 1.75 --> 2
{
    constexpr int a = 7;
    constexpr int b = 4;
    constexpr int result = 2;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide9By10) // 9/10  = 0.90 --> 1
{
    constexpr int a = 9;
    constexpr int b = 10;
    constexpr int result = 1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide3By4) // 3/4   = 0.75 --> 1
{
    constexpr int a = 3;
    constexpr int b = 4;
    constexpr int result = 1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, DivideNeg3By4) // -3/4  = -0.75 --> -1
{
    constexpr int a = -3;
    constexpr int b = 4;
    constexpr int result = -1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide3ByNeg4) // 3/-4  = -0.75 --> -1
{
    constexpr int a = 3;
    constexpr int b = -4;
    constexpr int result = -1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, DivideNeg3ByNeg4) // -3/-4 = 0.75 --> 1
{
    constexpr int a = -3;
    constexpr int b = -4;
    constexpr int result = 1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide999By1000) // 999/1000    = 0.999 --> 1
{
    constexpr int a = 999;
    constexpr int b = 1000;
    constexpr int result = 1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, DivideNeg999By1000) // -999/1000   = -0.999 --> -1
{
    constexpr int a = -999;
    constexpr int b = 1000;
    constexpr int result = -1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, Divide999ByNeg1000) // 999/-1000   = -0.999 --> -1
{
    constexpr int a = 999;
    constexpr int b = -1000;
    constexpr int result = -1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(IntegerRoundDivision, DivideNeg999ByNeg1000) // -999/-1000  = 0.999 --> 1
{
    constexpr int a = -999;
    constexpr int b = -1000;
    constexpr int result = 1;

    EXPECT_EQ(result, helpers::idiv_roundup(a, b));
}

TEST(HashFunction, AddHashesInReverse)
{
    constexpr std::size_t a = 0xABCDEF;
    constexpr std::size_t b = 0x123456789;

    EXPECT_EQ(helpers::add_to_hash(a, b), helpers::add_to_hash(b, a));
}

TEST(HashFunction, AddHashesOfFullSizeInReverse)
{
    constexpr std::size_t a = 0x1234567890ABCDEFLL;
    constexpr std::size_t b = 0xCDEFFEDCBA098765LL;

    EXPECT_EQ(helpers::add_to_hash(a, b), helpers::add_to_hash(b, a));
}
