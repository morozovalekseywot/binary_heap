#pragma once

#include <ostream>
#include "binary_heap.h"

template<class T>
struct Set
{
    Heap<T> heap;

    Set<T>() : heap()
    {};

    explicit Set(const Heap<T> &heap) : heap(heap)
    {}

    explicit Set(const vector<T> &vec) : heap(vec)
    {}

    Set(const Set<T> &s) : heap(s.heap)
    {}

    Set(const string &str,int check) : heap(str,check)
    {}

    bool search(const T v) const
    {
        return heap.search(v) != -1;
    }

    void insert(const T v)
    {
        heap.insert(v);
    }

    bool sub_set(const Set<T> &b)
    {
        return heap.search_heap(b.heap);
    }

    [[nodiscard]] int size() const
    {
        return heap.size();
    }

    Set<T> &operator+(const Set<T> &b) const
    {
        auto *ans = new Set<T>(b);
        for (int i = 0; i < heap.size(); i++)
        {
            ans->insert(heap[i]);
        }
        return *ans;
    }

    Set<T> &operator-(const Set<T> &b) const
    {
        auto *ans = new Set<T>();
        for (int i = 0; i < size(); i++)
        {
            if (!b.search(heap[i]))
                ans->insert(heap[i]);
        }
        return *ans;
    }

    Set<T> &operator*(const Set<T> &b) const
    {
        auto *ans = new Set<T>();
        for (int i = 0; i < heap.size(); i++)
        {
            if (b.search(heap[i]))
                ans->insert(heap[i]);
        }
        return *ans;
    }

    friend bool operator==(const Set<T> &a, const Set<T> &b)
    {
        vector<T> first(a.heap.data);
        vector<T> second(b.heap.data);
        sort(all(first));
        sort(all(second));
        return a.heap.data == b.heap.data;
    }

    friend ostream &operator<<(ostream &os, const Set &b)
    {
        os << "{";
        for (int i = 0; i < b.size() - 1; i++)
            os << b.heap[i] << ", ";
        os << b.heap[b.size() - 1] << "}";
        return os;
    }

    ~Set<T>() = default;
};