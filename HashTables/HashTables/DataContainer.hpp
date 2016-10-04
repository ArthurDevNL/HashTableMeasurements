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
    
    DataContainer(std::string build_path);
    std::string get_base_dir(std::string build_path);
    void get_file_paths(std::string base_dir_path, std::string file_paths[]);
    void read_data(int type, std::string file_path);
    std::string *get_data(int type, int size);

private:
    
    std::string *all_data = new std::string[3 * (int)pow(2, 16)];
    
};

#endif /* DataContainer_hpp */
