#pragma once
#ifndef POLYCUBES_HASHEDLIST_HPP
#define POLYCUBES_HASHEDLIST_HPP

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <initializer_list>
#include <type_traits>
using namespace std;

template <typename T, typename TMapType = unordered_map<size_t, T>>
class HashedList
{
    private:
        using map = TMapType;
        map values;

        template<typename Tx, typename TMap>
        static Tx find_by_hash(size_t hash, TMap& map)
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
    
    public:
        using hasher = hash<typename remove_cv<T>::type>;
        using iterator = typename map::iterator;
        using const_iterator = typename map::const_iterator;
    
        HashedList(){}
    
        HashedList(initializer_list<T> list)
        {
            for (const auto& t : list)
            {
                add(t);
            }
        }
    
        const_iterator find_by_hash(size_t hash) const
        {
            return find_by_hash<const_iterator, const map>(hash, values);
        }
    
        iterator find_by_hash(size_t hash)
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
            size_t hash = hashing(t);
            auto it = values.find(hash);
            if (it != values.end())
            {
                return;
            }
            else
            {
                values.insert(make_pair(hash, t));
            }
        }
    
        size_t size() const
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
};

#endif // POLYCUBES_HASHEDLIST_HPP
