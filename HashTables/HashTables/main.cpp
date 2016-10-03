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

#include "Hashfunctions.cpp"
#include "cityhash/city.h"
#include "DataContainer.hpp"
#include "HashTable.cpp"

using namespace std;

void fnvExample(const char* str);
void jenkinsExample(const char* str);
void cityHashExample(const char* str);

void fnvExample(const char* str) {
    uint64_t hash = fnvHash::hash(str, strlen(str));
    std::cout << "FNV: " << hash << "\n";
}

void jenkinsExample(const char* str) {
    uint64_t hash = jenkinsHash::hash(str, strlen(str));
    std::cout << "Jenkins: " << hash << "\n";
}

void cityHashExample(const char* str) {
    uint64_t hash = cityHash::hash(str, strlen(str));
    std::cout << "Cityhash: " << hash << "\n";
}

string *test() {
    string *arr = new string[5];
    return arr;
}

int main(int argc, const char * argv[]) {
    
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
    
    fnvExample("abc");
    jenkinsExample("abc");
    cityHashExample("abc");
    
    return 0;
    
}

    
    
    /*
    verschillende datasets
        verschillende sizes
            verschillende tabletypes (open addressing en chaining)
                verschillende loadfactors
                    verschillende hashfuncties
    */

