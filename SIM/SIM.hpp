//
//  SIM.hpp
//  SIM
//
//  Created by Marwan Awad on 11/1/20.
//  Copyright © 2020 Marwan Awad. All rights reserved.
//

#ifndef SIM_hpp
#define SIM_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class SIM{
public:
    SIM(string[], int[]);
    ~SIM();
    
    void setInstrLine(int);
    
    void selectInst(int);
    void extractData();
    
    string getInstMem(int);
    int getDataMem(int);
    
private:
    string instrLine;
    string instMem[1024];
    int dataMem[1024];
    int d1, d2, d3;

};
#endif /* SIM_hpp */
