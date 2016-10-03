//
//  TestCases.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "TestCases.hpp"
#include "HashFunctions.hpp"

using namespace std;

TestCase::TestCase(HashFunction* hash_class, std::string* data, const size_t data_size, HashTable* table) {
    this->hash_class = hash_class;
    this->data = data;
    this->data_length = data_size;
    this->table = table;
}

void TestCase::perform_test() {
    fill_table();
}

void TestCase::fill_table() {
    auto start = chrono::high_resolution_clock::now();
    
    insertion_steps = 0;
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        //uint64_t hash = this->hash_class->hash(char_string, str_len);
        // insertion_steps += table.insert(data[i], hash);
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    
    insertion_time = diff.count();
}

void TestCase::lookup_table() {
    auto start = chrono::high_resolution_clock::now();
    
    lookup_steps = 0;
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        //uint64_t hash = this->hash_class->hash(char_string, str_len);
        // lookup_steps += table.lookup(data[i], hash);
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    
    insertion_time = diff.count();
}
