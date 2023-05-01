#ifndef CLASS_TIMES_H
#define CLASS_TIMES_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class ClassTimes
{
    private:
        map<int, vector<pair<double, double> > > schedule;
        vector<double> times;
    public:
        ClassTimes();
        void printSchedule();
        
        void addClassTime();
};

#endif