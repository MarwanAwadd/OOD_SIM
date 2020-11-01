//
//  main.cpp
//  SIM
//
//  Created by Marwan Awad on 11/1/20.
//  Copyright © 2020 Marwan Awad. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "SIM.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string instruction;
    int i = 0;
    string instMem [1024];
    int dataMem [1024];
    ifstream myfile1 ("Test2.txt");
    if(myfile1.is_open()){
        while ( getline(myfile1, instMem[i]) )
        {
            cout << instMem[i] << endl;
            i++;
        }
        myfile1.close();
    }
    else cout << "Unable to open file" << endl;
    
    SIM s (instMem, dataMem);
    s.selectInst(i);
    return 0;
}
