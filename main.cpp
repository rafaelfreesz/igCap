#include <iostream>
#include <vector>
#include "Configures.h"
#include "Utils.h"
#include "Instance.h"
#include "Stats.h"
#include "Search.h"

using namespace std;
int main() {

    Configures* configures = new Configures(0.1,5,30);
    vector<Instance*> instances = Utils::loadInstances();
    vector<Stats*> statsVector;


    for(Instance* instance : instances){
        cout<<"Instance "+instance->name<<endl;
        Stats* stats = new Stats(instance);

        for(int i=0;i<configures->runs;i++){

            srand(configures->seeds.at(i));

            Search* search = new Search(instance,configures);

            clock_t time=clock();
            search->go();
            time=clock()-time;

            stats->pushRun(((double) time / CLOCKS_PER_SEC),search->layout);
            stats->coutRun(i, configures->seeds.at(i));
        }

        statsVector.push_back(stats);
        stats->coutRunsResume();
    }



    return 0;
}
