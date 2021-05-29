#pragma once

#include <ostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iterator>

using namespace std;
#define Unique(x) x.erase(unique(all(x)), x.end())
#define all(x) x.begin(), x.end()

template<class T>
struct Set_Vector
{
    vector<T> vec;

    Set_Vector<T>() : vec()
    {};


    explicit Set_Vector(const vector<T> &Vec) : vec(Vec)
    {
        sort(vec.begin(), vec.end());
        Unique(vec);
    }

    Set_Vector(const Set_Vector<T> &s) : vec(s.vec)
    {}

    bool search(const T v) const
    {
        auto it = lower_bound(all(vec), v);
        return *it == v;
    }

    void insert(const T v)
    {
        if(vec.size()==0)
        {
            vec.emplace_back(v);
            return;
        }
        auto it = lower_bound(all(vec), v);
        if (*it != v)
            vec.insert(it, v);
    }

    void remove(const T v)
    {
        if(vec.size()==0)
            return;
        auto it = lower_bound(all(vec), v);
        if (it != vec.end())
            vec.erase(it);
    }

    bool include(const Set_Vector<T> &b)
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

    Set_Vector<T> &operator+(const Set_Vector<T> &b) const
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
        return *(new Set_Vector(ans));

        //return merge(vec.begin(),vec.end(),b.vec.begin(),b.vec.end());
    }

    Set_Vector<T> &operator-(const Set_Vector<T> &b) const
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
        return *(new Set_Vector(ans));

//        vector<T> ans(vec.size());
//        set_difference(all(vec),all(b.vec),ans.begin());
//        ans.shrink_to_fit();
//        return *(new Set_Vector(ans));
    }

    Set_Vector<T> &operator*(const Set_Vector<T> &b) const
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
        return *(new Set_Vector(ans));

//        vector<T> ans(vec.size());
//        set_intersection(all(vec),all(b.vec),ans.begin());
//        ans.shrink_to_fit();
//        return *(new Set_Vector(ans));
    }

    friend bool operator==(const Set_Vector<T> &a, const Set_Vector<T> &b)
    {
        return a.vec.data == b.vec.data;
    }

    friend bool operator==(const Set_Vector<T> &a, const set<T> &b)
    {
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i++)
        {
            if (b.find(a.vec[i]) == b.end())
                return false;
        }
        return true;
    }

    friend ostream &operator<<(ostream &os, const Set_Vector &b)
    {
        os << "{";
        for (int i = 0; i < b.size() - 1; i++)
            os << b.vec[i] << ", ";
        os << b.vec[b.size() - 1] << "}";
        return os;
    }

    ~Set_Vector<T>() = default;
};