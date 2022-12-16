//
// Created by rafael on 16/12/22.
//

#include "Search.h"

Search::Search(Instance *instance, Configures* configures) {
    this->instance=instance;
    this->layout=new Layout(instance);
    this->configures=configures;

}
Search::~Search(){
    //Maybe no needed.
}

void Search::go() {
    construct();
}

void Search::construct() {

}
