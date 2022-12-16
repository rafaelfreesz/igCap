//
// Created by rafael on 16/12/22.
//

#include "Layout.h"

//Constructor
Layout::Layout(Instance *instance) {
    this->instance=instance;
    this->corridor=new int [instance->n];
    this->abcissa=new float[instance->n];
    this->p=0;
    this->assigned=0;
    this->cost=0.0;
}
//Destructor
Layout::~Layout() {
    delete []this->corridor;
    delete []this->abcissa;
}

Layout *Layout::clone() {
    Layout* agClone = new Layout(this->instance);

    agClone->p=this->p;
    agClone->cost=this->cost;
    agClone->assigned=this->assigned;

    for(int i=0;i<this->assigned;i++){
        agClone->abcissa[i]=this->abcissa[i];
        agClone->corridor[i]=this->corridor[i];
    }

    return agClone;
}


//Printing current layout
void Layout::print() {

    cout<<"Layout:"<<endl;
    cout<<"E: ";
    for(int i=0;i<this->p;i++){
        cout<< to_string(this->corridor[i]) + " ";
    }
    cout<<endl;

    cout<<"D: ";
    for(int i=this->p;i<this->assigned;i++){
        cout<< to_string(this->corridor[i]) + " ";
    }
    cout<<endl;

    cout<<"Abcissa:"<<endl;
    for(int i=0;i<this->assigned;i++){
        cout<<to_string(this->abcissa[this->corridor[i]])+" ";
    }
    cout<<endl;

    cout<<"Cost: "+ to_string(this->cost)<<endl;
}