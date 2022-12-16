//
// Created by rafael on 16/12/22.
//

#include "Utils.h"

//Return a vector with all problem instances
vector <Instance*> Utils::loadInstances() {
    vector<Instance*> instances;
    string strInstanceName, line;
    ifstream fileInstances;

    strInstanceName="Instances/Instances";

    fileInstances.open(strInstanceName.c_str());

    //Loading and treating each instance
    while(getline(fileInstances, strInstanceName)){
        line= "Instances/" + strInstanceName;
        ifstream fileInst;
        fileInst.open(line.c_str());

        //Setting instance name and size (n)
        getline(fileInst,line);
        Instance* instance = new Instance(stoi(line));
        instance->name=strInstanceName;

        //Setting facilites length
        getline(fileInst,line);
        vector<string> tokenizedLengths;
        tokenize(line,tokenizedLengths,",");
        if(tokenizedLengths.size()!=instance->n){
            cout<<"#lengths differs from instance size in" + instance->name<<endl;
            exit(2);
        }else{
            for(int i=0;i<instance->n;i++){
                instance->lengths[i]= stoi(tokenizedLengths.at(i));
                instance->halfLengths[i]=(float)instance->lengths[i]/2.0;
            }
        }

        //Setting facilities demmands
        for(int i=0;i<instance->n;i++){
            if(getline(fileInst,line)){
                vector<string> tokenizedDemands;
                tokenize(line,tokenizedDemands,",");

                if(tokenizedDemands.size()==instance->n){
                    for(int j=0;j<instance->n;j++){
                        instance->demands[i][j]= stoi(tokenizedDemands.at(j));
                    }
                }else{
                    cout<<"#demmands differs from instance size in" + instance->name<<endl;
                    exit(3);
                }
            }else{
                cout<<"#lines differs from instance size in" + instance->name<<endl;
            }
        }


        instance->calculateLayoutLength();
        instance->verifyIntegrity();
        fileInst.close();
        instances.push_back(instance);
    }

    fileInstances.close();

    return instances;
}


//Tokonize string to vector
void Utils::tokenize(string str, vector<string> &token_v, string DELIMITER) {
    size_t start = str.find_first_not_of(DELIMITER), end=start;

    while (start != std::string::npos) {
        end = str.find(DELIMITER, start);
        token_v.push_back(str.substr(start, end-start));
        start = str.find_first_not_of(DELIMITER, end);
    }
}