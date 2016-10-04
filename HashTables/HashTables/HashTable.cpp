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
    datasize = _datasize;
    load_factor = _load_factor;
    hashtable_size = (int)(datasize / load_factor);
}

OpenAddressingHashTable::OpenAddressingHashTable(int _type, int _datasize, double _load_factor) : HashTable(_type, _datasize, _load_factor) {
    hashtable = new string[hashtable_size];
}
int OpenAddressingHashTable::insert(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    int collision_count = 0;
    while (hashtable[i] != "") {
        collision_count++;
        i = (i + 1) % hashtable_size;
    }
    hashtable[i] = value;
    return collision_count;
}

int OpenAddressingHashTable::lookup(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    int collision_count = 0;
    while (hashtable[i] != "" && hashtable[i] != value) {
        collision_count++;
        i = (i + 1) % hashtable_size;
    }
    return collision_count;
}


ChainingHashTable::ChainingHashTable(int _type, int _datasize, double _load_factor) : HashTable(_type, _datasize, _load_factor) {
    hashtable = new Node[hashtable_size];
}

int ChainingHashTable::insert(string value, uint64_t hash) {
    Node n = Node();
    n.value = value;
    int i = (int)(hash % hashtable_size);
    int list_size = 1; // Voor het geval er gelijk plaats is, aantal iterations op 0 terwijl je wel insert is raar
    if (hashtable[i].value == "") {
        hashtable[i] = n;
    }
    else {
        Node current_node = hashtable[i];
        list_size++;
        while (current_node.next != NULL) {
            list_size++;
            current_node = *current_node.next;
        }
        current_node.next = &n;
    }
    return list_size;
}

int ChainingHashTable::lookup(string value, uint64_t hash) {
    int i = (int)(hash % hashtable_size);
    int list_size = 0;
    
    Node current_node = hashtable[i];
    list_size++;
    while (current_node.next != NULL && current_node.value != value) {
        list_size++;
        current_node = *current_node.next;
    }
    
    return list_size;
}
