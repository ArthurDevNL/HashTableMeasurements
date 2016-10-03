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
#include "DataContainer.hpp"

using namespace std;

void fnvExample(const char* str);
void jenkinsExample(const char* str);
void cityHashExample(const char* str);

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
    
    //TestCase testcase = TestCase(nullptr, 0, nullptr, murmur_hash::hash);
    
    DataContainer container = DataContainer(*argv);
    
    for (int data_type = DataContainer::five; data_type < DataContainer::variable; data_type++) {
        for (int size_nr = 0; size_nr < 3; size_nr++) {
            int size = (int)pow(2, 8 + 4 * size_nr); // either 2^8, 2^12 or 2^16
            string *data = container.getData(data_type, size);
            //for (int table_type = HashTable::chaining; table_type != HashTable::open_addressing; table_type++) {
                //HashTable table = HashTable(table_type, data);
                //for (int load_factor)
            //}
        }
    }
    
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

