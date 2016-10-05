//
//  HashTable.hpp
//  HashTables
//
//  Created by Joris ten Tusscher on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <iostream>
#include "HashFunctions.hpp"

class HashTable {
public:
    enum hashtable_type { chaining, open_addressing };
    
    HashTable(int _type, int _datasize, double _load_factor);
    
    hashtable_type type;
    int data_size;
    double load_factor;
    uint64_t hash(const char* str);
    
    std::string* hashtable;
    int hashtable_size;
    
    virtual int insert(std::string value, uint64_t hash) = 0;
    virtual std::tuple<std::string, int> lookup(std::string value, uint64_t hash) = 0;
};



class OpenAddressingHashTable: public HashTable {
public:
    std::string* hashtable;
    int insert(std::string value, uint64_t hash) override;
    std::tuple<std::string, int> lookup(std::string value, uint64_t hash) override;
    OpenAddressingHashTable(int _type, int _datasize, double _load_factor);
};


struct Node {
public:
    Node();
    Node(std::string value);
    std::string value;
    Node* next;
};

class ChainingHashTable: public HashTable {
public:
    Node* hashtable;
    int insert(std::string value, uint64_t hash) override;
    std::tuple<std::string, int> lookup(std::string value, uint64_t hash) override;
    ChainingHashTable(int _type, int _datasize, double _load_factor);
};


#endif /* HashTable_hpp */
