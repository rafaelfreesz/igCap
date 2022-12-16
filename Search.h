//
// Created by rafael on 16/12/22.
//

#ifndef IGCAP_SEARCH_H
#define IGCAP_SEARCH_H


#include "Instance.h"
#include "Configures.h"
#include "Layout.h"

class Search {
public:

    Search(Instance *instance, Configures* configures);
    ~Search();

    void go();
    void construct();


    Instance* instance;
    Configures* configures;
    Layout* layout;
};


#endif //IGCAP_SEARCH_H
