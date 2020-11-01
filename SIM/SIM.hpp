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
#include <fstream>
using namespace std;

class SIM{
public:
    SIM(string);
    ~SIM();
    
    void setInstrLine(int);
    
    void selectInst();
    void extractData();
    
private:
    string instrLine;
    string instMem[1024];
    int dataMem[1024];
    int d1, d2, d3;
    int max;

};
#endif /* SIM_hpp */
