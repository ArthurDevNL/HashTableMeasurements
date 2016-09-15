#!/usr/bin/env python
# Source: http://www.saschaschnepp.net/2013/12/01/python_hashtable/

import sys

class Item:
    key = None
    value = None

    def __init__(self, key, value):
        self.key = key
        self.value = value

class ChainedHashTable:
    'Common base class for a hash table'
    tableSize    = 0
    entriesCount = 0
    alphabetSize = 2*26
    hashTable    = []
     
    # Public functions
    def __init__(self, size, hash_function):
        self.tableSize = size
        self.hashTable = [[] for i in range(size)]
        self.hash_function = hash_function

    # Inserts a given item
    def insert(self, key, value):
        hash = self.hash_function(self.tableSize, key)
        
        for i, it in enumerate(self.hashTable[hash]):
            if it.key == key:
                del self.hashTable[hash][i]
                self.entriesCount -= 1

        item = Item(key, value)
        self.hashTable[hash].append(item)
        self.entriesCount += 1

    # Returns the full item
    def get(self, key):
        hash = self.hashing(self.tableSize, key)
        for i, it in enumerate(self.hashTable[hash]):
            if it.key == key:
                return self.hashTable[hash]
        return None

    # Deletes the given key from the hash table
    def delete(self, key):
        hash = self.hash_function(self.tableSize, key)

        for i, it in enumerate(self.hashTable[hash]):
            if it.key == key:
                del self.hashTable[hash][i]
                self.entriesCount -= 1
                return

# ******* HASH FUNCTIONS *******
def simple_hash(table_size, key):
    hash = 0
    for i,c in enumerate ( key ):
        hash += pow(2*26, len(key)-i-1) * ord(c)
    return hash % table_size


# Example code
hash_table = ChainedHashTable(100, simple_hash)
hash_table.insert("test", "val")







