//
// Created by rafael on 16/12/22.
//

#ifndef IGCAP_CONFIGURES_H
#define IGCAP_CONFIGURES_H
#include <vector>
#include <ctime>

using namespace std;
class Configures {
public:
    Configures(float alpha, int dMax, int runs){
        this->alpha=alpha;
        this->dMax=dMax;
        this->runs=runs;
        for(int i=0;i<runs;i++){
            seeds.push_back(clock());
        }
    }

    vector<double> seeds;
    float alpha;
    int dMax;
    int runs;
};


#endif //IGCAP_CONFIGURES_H
