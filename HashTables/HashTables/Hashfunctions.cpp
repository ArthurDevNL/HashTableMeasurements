//
//  Hashfunctions.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include <iostream>
#include "Hashfunctions.hpp"
#include "cityhash/city.h"

class fnvHash: hashfunction {
public: 
    static uint64_t hash(const char* str, size_t len) {
        // http://isthe.com/chongo/tech/comp/fnv/#FNV-1a, kopje Parameters of the FNV-1/FNV-1a hash
        const uint64_t FNV_PRIME = 1099511628211u;
        const uint64_t OFFSET_BASIS = 14695981039346656037u;
        
        uint64_t hash = OFFSET_BASIS;
        for (size_t i = 0; i < len + 1; ++i)
        {
            hash ^= *str++;
            hash *= FNV_PRIME;
        }
        return hash;
    }
};

/* 
 Moet nog aangepast worden, klopt nog niet helemaal
*/
class jenkinsHash: hashfunction {
public:
    static uint64_t hash(const char* str, size_t len) {
        uint64_t hash, i;
        for(hash = i = 0; i < len; ++i)
        {
            hash += str[i];
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
        return hash;
    }
};

class cityHash: hashfunction {
public:
    static uint64_t hash(const char* str, size_t len) {
//        uint64_t hash;
        return CityHash64(str, len);
    }
};
