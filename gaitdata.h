//
// Created by ychepth on 2019/11/2.
//

#ifndef CSVHANDLE_GAITDATA_H
#define CSVHANDLE_GAITDATA_H

#include <string>
#include <vector>
using namespace std;

class Gaitdata{
public:
    vector<float> hipL;
    vector<float> hipR;
    vector<float> kneeL;
    vector<float> kneeR;
    vector<float> ankleL;
    vector<float> ankleR;
    vector<float> time;
};

bool toGaitData(unsigned int iter, string data, Gaitdata* gaitdata);


#endif //CSVHANDLE_GAITDATA_H
