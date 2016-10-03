//
//  TestCases.hpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef TestCases_hpp
#define TestCases_hpp

#include <iostream>
#include "HashFunctions.hpp"

class TestCase {
public:
    TestCase(HashFunction* hash_class, const std::string* data, const size_t data_length);
private:
    std::string* data;
    size_t data_length;
};

#endif /* TestCases_hpp */
