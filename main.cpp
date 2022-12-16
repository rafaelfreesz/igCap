#include <iostream>
#include <vector>
#include "Configures.h"
#include "Utils.h"
#include "Instance.h"

int main() {

    Configures* configures = new Configures(0.1,5,30);
    vector<Instance*> instances = Utils::loadInstances();

    for(Instance* instance : instances){
        instance->print();
    }



    return 0;
}
