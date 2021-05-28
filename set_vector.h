#pragma once

#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <iterator>

using namespace std;
#define Unique(x) x.erase(unique(all(x)), x.end())
#define all(x) x.begin(), x.end()

template<class T>
struct Set_vec
{
    vector<T> vec;

    Set_vec<T>() : vec()
    {};


    explicit Set_vec(const vector<T> &Vec) : vec(Vec)
    {
        sort(vec.begin(), vec.end());
        Unique(vec);
    }

    Set_vec(const Set_vec<T> &s) : vec(s.vec)
    {}

    bool search(const T v) const
    {
        auto it = lower_bound(all(vec), v);
        return *it == v;
    }

    void insert(const T v)
    {
        auto it = lower_bound(all(vec), v);
        if (*it != v)
            vec.insert(it, v);
    }

    void remove(const T v)
    {
        auto it = lower_bound(all(vec), v);
        if (it != vec.end())
            vec.erase(it);
    }

    bool include(const Set_vec<T> &b)
    {
        int i = 0;
        for (int j = 0; j < b.size(); j++)
        {
            while (i < vec.size() && vec[i] != b.vec[j])
                i++;
            if (i == vec.size())
                return false;
        }
        return true;
    }

    [[nodiscard]] int size() const
    {
        return vec.size();
    }

    Set_vec<T> &operator+(const Set_vec<T> &b) const
    {
        vector<T> ans(vec.size() + b.size());
        int i = 0, j = 0, size = 0;
        while (i < vec.size() && j < b.size())
        {
            if (vec[i] == b.vec[j])
            {
                ans[size++] = vec[i];
                i++;
                j++;
                continue;
            }
            while (i < vec.size() && vec[i] < b.vec[j])
            {
                ans[size++] = vec[i++];
            }
            while (j < b.size() && b.vec[j] < vec[i])
            {
                ans[size++] = b.vec[j++];
            }
        }
        while (i < vec.size())
            ans[size++] = vec[i++];
        while (j < b.size())
            ans[size++] = b.vec[j++];

        ans.resize(size);
        return *(new Set_vec(ans));
    }

    Set_vec<T> &operator-(const Set_vec<T> &b) const
    {
        vector<T> ans(vec.size());
        int i = 0, j = 0, size = 0;
        while (i < vec.size() && j < b.size())
        {
            if (vec[i] == b.vec[j])
            {
                i++;
                j++;
                continue;
            }
            while (i < vec.size() && vec[i] < b.vec[j])
            {
                ans[size++] = vec[i++];
            }
            while (j < b.size() && b.vec[j] < vec[i])
            {
                j++;
            }
        }
        if (j >= b.size() && i < vec.size())
            while (i < vec.size())
                ans[size++] = vec[i++];
        ans.resize(size);
        return *(new Set_vec(ans));
    }

    Set_vec<T> &operator*(const Set_vec<T> &b) const
    {
        vector<T> ans(vec.size());
        int i = 0, j = 0, size = 0;
        while (i < vec.size() && j < b.size())
        {
            if (vec[i] == b.vec[j])
            {
                ans[size++] = vec[i];
                i++;
                j++;
                continue;
            }
            while (i < vec.size() && vec[i] < b.vec[j])
                i++;
            while (j < b.size() && b.vec[j] < vec[i])
                j++;
        }
        ans.resize(size);
        return *(new Set_vec(ans));
    }

    friend bool operator==(const Set_vec<T> &a, const Set_vec<T> &b)
    {
        return a.vec.data == b.vec.data;
    }

    friend ostream &operator<<(ostream &os, const Set_vec &b)
    {
        os << "{";
        for (int i = 0; i < b.size() - 1; i++)
            os << b.vec[i] << ", ";
        os << b.vec[b.size() - 1] << "}";
        return os;
    }

    ~Set_vec<T>() = default;
};