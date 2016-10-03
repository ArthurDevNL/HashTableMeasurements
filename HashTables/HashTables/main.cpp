//
//  main.cpp
//  HashTables
//
//  Created by Gert-Jan van Ginkel on 03/10/16.
//  Copyright © 2016 Gert-Jan van Ginkel. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>

enum collision_resolve_type { chaining, open_addressing };

using namespace std;

string getBaseDir(string buildpath) {
    string base_dir = "reimagined-happiness";
    unsigned long base_dir_i = buildpath.find(base_dir);
    buildpath = buildpath.substr(0, base_dir_i + base_dir.length());
    return buildpath;
}

void getFilePaths(string basedirpath, string filepaths[]) {
    for (int i = 0; i < 3; i++) {
        filepaths[i] = basedirpath + filepaths[i];
    }
}

string *getData(string filepath, string dataset[]) {
    ifstream stream(filepath);
    string line;
    for (int i = 0; i < (int(pow(2, 16))); i++) {
        getline(stream, line);
        dataset[i] = line;
    }
    stream.close();
    return dataset;
}

int main(int argc, const char * argv[]) {
    
    string basedirpath = getBaseDir(*argv);
    string filepaths[] = {"/datasets/length5.txt", "/datasets/length45.txt", "/datasets/lengthvariable.txt"};
    getFilePaths(basedirpath, filepaths);
    
    for (int filenr = 0; filenr < 3; filenr++) {
        string *dataset = new string[(int)pow(2, 16)];
        getData(filepaths[filenr], dataset);
        
        int sizes[] = {(int)pow(2, 8), (int)pow(2, 12), (int)pow(2, 16)};
        for (int sizenr = 0; sizenr < 3; sizenr++) {
            int size = sizes[sizenr];
            
            for (int table_type = chaining; table_type != open_addressing; table_type++) {
                
            }
            
            int *hashtable = new int[size];
            
        }
        
    }
    
    
    
    
    
    
    /*
    verschillende datasets
        verschillende sizes
            verschillende tabletypes (open addressing en chaining)
                verschillende loadfactors
                    verschillende hashfuncties
    */
     
    return 0;
}
