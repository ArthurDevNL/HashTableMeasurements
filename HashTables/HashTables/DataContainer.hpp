//
//  DataContainer.hpp
//  HashTables
//
//  Created by Joris ten Tusscher on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#ifndef DataContainer_hpp
#define DataContainer_hpp

#include <iostream>
#include <math.h>

class DataContainer {
    
public:
    
    enum dataset_type { five, fourtyfive, variable };
    
    DataContainer(std::string buildpath);
    std::string getBaseDir(std::string buildpath);
    void getFilePaths(std::string basedirpath, std::string filepaths[]);
    void readData(int type, std::string filepath);
    std::string *getData(int type, int size);

private:
    
    std::string *alldata = new std::string[3 * (int)pow(2, 16)];
    
};

#endif /* DataContainer_hpp */
