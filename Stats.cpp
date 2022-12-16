//
// Created by rafael on 16/12/22.
//

#include "Stats.h"

Stats::Stats(Instance *instance) {
    this->instance=instance;
    this->costAvg=0;
    this->timeAvg=0;
    this->bestCost=-1;
    this->bestCostCount=0;
    this->bestTime=-1;
}

void Stats::pushRun(double time, Layout *layout) {
    this->times.push_back(time);
    this->layouts.push_back(layout);

    if(this->bestCost==-1 || layout->cost<this->bestCost){
        this->bestCost=layout->cost;
        this->bestCostCount=1;
    }else if(this->bestCost==layout->cost){
        this->bestCostCount++;
    }

    if(this->bestTime==-1 || time<this->bestTime){
        this->bestTime=time;
    }

    this->costAvg+=layout->cost;
    this->timeAvg+=time;
}

void Stats::coutRun(int i, long seed) {
    cout<<to_string(i)<<" - "<<to_string(seed)<<" - "<<to_string(this->times.at(i))<<"s - "<<to_string(this->layouts.at(i)->cost)<<endl;

}