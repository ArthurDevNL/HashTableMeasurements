//
//  HashTable.hpp
//  HashTables
//
//  Created by Joris ten Tusscher on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <iostream>

#endif /* HashTable_hpp */

class HashTable {
    
public:
    
    enum hashtable_type { chaining, open_addressing };
    
    HashTable(int type, std::string *data);
    //std::string getBaseDir(std::string buildpath);
    //void getFilePaths(std::string basedirpath, std::string filepaths[]);
    //void readData(int type, std::string filepath);
    
//private:
    
    //std::string *data;
    
};
