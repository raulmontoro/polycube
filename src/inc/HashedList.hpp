#pragma once
#ifndef POLYCUBES_HASHEDLIST_HPP
#define POLYCUBES_HASHEDLIST_HPP
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <initializer_list>
#include <type_traits>

template <typename T>
class HashedList
{
private:
    using map = std::unordered_map<std::size_t, T>;

public:
    using hasher = std::hash<typename std::remove_cv<T>::type>;
    using iterator = typename map::iterator;
    using const_iterator = typename map::const_iterator;

private:
    map values;

public:
    HashedList(){}

    HashedList(std::initializer_list<T> list)
    {
        for (const auto& t : list)
        {
            add(t);
        }
    }

    const_iterator find_by_hash(std::size_t hash) const
    {
        return find_by_hash<const_iterator, const map>(hash, values);
    }

    iterator find_by_hash(std::size_t hash)
    {
        return find_by_hash<iterator, map>(hash, values);
    }

    iterator find(const T &t)
    {
        return find<iterator, const T, map>(t, values);
    }

    const_iterator find(const T &t) const
    {
        return find<const_iterator, const T, const map>(t, values);        
    }

    void add(const T &t)
    {
        hasher hashing;
        std::size_t hash = hashing(t);
        auto it = values.find(hash);
        if (it != values.end())
        {
            return;
        }
        else
        {
            values.insert(std::make_pair(hash, t));
        }
    }

    std::size_t size() const
    {
        return values.size();
    }

    iterator begin()
    {
        return values.begin();
    }

    const_iterator begin() const
    {
        return values.begin();
    }

    iterator end()
    {
        return values.end();
    }

    const_iterator end() const
    {
        return values.end();
    }

    const_iterator cbegin() const
    {
        return values.cbegin();
    }

    const_iterator cend() const
    {
        return values.cend();
    }

private:
    template<typename Tx, typename TMap>
    static Tx find_by_hash(std::size_t hash, TMap& map)
    {
        auto it = map.find(hash);
        if (it != map.end())
        {
            return it;
        }
        return map.end();
    }

    template<typename Tx, typename Ty, typename TMap>
    static Tx find(Ty& t, TMap& map)
    {
        hasher hashing;
        auto it = map.find(hashing(t));
        if (it != map.end())
        {
            return it;
        }
        return map.end();
    }
};

#endif // POLYCUBES_HASHEDLIST_HPP
