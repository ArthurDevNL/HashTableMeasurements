//
//  Hashfunctions.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef _HASHFUNCTION_INCLUDED_
#define _HASHFUNCTION_INCLUDED_

#include "HashFunctions.hpp"
#include "cityhash/city.h"

class fnv_hash: HashFunction {
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
class jenkins_hash: HashFunction {
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

class city_hash: HashFunction {
public:
    static uint64_t hash(const char* str, size_t len) {
        return CityHash64(str, len);
    }
};

class murmur_hash: HashFunction {
public:
    static uint64_t hash(const char* str, size_t len) {
        //-----------------------------------------------------------------------------
        // MurmurHash2, 64-bit versions, by Austin Appleby
        
        // The same caveats as 32-bit MurmurHash2 apply here - beware of alignment
        // and endian-ness issues if used across multiple platforms.
        
        // 64-bit hash for 64-bit platforms
        
        // Seed generated on random.org
        uint64_t seed = 0xe8ba7eea39cc08a3;
        
        const uint64_t m = 0xc6a4a7935bd1e995;
        const int r = 47;
        
        uint64_t h = seed ^ (len * m);
        
        const uint64_t * data = (const uint64_t *)str;
        const uint64_t * end = data + (len/8);
        
        while(data != end)
        {
            uint64_t k = *data++;
            
            k *= m;
            k ^= k >> r;
            k *= m;
            
            h ^= k;
            h *= m;
        }
        
        const unsigned char * data2 = (const unsigned char*)data;
        
        switch(len & 7)
        {
            case 7: h ^= uint64_t(data2[6]) << 48;
            case 6: h ^= uint64_t(data2[5]) << 40;
            case 5: h ^= uint64_t(data2[4]) << 32;
            case 4: h ^= uint64_t(data2[3]) << 24;
            case 3: h ^= uint64_t(data2[2]) << 16;
            case 2: h ^= uint64_t(data2[1]) << 8;
            case 1: h ^= uint64_t(data2[0]);
                h *= m;
        };
        
        h ^= h >> r;
        h *= m;
        h ^= h >> r;
        
        return h;
    }
};

#endif
