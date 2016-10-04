//
//  DataContainer.cpp
//  HashTables
//
//  Created by Joris ten Tusscher on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include "DataContainer.hpp"
#include <fstream>

using namespace std;

DataContainer::DataContainer(string build_path) {
    string base_dir_path = get_base_dir(build_path);
    string file_path[] = {"/datasets/length5.txt", "/datasets/length45.txt", "/datasets/lengthvariable.txt"};
    get_file_paths(base_dir_path, file_path);
    for (int type = five; type <= variable; type++) {
        read_data(type, file_path[type]);
    }
}

string DataContainer::get_base_dir(string build_path) {
    string base_dir = "reimagined-happiness";
    unsigned long base_dir_i = build_path.find(base_dir);
    build_path = build_path.substr(0, base_dir_i + base_dir.length());
    return build_path;
}

void DataContainer::get_file_paths(string base_dir_path, string file_paths[]) {
    for (int i = 0; i < 3; i++) {
        file_paths[i] = base_dir_path + file_paths[i];
    }
}

void DataContainer::read_data(int type, string file_path) {
    ifstream stream(file_path);
    string line;
    int p = (int)pow(2, 16);
    for (int i = type * p; i < (type + 1) * p; i++) {
        getline(stream, line);
        all_data[i] = line;
    }
    stream.close();
}

string *DataContainer::get_data(int type, int size) {
    string *arr = new string[size];
    int min = type * (int)pow(2, 16);
    int max = min + size;
    for (int i = min; i < max; i++) {
        arr[i - min] = all_data[i];
    }
    return arr;
}
