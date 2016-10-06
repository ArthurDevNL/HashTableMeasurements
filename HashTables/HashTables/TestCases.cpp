//
//  TestCases.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include "TestCases.hpp"
#include "HashFunctions.hpp"

using namespace std;

TestCase::TestCase(string* data, const size_t data_size, HashTable* table, uint64_t (*hash_function)(const char* str, size_t len)) {
    this->hash_function = hash_function;
    this->data = data;
    this->table = table;
    this->data_length = data_size;
    this->insertion_steps = new unsigned int[data_size];
    this->lookup_steps = new unsigned int[data_size];
    this->insert_hash_times = new double[data_size];
    this->lookup_hash_times = new double[data_size];
    
    
}

void TestCase::perform_test() {
    fill_table();
    lookup_table();
    
    cout << "Test results: \n";
    cout << "Insertion steps: " << insertion_sum << ", time: " << insertion_time << " s." << endl;
    cout << "Lookup steps: " << lookup_sum << ", time: " << lookup_time << " s." << endl;
    cout << "Collisions (only applicable with chaining): " << collisions << endl;
}

void TestCase::write_results(string location, string hash_type) {
    ofstream f;
    f.open(location.c_str());
    f << "id,table_type,hash_type,insertion_steps,lookup_steps,insertion_hash_times,lookup_hash_times" << endl;
    for(int i = 0; i < data_length; i++) {
        f << i << "," << table->type << "," << hash_type << "," << insertion_steps[i] << "," << lookup_steps[i] << "," << insert_hash_times[i] << "," << lookup_hash_times[i] << endl;
    }
    f.close();
}

uint64_t TestCase::hash(string str) {
    const char* char_string = str.c_str();
    size_t str_len = strlen(char_string);
    return hash_function(char_string, str_len);
}

void TestCase::fill_table() {
    auto all_start = chrono::high_resolution_clock::now();
    
    insertion_sum = 0;
    collisions = 0;
    
    uint64_t* hashes = new uint64_t[data_length];
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        hashes[i] = hash_function(char_string, str_len);
    }
    
    auto all_end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = all_end - all_start;
    
    insertion_hash_time = diff.count();
    
    auto ins_start = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < data_length; i++) {
        int steps = table->insert(data[i], hashes[i]);
        
        insertion_steps[i] = steps;
        insertion_sum += steps;
        
        if (insertion_steps[i] > 0)
            collisions++;
    }
    
    auto ins_end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> ins_diff = ins_end - ins_start;
    
    insertion_time = ins_diff.count();
}

void TestCase::lookup_table() {
    auto all_start = chrono::high_resolution_clock::now();
    
    lookup_sum = 0;
    
    uint64_t* hashes = new uint64_t[data_length];
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        hashes[i] = hash_function(char_string, str_len);
    }
    
    auto all_end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = all_end - all_start;
    
    lookup_hash_time = diff.count();
    
    auto lk_start = chrono::high_resolution_clock::now();
    
    for(int i = 0; i < data_length; i++) {
        int steps = table->lookup(data[i], hashes[i]);
        
        lookup_steps[i] = steps;
        lookup_sum += steps;
    }
    
    auto lk_end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> lk_diff = lk_end - lk_start;
    
    lookup_time = lk_diff.count();
    
    /*
    
    auto all_start = chrono::high_resolution_clock::now();
    
    lookup_sum = 0;
    
    for (int i = 0; i < data_length; i++) {
        const char* char_string = data[i].c_str();
        size_t str_len = strlen(char_string);
        uint64_t hash = hash_function(char_string, str_len);
        
//        auto end = chrono::high_resolution_clock::now();
//        
//        chrono::duration<double> diff = end - start;
//        
//        lookup_hash_times[i] = diff.count();
        
        lookup_steps[i] = table->lookup(data[i], hash);
        lookup_sum += lookup_steps[i];
    }
    
    auto all_end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> diff = all_end - all_start;
    
    lookup_time = diff.count();*/
}
