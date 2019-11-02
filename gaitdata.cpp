//
// Created by ychepth on 2019/11/2.
//

#include "gaitdata.h"
#include <sstream>
#include "csvreader.h"

template <class Type>
Type stringToNum(const string & str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

bool toGaitData(unsigned int iter, string data, Gaitdata* gaitdata){
    switch(iter){
        case 0:
            gaitdata->time.push_back(stringToNum<float>(data));
            break;
        case 1:
            gaitdata->hipL.push_back(stringToNum<float>(data));
            break;
        case 2:
            gaitdata->hipR.push_back(stringToNum<float>(data));
            break;
        case 3:
            gaitdata->kneeL.push_back(stringToNum<float>(data));
            break;
        case 4:
            gaitdata->kneeR.push_back(stringToNum<float>(data));
            break;
        case 5:
            gaitdata->ankleL.push_back(stringToNum<float>(data));
            break;
        case 6:
            gaitdata->ankleR.push_back(stringToNum<float>(data));
        default:
            break;
    }
    return true;
}

