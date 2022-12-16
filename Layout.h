//
// Created by rafael on 16/12/22.
//

#ifndef IGCAP_LAYOUT_H
#define IGCAP_LAYOUT_H
#include "Instance.h"

class Layout {
    Layout(Instance* instance);
    ~Layout();

    Layout* clone();

    void print();

    int* corridor;
    float* abcissa;
    int p;
    float cost;
    int assigned;
    Instance* instance;
};


#endif //IGCAP_LAYOUT_H
