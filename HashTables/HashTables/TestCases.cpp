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
}

void TestCase::perform_test() {
//    std::string str = "abc";
//    uint64_t hash = this->hash(str);
//    int insert_steps = table->insert(str, hash);
//    int lookup_steps = table->lookup(str, hash);
//    cout << "Insert steps: " << insert_steps << ", lookup steps: " << lookup_steps << "\n";
    fill_table();
    lookup_table();
    cout << "Test results: \n";
    cout << "Insertion steps: " << insertion_steps << ", time: " << insertion_time << " s. \n";
    cout << "Lookup steps: " << lookup_steps << ", time: " << lookup_time << " s. \n";
}

uint64_t TestCase::hash(string str) {
    const char* char_string = str.c_str();
    size_t str_len = strlen(char_string);
    return hash_function(char_string, str_len);
}

void TestCase::fill_table() {
    auto start = chrono::high_resolution_clock::now();
    
    insertion_steps = 0;
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        uint64_t hash = hash_function(char_string, str_len);
        insertion_steps += table->insert(data[i], hash);
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
        uint64_t hash = hash_function(char_string, str_len);
        lookup_steps += table->lookup(data[i], hash);
    }
    
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = end - start;
    
    lookup_time = diff.count();
}
