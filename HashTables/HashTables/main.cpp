//
//  main.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>

#include "Hashfunctions.hpp"
#include "Hashfunctions.cpp"
#include "TestCases.hpp"

enum collision_resolve_type { chaining, open_addressing };

using namespace std;

string getBaseDir(string buildpath) {
    string base_dir = "reimagined-happiness";
    unsigned long base_dir_i = buildpath.find(base_dir);
    buildpath = buildpath.substr(0, base_dir_i + base_dir.length());
    return buildpath;
}

void getFilePaths(string basedirpath, string filepaths[]) {
    for (int i = 0; i < 3; i++) {
        filepaths[i] = basedirpath + filepaths[i];
    }
}

string *getData(string filepath, string dataset[]) {
    ifstream stream(filepath);
    string line;
    for (int i = 0; i < (int(pow(2, 16))); i++) {
        getline(stream, line);
        dataset[i] = line;
    }
    stream.close();
    return dataset;
}

void fnv_example(const char* str);
void jenkins_example(const char* str);
void city_hash_example(const char* str);

void fnv_example(const char* str) {
    uint64_t hash = fnv_hash::hash(str, strlen(str));
    std::cout << "FNV: " << hash << "\n";
}

void jenkins_example(const char* str) {
    uint64_t hash = jenkins_hash::hash(str, strlen(str));
    std::cout << "Jenkins: " << hash << "\n";
}

void city_hash_example(const char* str) {
    uint64_t hash = city_hash::hash(str, strlen(str));
    std::cout << "Cityhash: " << hash << "\n";
}

void murmurExample(const char* str) {
    uint64_t hash = murmur_hash::hash(str, strlen(str));
    std::cout << "MurMurHash: " << hash << "\n";
}

int main(int argc, const char * argv[]) {
    
    /*string basedirpath = getBaseDir(*argv);
    string filepaths[] = {"/datasets/length5.txt", "/datasets/length45.txt", "/datasets/lengthvariable.txt"};
    getFilePaths(basedirpath, filepaths);
    
    for (int filenr = 0; filenr < 3; filenr++) {
        string *dataset = new string[(int)pow(2, 16)];
        getData(filepaths[filenr], dataset);
        
        int sizes[] = {(int)pow(2, 8), (int)pow(2, 12), (int)pow(2, 16)};
        for (int sizenr = 0; sizenr < 3; sizenr++) {
            int size = sizes[sizenr];
            
            for (int table_type = chaining; table_type != open_addressing; table_type++) {
                
            }
            
            int *hashtable = new int[size];
            
        }
        
    }*/
    
    fnv_example("abc");
    jenkins_example("abc");
    city_hash_example("abc");
    murmurExample("abc");
    
    return 0;
    
}

    
    
    /*
    verschillende datasets
        verschillende sizes
            verschillende tabletypes (open addressing en chaining)
                verschillende loadfactors
                    verschillende hashfuncties
    */

