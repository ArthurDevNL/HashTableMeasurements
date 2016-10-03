//
//  Hashfunctions.hpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef Hashfunctions_hpp
#define Hashfunctions_hpp

#include <stdio.h>

#endif /* Hashfunctions_hpp */

class hashfunction {
public:
    static uint64_t hash(const char* str, size_t len);
};
