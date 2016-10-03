//
//  HashFunctions.hpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef HashFunctions_h
#define HashFunctions_h

#include <iostream>

class HashFunction {
public:
    static uint64_t hash(const char* str, size_t len);
};

#endif /* HashFunctions_h */
