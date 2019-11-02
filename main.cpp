#include <iostream>
#include "csvreader.h"
#include "gaitdata.h"
using namespace std;

int main() {
    Gaitdata gaitdata;
    CsvReader csvReader;
    csvReader.ReadCSV();
    std::cout << csvReader.gaitdata.time[0] << std::endl;
    return 0;
}