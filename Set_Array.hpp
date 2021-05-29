#pragma once

#include <ostream>
#include <set>
#include "Heap_Array.hpp"

template<class T>
struct Set_Array {
    Heap_Array<T> heap;

    Set_Array<T>() : heap() {};

    explicit Set_Array(const Heap_Array<T> &heap) : heap(heap) {}

    explicit Set_Array(const vector<T> &vec) : heap(vec) {}

    Set_Array(const Set_Array<T> &s) : heap(s.heap) {}

    Set_Array(const string &str, int check) : heap(str, check) {}

    bool search(const T v) const {
        return heap.search(v) != -1;
    }

    void insert(const T v) {
        heap.insert(v);
    }

    void remove(const T v) {
        heap.remove(v);
    }

    bool include(const Set_Array<T> &b) {
        for (int i = 0; i < b.size(); i++) {
            if (!search(b.heap[i]))
                return false;
        }
        return true;
    }

    [[nodiscard]] int size() const {
        return heap.size();
    }

    Set_Array<T> &operator+(const Set_Array<T> &b) const {
        auto *ans = new Set_Array<T>(b);
        for (int i = 0; i < heap.size(); i++) {
            ans->insert(heap[i]);
        }
        return *ans;
    }

    Set_Array<T> &operator-(const Set_Array<T> &b) const {
        auto *ans = new Set_Array<T>();
        for (int i = 0; i < size(); i++) {
            if (!b.search(heap[i]))
                ans->insert(heap[i]);
        }
        return *ans;
    }

    Set_Array<T> &operator*(const Set_Array<T> &b) const {
        auto *ans = new Set_Array<T>();
        for (int i = 0; i < heap.size(); i++) {
            if (b.search(heap[i]))
                ans->insert(heap[i]);
        }
        return *ans;
    }

    friend bool operator==(const Set_Array<T> &a, const Set_Array<T> &b) {
        vector<T> first(a.heap.data);
        vector<T> second(b.heap.data);
        sort(all(first), comp<T>);
        sort(all(second), comp<T>);
        return a.heap.data == b.heap.data;
    }

    friend bool operator==(const Set_Array<T> &a, const set<T> &b) {
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i++) {
            if (b.find(a.heap[i]) == b.end())
                return false;
        }
        return true;
    }

    friend ostream &operator<<(ostream &os, const Set_Array &b) {
        os << "{";
        for (int i = 0; i < b.size() - 1; i++)
            os << b.heap[i] << ", ";
        os << b.heap[b.size() - 1] << "}";
        return os;
    }

    ~Set_Array<T>() = default;
};