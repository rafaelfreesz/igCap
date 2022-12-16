//
// Created by rafael on 16/12/22.
//
//Class that stores and manage instances

#ifndef IGCAP_INSTANCE_H
#define IGCAP_INSTANCE_H
#include <iostream>

using namespace std;
class Instance {
public:
    Instance(int n);
    ~Instance();

    void calculateLayoutLength();

    void print();
    void verifyIntegrity();


    string name;
    int n;
    int* lengths;
    float* halfLengths;
    int** demands;
    int layoutLengh;
};


#endif //IGCAP_INSTANCE_H
