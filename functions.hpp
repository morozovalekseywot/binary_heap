#pragma once

#include <fstream>
#include <cstdlib>
#include "Set_Node.hpp"
#include <iomanip>

void write_results(const vector<long long> &time, const string &file_name, const string &test_name)
{
    int node_time = time[0];
    int array_time = time[1];
    int vector_time = time[2];

    ofstream fout(file_name, ios_base::app);
    cout << test_name << endl;
    fout << test_name << endl;
    cout << "Nodes: " << node_time << " microseconds" << endl;
    fout << "Nodes: " << node_time << " microseconds" << endl;
    cout << "Array: " << array_time << " microseconds" << endl;
    fout << "Array: " << array_time << " microseconds" << endl;
    cout << "Vector: " << vector_time << " microseconds" << endl;
    fout << "Vector: " << vector_time << " microseconds" << endl;
    cout<<endl;
    fout<<endl;
    if (node_time >= array_time)
    {
        cout << "Array is " << fixed << setprecision(1) << static_cast<long double>(node_time) / array_time << " times faster than a nodes!" << endl;
        fout << "Array is " << fixed << setprecision(1) << static_cast<long double>(node_time) / array_time << " times faster than a nodes!" << endl;
    }
    if (node_time < array_time)
    {
        cout << "Nodes is " << fixed << setprecision(1) << static_cast<long double>(array_time) / node_time << " times faster than an array!" << endl;
        fout << "Nodes is " << fixed << setprecision(1) << static_cast<long double>(array_time) / node_time << " times faster than an array!" << endl;
    }
    // сравнение с вектором
    if (vector_time < node_time)
    {
        cout << "Vector is " << fixed << setprecision(1) << static_cast<long double>(node_time) / vector_time << " times faster than a nodes!" << endl;
        fout << "Vector is " << fixed << setprecision(1) << static_cast<long double>(node_time) / vector_time << " times faster than a nodes!" << endl;
    } else
    {
        cout << "Nodes is " << fixed << setprecision(1) << static_cast<long double>(vector_time) / node_time << " times faster than a Vector!" << endl;
        fout << "Nodes is " << fixed << setprecision(1) << static_cast<long double>(vector_time) / node_time << " times faster than a Vector!" << endl;
    }
    if (vector_time < array_time)
    {
        cout << "Vector is " << fixed << setprecision(1) << static_cast<long double>(array_time) / vector_time << " times faster than an array!" << endl;
        fout << "Vector is " << fixed << setprecision(1) << static_cast<long double>(array_time) / vector_time << " times faster than an array!" << endl;
    } else
    {
        cout << "Array is " << fixed << setprecision(1) << static_cast<long double>(vector_time) / array_time << " times faster than a Vector!" << endl;
        fout << "Array is " << fixed << setprecision(1) << static_cast<long double>(vector_time) / array_time << " times faster than a Vector!" << endl;
    }
    cout << endl;
    fout << endl;
    fout.close();
}