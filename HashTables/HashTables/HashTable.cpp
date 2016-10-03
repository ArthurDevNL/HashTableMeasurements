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


ChainingHashTable::ChainingHashTable(int _type, int _datasize, double _load_factor) : HashTable(_type, _datasize, _load_factor) {
    hashtable = new Node[hashtable_size];
    //for (int i = 0; i < hashtable_size; i++) {
    //    hashtable[i] = nullptr;
    //}
    
    for (int i = 0; i < 256; i++) {
        cout << (&hashtable[i] == NULL) << endl;
    }
}
