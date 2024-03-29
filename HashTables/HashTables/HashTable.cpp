//
//  HashTable.cpp
//  HashTables
//
//  Created by Joris ten Tusscher on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include "HashTable.hpp"

using namespace std;

HashTable::HashTable(int _type, int _datasize, double _load_factor) {
    type = static_cast<hashtable_type>(_type);
    data_size = _datasize;
    load_factor = _load_factor;
    hashtable_size = (int)(data_size / load_factor);
}

OpenAddressingHashTable::OpenAddressingHashTable(int _type, int _datasize, double _load_factor) : HashTable(_type, _datasize, _load_factor) {
    hashtable = new string[hashtable_size];
}
int OpenAddressingHashTable::insert(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    int iterations = 0;
    while (hashtable[i] != "") {
        iterations++;
        i = (i + 1) % hashtable_size;
    }
    hashtable[i] = value;
    return iterations;
}

int OpenAddressingHashTable::lookup(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    int iterations = 0;
    while (hashtable[i] != value) {
        iterations++;
        i = (i + 1) % hashtable_size;
    }
    return iterations;
}



Node::Node(string _value) {
    value = _value;
    next = nullptr;
}
Node::Node() {
    value = "";
    next = nullptr;
}



ChainingHashTable::ChainingHashTable(int _type, int _datasize, double _load_factor) : HashTable(_type, _datasize, _load_factor) {
    hashtable = new Node[hashtable_size];
}

int ChainingHashTable::insert(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    
    Node* current_node = &hashtable[i];
    if (current_node->value == "") {
        current_node->value = value;
        return 0;
    }
    else {
        Node *new_node = (Node*)calloc(1, sizeof(Node));
        
        new_node->value = value;
        new_node->next = nullptr;
        int loops = 1;
        
        while(current_node->next != nullptr) {
            loops++;
            current_node = current_node->next;
        }
        
        // Found the last element without pointer to next element
        current_node->next = new_node;
        
        return loops;
    }
}

int ChainingHashTable::lookup(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    int list_size = 0;
    Node current_node = hashtable[i];
    while (current_node.next != nullptr && current_node.value != value) {
        list_size++;
        current_node = *current_node.next;
    }
    return list_size;
}
