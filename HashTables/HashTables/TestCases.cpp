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

TestCase::TestCase(string* data, const size_t data_size, HashTable* table, uint64_t (*hash_function)(const char* str, size_t len)) {
    this->hash_function = hash_function;
    this->data = data;
    this->data_length = data_size;
    this->table = table;
    this->insertion_steps = new unsigned int[data_size];
    this->lookup_steps = new unsigned int[data_size];
}

void TestCase::perform_test() {
    fill_table();
    lookup_table();
    
    cout << "Test results: \n";
    cout << "Insertion steps: " << lookup_sum << ", time: " << insertion_time << " s." << endl;
    cout << "Lookup steps: " << lookup_sum << ", time: " << lookup_time << " s." << endl;
}

uint64_t TestCase::hash(string str) {
    const char* char_string = str.c_str();
    size_t str_len = strlen(char_string);
    return hash_function(char_string, str_len);
}

void TestCase::fill_table() {
    insertion_sum = 0;
    
    for (int i = 0; i < data_length; i++) {
        auto start = chrono::high_resolution_clock::now();
        
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        uint64_t hash = hash_function(char_string, str_len);
        
        auto end = chrono::high_resolution_clock::now();
        
        chrono::duration<double> diff = end - start;
        
        insert_hash_times[i] = diff.count();
        
        insertion_steps[i] = table->insert(data[i], hash);
        insertion_sum += insertion_steps[i];
        
        if (insertion_steps[i] > 1)
            collisions++;
        
    }
}

void TestCase::lookup_table() {
    auto start = chrono::high_resolution_clock::now();
    
    lookup_sum = 0;
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        uint64_t hash = hash_function(char_string, str_len);
        
        lookup_steps[i] = table->lookup(data[i], hash);
        lookup_sum += lookup_steps[i];
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    
    lookup_time = diff.count();
}
