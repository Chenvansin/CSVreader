//
// Created by ychepth on 2019/11/2.
//

#ifndef CSVHANDLE_CSVREADER_H
#define CSVHANDLE_CSVREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "gaitdata.h"

typedef std::vector<std::string> StringVector;
typedef std::vector<StringVector> StringMatrix;

class CsvReader{
public:
    CsvReader();
    bool spliteLine(const std::string strLine,StringVector& stringVector,bool convert);
    unsigned int ReadCSV();
    Gaitdata gaitdata;

private:
    std::string filename;
    StringMatrix content;
    char delimiter;
};

#endif //CSVHANDLE_CSVREADER_H
