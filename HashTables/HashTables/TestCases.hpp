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
    TestCase(std::string* data, const size_t data_size, HashTable* table, uint64_t (*hash_function)(const char* str, size_t len));
    
    void perform_test();
    uint64_t test_hash(std::string* str);
    
    // Test results
    unsigned int insertion_steps;
    double insertion_time;
    
    unsigned int lookup_steps;
    double lookup_time;
private:
    std::string* data;
    size_t data_length;
    uint64_t (*hash_function)(const char* str, size_t len);
    HashTable* table;
    
    // Benchmarking functions
    void fill_table();
    void lookup_table();
};

#endif /* TestCases_hpp */
