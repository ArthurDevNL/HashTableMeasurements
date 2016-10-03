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
    int datasize;
    double load_factor;
    uint64_t hash(const char* str);
    
    std::string* hashtable;
    int hashtable_size;
    
    int insert(std::string value, uint64_t hash);
    
private:
    uint64_t (*hash_func)(const char* str, size_t len);
};



class OpenAddressingHashTable: HashTable {
public:
    std::string* hashtable;
    int insert(std::string value, uint64_t hash);
    OpenAddressingHashTable(int _type, int _datasize, double _load_factor);
};


struct Node {
public:
    std::string value;
    Node* next;
};
class ChainingHashTable: HashTable {
public:
    Node* hashtable;
    int insert(std::string value, uint64_t hash);
    ChainingHashTable(int _type, int _datasize, double _load_factor);
};


#endif /* HashTable_hpp */
