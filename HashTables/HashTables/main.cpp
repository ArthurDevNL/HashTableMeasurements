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
#include "HashTable.hpp"
#include "TestCases.hpp"
#include "DataContainer.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ChainingHashTable table = ChainingHashTable(0, 64, 0.5);
    
    string* testStrings = new string[5] { "abc", "def", "ghi", "jkl", "mno" };
    
    TestCase testcase = TestCase(testStrings, 5, &table, murmur_hash::hash);
    testcase.perform_test();
    
    DataContainer container = DataContainer(*argv);
    
    for (int data_type = DataContainer::five; data_type <= DataContainer::variable; data_type++) {
        for (int size_nr = 0; size_nr < 3; size_nr++) {
            int size = (int)pow(2, 8 + 4 * size_nr); // either 2^8, 2^12 or 2^16
            string *data = container.getData(data_type, size);
            for (int table_type = HashTable::chaining; table_type <= HashTable::open_addressing; table_type++) {
                double max_loadfactor = table_type == HashTable::chaining ? 1.5 : 1.0;
                for (double load_factor = 0.5; load_factor <= max_loadfactor; load_factor+=0.5) {
                    //HashTable table = HashTable(table_type, data, size, load_factor, fnv_hash().hash);
                    ChainingHashTable table = ChainingHashTable(table_type, size, load_factor);
                }
            }
        }
    }
    
    return 0;
    
}

    
    
    /*
    verschillende datasets
        verschillende sizes
            verschillende tabletypes (open addressing en chaining)
                verschillende loadfactors
                    verschillende hashfuncties
    */

