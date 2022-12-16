//
// Created by rafael on 16/12/22.
//

#ifndef IGCAP_STATS_H
#define IGCAP_STATS_H
#include <vector>
#include "Instance.h"
#include "Layout.h"

class Stats {
public:
    Stats(Instance* instance);
    void pushRun(double time, Layout* layout);
    void coutRun(int i, long seed);

    Instance* instance;
    vector<Layout*> layouts;
    vector<double> times;
    float costAvg;
    float bestCost;
    int bestCostCount;
    double timeAvg;
    double bestTime;
};


#endif //IGCAP_STATS_H
