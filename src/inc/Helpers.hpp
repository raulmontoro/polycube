#pragma once
#ifndef POLYCUBES_HELPERS_HPP
#define POLYCUBES_HELPERS_HPP
#include <cstdint>

namespace helpers {

    
    /*  euclidian division 
        https://en.wikipedia.org/wiki/Euclidean_division
        two different sign rules    */

    constexpr int idiv_roundup(int numerator, int denominator)
    {
        int div = numerator / denominator;
        int remain = (numerator % denominator);

        /*      xor
                a   b   xor(a,b) = a^b
                ---------------
                1   0   1
                0   1   1
        */
        if (remain != 0)
        {
            /*  division sign rule
                numerator, denominator are different sing   -1
                numerator, denominator are same      sing    1
            */
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
