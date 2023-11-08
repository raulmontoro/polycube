#pragma once
#ifndef POLYCUBES_HELPERS_HPP
#define POLYCUBES_HELPERS_HPP
#include <cstdint>

namespace helpers {
    constexpr int idiv_roundup(int numerator, int denominator)
    {
        int div = numerator / denominator;
        int remain = (numerator % denominator);
        if (remain != 0)
        {
            div += (1 - (((denominator < 0) ^ (numerator < 0)) * 2));
        }
        return div;
    }

    constexpr std::size_t add_to_hash(std::size_t start, std::size_t hash)
    {
        return hash ^ 0x9e3779b9 ^ start;
    }

    template<typename... T>
    constexpr std::size_t add_to_hash(std::size_t start, std::size_t hash, T... hashes)
    {
        std::size_t new_base = add_to_hash(start, hash);
        return add_to_hash(new_base, hashes...);
    }
}

#endif // POLYCUBES_HELPERS_HPP
