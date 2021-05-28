#pragma once

#include <fstream>
#include <cstdlib>
#include "Set_Node.hpp"

void write_results(pair<int, int> time, const string &file_name, const string &test_name) {
    int node_time = time.first;
    int array_time = time.second;
    ofstream fout(file_name, ios_base::app);
    cout << test_name << endl;
    fout << test_name << endl;
    cout << "Nodes: " << node_time << " microseconds" << endl;
    fout << "Nodes: " << node_time << " microseconds" << endl;
    cout << "Array: " << array_time << " microseconds" << endl;
    fout << "Array: " << array_time << " microseconds" << endl;
    if (node_time >= array_time) {
        cout << "Array is " << node_time / array_time << " times faster than a nodes!" << endl;
        fout << "Array is " << node_time / array_time << " times faster than a nodes!" << endl;
    }
    if (node_time < array_time) {
        cout << "Nodes is " << array_time / node_time << " times faster than a array!" << endl;
        fout << "Nodes is " << array_time / node_time << " times faster than a array!" << endl;
    }
    cout << endl;
    fout << endl;
    fout.close();
}