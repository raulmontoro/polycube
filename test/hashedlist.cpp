#include <gtest/gtest.h>
#include "HashedList.hpp"

// #define POLYCUBES_INCLUDE_TIME_TESTS

#ifdef POLYCUBES_INCLUDE_TIME_TESTS
#include <thread>
#include <iostream>
#include <chrono>
#endif // POLYCUBES_INCLUDE_TIME_TESTS

TEST(HashedList, SeveralIntsSameValue)
{
    HashedList<int> map{1, 1, 1, 1, 1};

    EXPECT_EQ(1, map.size());
}

TEST(HashedList, AddSeveralIntsSameValue)
{
    HashedList<int> map{1};

    EXPECT_EQ(1, map.size());
    map.add(1);
    map.add(1);
    map.add(1);
    EXPECT_EQ(1, map.size());
}

TEST(HashedList, FindNonExistingValue)
{
    HashedList<int> map{1, 2, 3, 4};

    EXPECT_EQ(4, map.size());
    EXPECT_EQ(nullptr, map.find(5));
}

TEST(HashedList, FindExistingValue)
{
    HashedList<int> map{1, 2, 3, 4};

    EXPECT_EQ(4, map.size());
    EXPECT_EQ(1, map.find(1)->second);
    EXPECT_EQ(2, map.find(2)->second);
    EXPECT_EQ(3, map.find(3)->second);
    EXPECT_EQ(4, map.find(4)->second);
}

TEST(HashedList, InitializeOverSeveralBins)
{
    HashedList<int> map{1, 2, 3, 4, 5, 6, 7, 8, 9};

    EXPECT_EQ(9, map.size());

    // Default hashing for std::hash<int> just takes the int value as the hash.
    EXPECT_EQ(1, map.find_by_hash(1)->second);
    EXPECT_EQ(1, map.find(1)->second);
    EXPECT_EQ(2, map.find_by_hash(2)->second);
    EXPECT_EQ(2, map.find(2)->second);
    EXPECT_EQ(3, map.find_by_hash(3)->second);
    EXPECT_EQ(3, map.find(3)->second);
    EXPECT_EQ(4, map.find_by_hash(4)->second);
    EXPECT_EQ(4, map.find(4)->second);
    EXPECT_EQ(5, map.find_by_hash(5)->second);
    EXPECT_EQ(5, map.find(5)->second);
    EXPECT_EQ(6, map.find_by_hash(6)->second);
    EXPECT_EQ(6, map.find(6)->second);
    EXPECT_EQ(7, map.find_by_hash(7)->second);
    EXPECT_EQ(7, map.find(7)->second);
    EXPECT_EQ(8, map.find_by_hash(8)->second);
    EXPECT_EQ(8, map.find(8)->second);
    EXPECT_EQ(9, map.find_by_hash(9)->second);
    EXPECT_EQ(9, map.find(9)->second);
}

#ifdef POLYCUBES_INCLUDE_TIME_TESTS

TEST(HashedList, SpeedBenchmark)
{
    using namespace std::chrono;
    HashedList<int> custom_map;
    HashedList<int, std::unordered_multimap<std::size_t, int>> custom_map_multi;
    std::unordered_map<std::size_t, int> default_map;

    constexpr long kItemCount =  1L * 1000L * 1000L;
    constexpr long kReportEvery =      100L * 1000L;
    for (long i = 0; i < kItemCount; i++)
    {
        custom_map.add(i);
        custom_map_multi.add(i);
        default_map.emplace(std::make_pair(i, i));
        if (i % kReportEvery == 0)
        {
            std::cout << i << std::endl;
            std::this_thread::sleep_for(milliseconds(100));
        }
    }

    std::cout << "Starting test." << std::endl;

#define loop_system(code)                                      \
    for (long i = 0; i < 1000; i++)                              \
    {                                                          \
        for (long j = kItemCount - 20000; j > 0; j -= 100)     \
        {                                                      \
            for (long k = 0; k < 10000; k = ((k + 10000) - 10)) \
            {                                                  \
                code                                           \
            }                                                  \
        }                                                      \
    }

    unsigned long count = 0;
    auto custom_map_start = high_resolution_clock::now();
    loop_system(
        volatile int b = custom_map.find(i + j + k)->second;
        b++;
        count += b;
    );
    auto custom_map_end = high_resolution_clock::now();
    std::cout << "Count: " << count << std::endl;

    count = 0;

    auto custom_map_multi_start = high_resolution_clock::now();
    loop_system(
        auto result = custom_map_multi.find(i + j + k);
        volatile int b = result->second;
        b++;
        count += b;
    );
    auto custom_map_multi_end = high_resolution_clock::now();
    std::cout << "Count: " << count << std::endl;


    auto default_map_start = high_resolution_clock::now();
    loop_system(
                volatile int b = default_map.find(i + j + k)->second;
                b++;
                count += b;
    );
    auto default_map_end = high_resolution_clock::now();

    std::cout << "Count: " << count << std::endl;

    auto custom_time = duration_cast<milliseconds>(custom_map_end - custom_map_start);
    auto custom_time_multi = duration_cast<milliseconds>(custom_map_multi_end - custom_map_multi_start);
    auto default_map_time = duration_cast<milliseconds>(default_map_end - default_map_start);

    std::cout << "Custom time:         " << custom_time.count() << std::endl;
    std::cout << "Custom time multi:   " << custom_time_multi.count() << std::endl;
    std::cout << "Default map time:    " << default_map_time.count() << std::endl;
}

#endif // POLYCUBES_INCLUDE_TIME_TESTS
