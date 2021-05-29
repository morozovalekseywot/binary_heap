#pragma once

#include "Heap_Node.hpp"

using namespace std;

template<class T>
struct Set_Node {
    Heap_Node<T> data;

    Set_Node() : data() {}

    explicit Set_Node(Heap_Node<T> *heap) : data(*heap) {}

    explicit Set_Node(const vector<T> &vec) : data(vec) {}

    Set_Node(const Set_Node<T> &st) : data(st.data) {}

    [[nodiscard]] bool search(const T &target) const {
        return data.search(target);
    }

    void insert(const T &target) {
        data.insert(target);
    }

    void print(ostream &out) {
        out << "{";
        if (data.root) data.root->print(out);
        out << "}";
    }

    void remove(const T &target) {
        data.remove(target);
    }

    [[nodiscard]] vector<T> getValues() const {
        return data.getValues();
    }

    [[nodiscard]] int getSize() const {
        return getValues().size();
    }

    [[nodiscard]] bool include(const Set_Node<T> st) const {
        auto values = st.getValues();
        for (T item: values)
            if (!search(item))
                return false;
        return true;
    }

    [[nodiscard]] Set_Node<T> &intersection(const Set_Node<T> &st) const {
        auto *intersection = new Set_Node<T>();
        vector<T> values = data.getValues();
        for (T item: values)
            if (st.search(item))
                intersection->insert(item);
        return *intersection;
    }

    [[nodiscard]] Set_Node<T> &unification(const Set_Node<T> &st) const {
        auto *unity = new Set_Node<T>();
        vector<T> values1 = data.getValues();
        vector<T> values2 = st.data.getValues();
        for (T item: values1)
            unity->insert(item);
        for (T item: values2)
            unity->insert(item);
        return *unity;
    }

    [[nodiscard]] Set_Node<T> &subtraction(const Set_Node<T> &st) const {
        auto *sub = new Set_Node<T>();
        vector<T> values = data.getValues();
        for (T item: values)
            if (!st.search(item))
                sub->insert(item);
        return *sub;
    }

    const Set_Node &operator*(const Set_Node &st) const {
        return intersection(st);
    }

    const Set_Node &operator+(const Set_Node &st) const {
        return unification(st);
    }

    const Set_Node &operator-(const Set_Node &st) const {
        return subtraction(st);
    }

    friend bool operator==(const Set_Node<T> &st1, const Set_Node<T> &st2) {
        auto values1 = st1.data.getValues();
        auto values2 = st2.data.getValues();
        sort(values1.begin(), values1.end());
        sort(values2.begin(), values2.end());
        return values1 == values2;
    }

    friend bool operator!=(const Set_Node<T> &st1, const Set_Node<T> &st2) {
        return !(st1 == st2);
    }

    friend bool operator==(const Set_Node<T> &st1, const set<T> &st2) {
        auto values = st1.data.getValues();
        set<T> new_st1(values.begin(), values.end());
        return new_st1 == st2;
    }

    friend bool operator!=(const Set_Node<T> &st1, const set<T> &st2) {
        return !(st1 == st2);
    }

    ~Set_Node() = default;
};

Set_Node<int> &setFromString(const string &str) {
    auto *st = new Set_Node<int>();
    int item;
    for (int i = 0; i < str.size(); i++) {
        int j = i;
        while (j < str.size() && str[j] != ' ')
            j++;
        if (str[i] == '-') {
            item = -convert(str.substr(i + 1, j - i - 1));
        } else {
            item = convert(str.substr(i, j - i));
        }
        st->insert(item);
        i = j;
    }
    return *st;
}