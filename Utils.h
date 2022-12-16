//
// Created by rafael on 16/12/22.
//

#ifndef IGCAP_UTILS_H
#define IGCAP_UTILS_H
#include <iostream>
#include <fstream>
#include "Instance.h"
#include <vector>

class Utils {
public:
    static vector<Instance*> loadInstances();
    static void tokenize(string str, vector<string> &token_v, string DELIMITER);
};


#endif //IGCAP_UTILS_H
