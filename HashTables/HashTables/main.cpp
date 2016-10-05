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

typedef uint64_t (*hash_function)(const char* str, size_t len);

int main(int argc, const char * argv[]) {
    
    DataContainer container = DataContainer(*argv);
    
    for (int data_type = DataContainer::five; data_type <= DataContainer::variable; data_type++) {
        for (int size_nr = 0; size_nr < 3; size_nr++) {
            int size = (int)pow(2, 8 + 4 * size_nr); // either 2^8, 2^12 or 2^16
            for (int table_type = HashTable::chaining; table_type <= HashTable::open_addressing; table_type++) {
                double max_loadfactor = table_type == HashTable::chaining ? 1.5 : 1.0;
                for (double load_factor = 0.5; load_factor <= max_loadfactor; load_factor+=0.5) {
                    hash_function functions[4] = { murmur_hash::hash, fnv_hash::hash, city_hash::hash, jenkins_hash::hash };
                    string function_names[4] = { "murmur", "fnv", "city", "jenkings" };
                    for (int function_nr = 0; function_nr < 4; function_nr++) {
                        HashTable *table;
                        if (table_type == HashTable::chaining) {
                            ChainingHashTable cht = ChainingHashTable(table_type, size, load_factor);
                            table = &cht;
                        }
                        else {
                            OpenAddressingHashTable oaht = OpenAddressingHashTable(table_type, size, load_factor);
                            table = &oaht;
                        }
                        string *data = container.get_data(data_type, size);
                        cout << "+----------------------------+" << endl;
                        cout << "Hash function: " << function_names[function_nr] << endl;
                        auto test = TestCase(data, size, table, functions[function_nr]);
                        test.perform_test();
                        string f_name = "data" + to_string(data_type) + "_size" + to_string(size_nr) + "_tablechaining_loadfactor" + to_string(load_factor) + "_hash" + function_names[function_nr] + ".csv";
                        test.write_results(f_name, function_names[function_nr]);
                    }
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

