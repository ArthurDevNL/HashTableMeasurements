//
//  TestCases.hpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef TestCases_hpp
#define TestCases_hpp

#include <iostream>
#include "HashFunctions.hpp"
#include "HashTable.hpp"

class TestCase {
public:
    TestCase(HashFunction* hash_class, std::string* data, const size_t data_size, HashTable* table);
    void perform_test();
    
    // Test results
    unsigned int insertion_steps;
    double insertion_time;
    
    unsigned int lookup_steps;
    double lookup_time;
private:
    std::string* data;
    size_t data_length;
    HashFunction* hash_class;
    HashTable* table;
    
    // Benchmarking functions
    void fill_table();
    void lookup_table();
};

#endif /* TestCases_hpp */
