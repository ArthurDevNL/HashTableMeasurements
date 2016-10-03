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

DataContainer::DataContainer(string buildpath) {
    string basedirpath = getBaseDir(buildpath);
    string filepaths[] = {"/datasets/length5.txt", "/datasets/length45.txt", "/datasets/lengthvariable.txt"};
    getFilePaths(basedirpath, filepaths);
    for (int type = five; type <= variable; type++) {
        readData(type, filepaths[type]);
    }
}

string DataContainer::getBaseDir(string buildpath) {
    string base_dir = "reimagined-happiness";
    unsigned long base_dir_i = buildpath.find(base_dir);
    buildpath = buildpath.substr(0, base_dir_i + base_dir.length());
    return buildpath;
}

void DataContainer::getFilePaths(string basedirpath, string filepaths[]) {
    for (int i = 0; i < 3; i++) {
        filepaths[i] = basedirpath + filepaths[i];
    }
}

void DataContainer::readData(int type, string filepath) {
    ifstream stream(filepath);
    string line;
    
    int p = (int)pow(2, 16);
    
    for (int i = type * p; i < (type + 1) * p; i++) {
        getline(stream, line);
        alldata[i] = line;
    }
    stream.close();
}

string *DataContainer::getData(int type, int size) {
    string *arr = new string[size];
    int min = type * (int)pow(2, 16);
    int max = min + size;
    for (int i = min; i < max; i++) {
        arr[i - min] = alldata[i];
    }
    return arr;
}
