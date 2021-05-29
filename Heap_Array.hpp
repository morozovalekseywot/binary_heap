#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;
#define Unique(x) x.erase(unique(all(x)), x.end())
#define all(x) x.begin(), x.end()

template<class T>
bool comp(T &a, T &b) {
    return a > b;
}

int convert(const string &str) {
    int ans = 0, k = 1;
    for (int i = int(str.size()) - 1; i >= 0; i--) {
        ans += (str[i] - '0') * k;
        k *= 10;
    }
    return ans;
}

template<class T>
struct Heap_Array {
    vector<T> data; // у i наследники 2*i+1 и 2*i+2

    explicit Heap_Array(const vector<T> &vec) : data(vec) {
        if (!data.empty()) {
            sort(data.begin(), data.end(), comp<T>);
            Unique(data);
            for (int i = 1; i < data.size() - 1; i += 2)
                swap(data[i], data[i + 1]);
        }
    };

    Heap_Array(const Heap_Array<T> &heap) : data(heap.data) {}

    Heap_Array() : data(vector<T>()) {};

    explicit Heap_Array(const string &str, int check) {
        vector<int> vec;
        for (int i = 0; i < str.size(); i++) {
            int j = i;
            while (j < str.size() && str[j] != ' ')
                j++;
            if (str[i] == '-')
                vec.emplace_back(-convert(str.substr(i + 1, j - i - 1)));
            else
                vec.emplace_back(convert(str.substr(i, j - i)));
            i = j;
        }
        *this = Heap_Array(vec);
    }

    void insert(T v);

    int search(T v, int it = 0) const;

    void remove(T v);


    //void heapify(int it = 0);
    [[nodiscard]] inline bool check(int it) const {
        return it < data.size();//&& heap[it] != NULL
    }

    [[nodiscard]] int size() const {
        return data.size();
    }

    void inline check_brother(int it) {
        if (it < 0)
            return;
        int left = 2 * it + 1, right = 2 * it + 2;
        if (left < data.size() && right < data.size()) {
            if (data[left] > data[right])
                swap(data[left], data[right]);
            return;
        }
    }

    T operator[](int i) const {
        if (i < 0 || i >= data.size())
            throw out_of_range("Index out of range in operator []");
        return data[i];
    }

    T &operator[](int i) {
        if (i < 0 || i >= data.size())
            throw out_of_range("Index out of range in operator &[]");
        return data[i];
    }

    // == Обходы ==
    // 1. КЛП = Корень Левый Правый
    void printNLR(int it, ostream &os) {
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
        if (check(2 * it + 1))
            printNLR(2 * it + 1, os);
        if (check(2 * it + 2))
            printNLR(2 * it + 2, os);
    }

    void printNLR2(int it, ostream &os) {
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
        if (check(2 * it + 1))
            os << "(" << data[2 * it + 1] << ") ";
        if (check(2 * it + 2))
            os << "[" << data[2 * it + 2] << "] ";
        if (check(2 * it + 1))
            printNLR2(2 * it + 1, os);
        if (check(2 * it + 2))
            printNLR2(2 * it + 2, os);
    }

    // 2. КПЛ = Корень Правый Левый
    void printNRL(int it, ostream &os) {
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
        if (check(2 * it + 2))
            printNRL(2 * it + 2, os);
        if (check(2 * it + 1))
            printNRL(2 * it + 1, os);
    }

    // 3. ЛПК = Левый Правый Корень
    void printLRN(int it, ostream &os) {
        if (check(2 * it + 1))
            printLRN(2 * it + 1, os);
        if (check(2 * it + 2))
            printLRN(2 * it + 2, os);
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
    }

    // 4. ЛКП = Левый Корень Правый
    void printLNR(int it, ostream &os) {
        if (check(2 * it + 1))
            printLNR(2 * it + 1, os);
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
        if (check(2 * it + 2))
            printLNR(2 * it + 2, os);
    }

    // 5. ПЛК = Правый Левый Корень
    void printRLN(int it, ostream &os) {
        if (check(2 * it + 2))
            printRLN(2 * it + 2, os);
        if (check(2 * it + 1))
            printRLN(2 * it + 1, os);
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
    }

    // 6. ПКЛ = Правый Корень Левый
    void printRNL(int it, ostream &os) {
        if (check(2 * it + 2))
            printRNL(2 * it + 2, os);
        os << data[it];
        if (check((it - 1) / 2))
            os << "{" << data[(it - 1) / 2] << "} ";
        else
            os << " ";
        if (check(2 * it + 1))
            printRNL(2 * it + 1, os);
    }

    Heap_Array<T> &sub_heap(T v) const;

    void app_child(int it, vector<T> &vec) const;

    bool equal_child(int it1, int it2, const Heap_Array<T> &heap) const;

    bool search_heap(const Heap_Array<T> &heap) const;

    ~Heap_Array<T>() = default;
};

template<class T>
void Heap_Array<T>::insert(T v) {
    if (search(v) >= 0)
        return;
    int i, parent;
    data.emplace_back(v);
    i = data.size() - 1;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if (data[i] > data[parent])
            swap(data[i], data[parent]);
        else
            break;
        check_brother(i);
        i = parent;
        parent = (i - 1) / 2;
    }
    check_brother(i);
    check_brother((i - 1) / 2);
}

template<class T>
int Heap_Array<T>::search(T v, int it) const {
    if (size() == 0)
        return -1;
    if (data[it] == v)
        return it;

    if (2 * it + 1 < data.size() && v <= data[2 * it + 1]) {
        int ans = search(v, 2 * it + 1);
        if (ans > 0)
            return ans;
    }
    if (2 * it + 2 < data.size() && v <= data[2 * it + 2])
        return search(v, 2 * it + 2);
    return -1;
}

template<class T>
void Heap_Array<T>::remove(T v) {
    int it = search(v);
    if (it != -1) {
        data.erase(data.begin() + search(v));
        *this = Heap_Array(data);
    }
    /*
    int it = search(v);
    while (check(2 * it + 1) && check(2 * it + 2))
    {
        swap(heap[it], heap[2 * it + 2]);
        //check_brother((it - 1) / 2);
        it = 2 * it + 2;
    }
    if (check(2 * it + 1))
    {
        swap(heap[2 * it + 1], heap[it]);
        //heap.erase(heap.begin() + 2 * it + 1);
        heap[2 * it + 1] = NULL;
    } else
    {
        check_brother((it - 1) / 2);
        //heap.erase(heap.begin() + it);
        heap[it] = NULL;
    }*/

}


template<class T>
Heap_Array<T> &Heap_Array<T>::sub_heap(T v) const {
    int it = search(v);
    if (it == -1) {
        return *(new Heap_Array<T>());
    }
    vector<T> h;
    app_child(it, h);
    return *(new Heap_Array<T>(h));
}

template<class T>
void Heap_Array<T>::app_child(int it, vector<T> &vec) const {
    vec.template emplace_back(data[it]);
    if (check(2 * it + 1))
        app_child(2 * it + 1, vec);
    if (check(2 * it + 2))
        app_child(2 * it + 2, vec);
}

template<class T>
bool Heap_Array<T>::search_heap(const Heap_Array<T> &heap) const {
    int it = search(heap.data[0]);
    if (it == -1 || heap.data.size() > data.size())
        return false;
    return equal_child(it, 0, heap);
}

template<class T>
bool Heap_Array<T>::equal_child(int it1, int it2, const Heap_Array<T> &heap) const {
    if (check(it1) != heap.check(it2) || data[it1] != heap[it2])
        return false;
    if (!heap.check(2 * it2 + 1) && !heap.check(2 * it2 + 2))
        return true;
    bool ans = false;
    if (check(2 * it1 + 1) && heap.check(2 * it2 + 1))
        ans = equal_child(2 * it1 + 1, 2 * it2 + 1, heap);
    if (!ans)
        return false;
    if (check(2 * it1 + 2) && heap.check(2 * it2 + 2))
        ans = equal_child(2 * it1 + 2, 2 * it2 + 2, heap);
    return ans;
}

template<class T>
void parent_node(const Heap_Array<T> &heap) {
    cout << heap.data[0] << " ";
    for (int i = 1; i < heap.data.size(); i++)
        cout << heap.data[i] << "{" << heap.data[(i - 1) / 2] << "} ";
    cout << "\n";
}