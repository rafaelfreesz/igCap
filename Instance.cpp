//
// Created by rafael on 16/12/22.
//

#include "Instance.h"

//Constructor
Instance::Instance(int n){
    this->n=n;
    this->lengths = new int[n];
    this->halfLengths = new float[n];
    this->demands = new int*[n];
    for(int i=0;i<n;i++){
        this->demands[i]=new int[n];
    }

}

//Destructor
Instance::~Instance() {
    delete[] this->lengths;
    delete[] this->halfLengths;
    for(int i=0;i<this->n;i++){
        delete []this->demands[i];
    }
    delete [] this->demands;
}


//Calculates the sum of every facility lengths
void Instance::calculateLayoutLength() {
    this->layoutLengh=0;
    for(int i=0;i<this->n;i++){
        this->layoutLengh+=this->lengths[i];
    }
}

//Verify instance integrity
void Instance::verifyIntegrity() {
    if(this->demands != nullptr){
        for(int i=0;i<this->n;i++){
            for(int j=0;j<this->n;j++){
                if(this->demands[i][j] != this->demands[j][i]){
                    cout<<"Diferença de elementos da matriz, instancia "<<this->name<<endl;
                    exit(0);
                }
            }
        }
    }else{
        cout<<"Não instanciada"<<endl;
        exit(0);
    }

}

//Printing instance attributes
void Instance::print() {

    cout<<"Name:"<<this->name<<endl;
    cout<<"N:"<<this->n<<endl;
    cout<<"Lenths:{";
    for(int i=0;i<n;i++) {
        cout << to_string(this->lengths[i]) + " ";
    }
    cout<<"}"<<endl;
    cout<<"Half Lenths:{";
    for(int i=0;i<n;i++) {
        cout << to_string(this->halfLengths[i]) + " ";
    }
    cout<<"}"<<endl;
    cout<<"Demands:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cout << to_string(this->demands[i][j]) + " ";
        }
        cout<<endl;
    }
    cout<<"---------------------------"<<endl;


}