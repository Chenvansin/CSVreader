//
// Created by ychepth on 2019/11/2.
//
#include "csvreader.h"
#include "gaitdata.h"
CsvReader::CsvReader() {
    this->filename = "E:\\Gait.csv";
    this->delimiter = ',';
}

bool CsvReader::spliteLine(const std::string strLine,StringVector& stringVector,bool convert){
    unsigned int nBegin = 0;
    unsigned int nEnd = 0;
    unsigned int iter = 0;

    while((nEnd = strLine.find_first_of(delimiter,nBegin)) != std::string::npos){ //ending forward search until to last substring which doesn't have delimiter.
        std::string strtemp = strLine.substr(nBegin,nEnd-nBegin); //got substring from nBegin to nEnd
        stringVector.push_back(strtemp);
        if(convert){
            toGaitData(iter,std::string(strtemp.data()),&gaitdata);
            iter++;
        }
        nBegin = nEnd+1; // moving nowBegin position
    }

    if(nBegin = strLine.find_last_of(delimiter,strLine.length()-1) != std::string::npos){//applying back-forward search to obtain last substring
        std::string strtemp = strLine.substr(nBegin+1,strLine.length()-nBegin-1);
        stringVector.push_back(strtemp);
        if(convert)
            toGaitData(iter,std::string(strtemp.data()),&gaitdata); //since iter had been added in last step of forward process.
    }
    return true;
}

unsigned int CsvReader::ReadCSV() {
    unsigned int length = 0;
    bool convert = false; //to skip first row of .CSV
    std::ifstream Reader(filename.data());
    if(!Reader){
        perror("[open file failed!");
    }

    std::string strLineContext;
    while (getline(Reader,strLineContext)){
        length++;
        StringVector vecValue;
        spliteLine(strLineContext,vecValue,convert);
        content.push_back(vecValue); //added data to content but doesn't add toGaitData at first time
        convert = true;
    }
    Reader.close();



    return length;
}

