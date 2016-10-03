//
//  main.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include <iostream>
#include "Hashfunctions.cpp"
#include "cityhash/city.h"

void fnvExample(const char* str);
void jenkinsExample(const char* str);
void cityHashExample(const char* str);

int main(int argc, const char * argv[]) {
    fnvExample("abc");
    jenkinsExample("abc");
    cityHashExample("abc");
    return 0;
}

void fnvExample(const char* str) {
    uint64_t hash = fnvHash::hash(str, strlen(str));
    std::cout << "FNV: " << hash << "\n";
}

void jenkinsExample(const char* str) {
    uint64_t hash = jenkinsHash::hash(str, strlen(str));
    std::cout << "Jenkins: " << hash << "\n";
}

void cityHashExample(const char* str) {
    uint64_t hash = cityHash::hash(str, strlen(str));
    std::cout << "Cityhash: " << hash << "\n";
}
