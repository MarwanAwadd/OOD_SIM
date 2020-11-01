//
//  SIM.cpp
//  SIM
//
//  Created by Marwan Awad on 11/1/20.
//  Copyright © 2020 Marwan Awad. All rights reserved.
//

#include "SIM.hpp"
//Constructor: Sets current instruction to empty. Sets instruction memory array values to empty. Sets data memory array values to 0.
SIM::SIM(string newInstMem[], int newDataMem[]){
    instrLine = "";
    for(int i = 0; i < 1024; i++)
        instMem[i] = newInstMem[i];
    for(int i = 0; i < 1024; i++)
        dataMem[i] = 0;
}

SIM::~SIM(){
}

void SIM::setInstrLine(int i){
    instrLine = instMem[i];
}

void SIM::selectInst(int max){
    for(int i = 0; i < max; i++){
        setInstrLine(i);
        string instr = instrLine.substr(0,3);
        d1 = 0;
        d2 = 0;
        d3 = 0;
        extractData();
        if(instr == "ADD"){
            cout << "#The SIM added memory address " << d1 << " with value " << dataMem[d1] << " to memory address " << d2 << " with value " << dataMem[d2] << " and stored the result ";
            dataMem[d3] = dataMem[d1] + dataMem[d2];
            cout << dataMem[d3] << " in memory address " << d3 << "." << endl;
        }
        else if(instr == "NEG"){
            cout << "#The SIM inversed the sign in memory address " << d1 << " with value " << dataMem[d1] << " in memory address " << d2 << " which is now ";
            dataMem[d2] = -(dataMem[d1]);
            cout << dataMem[d2] << "." << endl;
        }
        else if(instr == "MUL"){
            cout << "#The SIM multiplied memory address " << d1 << " with value " << dataMem[d1] << " to memory address " << d2 << " with value " << dataMem[d2] << " and stored the result ";
            dataMem[d3] = dataMem[d1] * dataMem[d2];
            cout << dataMem[d3] << " in memory address " << d3 << "." << endl;
        }
        else if(instr == "JPA"){
            i = d1 - 1;
            cout << "#The SIM jumped to memory address " << d1 - 1 << "." << endl;
        }
        else if(instr == "JP0"){
            if(dataMem[d1] == 0){
                i = d2 - 1;
                cout << "#The SIM jumped to memory address " << d2 << " because in1 was equal to zero." << endl;
            }
            else cout << "#The SIM did not jump to memory address " << d2 << " because in1 of value " << d1 << " was not equal to zero." << endl;
        }
        else if(instr == "ASI"){
            dataMem[d2] = d1;
            cout << "#The SIM stored value " << d1 << " in memory address " << d2 << "." << endl;
        }
        else if(instr == "LOE"){
            if(dataMem[d1] <= dataMem[d2]) {
                dataMem[d3] = 1;
                cout << "#The SIM stored the value 1 in memory address " << d3 << " because the value " << dataMem[d1] << " of address " << d1 << " was less than or equal to the value " << dataMem[d2] << "stored in memory address " << d2 << "." << endl;
            }
            else{
                dataMem[d3] = 0;
                cout << "#The SIM stored the value 0 in memory address " << d3 << " because the value " << dataMem[d1] << " of address " << d1 << " was greater than the value " << dataMem[d2] << "stored in memory address " << d2 << "." << endl;
            }
        }
        else if(instr == "HLT"){
            cout << "#The SIM is stopped." << endl;
            break;
        }
        else cerr << "instruction in text is invalid" << endl;
    }
    
}

void SIM::extractData(){
    stringstream ss;
    string tempInstr = instrLine;
    /* Storing the whole string into string stream */
    ss << tempInstr;
    /* Running loop till the end of the stream */
    string temp;
    int found;
    int i = 0;
    while (!ss.eof()) {
        
        /* extracting word by word from stream */
        ss >> temp;
        
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found){
            i++;
            if(i == 1)
                d1 = found;
            else if(i == 2)
                d2 = found;
            else
                d3 = found;
        }
        
        /* To save from space at the end of string */
        temp = "";
    }
}

int SIM::getDataMem(int i){
    return dataMem[i];
}

string SIM::getInstMem(int i){
    return instMem[i];
}
