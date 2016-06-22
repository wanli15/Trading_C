#ifndef _TOOLS_H_
#define _TOOLS_H_
#include <string>
#include <iostream>
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

    //calculate daily gain
    vector<double> gain(vector<double> price);
    
    ////calculate daily loss
    vector<double> loss(vector<double> price);
    
    ////calculate simple moving average
    vector<double> SMA( vector<double> price, int period);
    
    ////calculate expoential moveing average
    vector<double> EMA(vector<double> price, int period);
    
    vector<double> Highesthigh(vector<double> index, int period);
    
    vector<double> Lowestlow(vector<double> index, int period);
    
    //map manipulation for yield calculation
    vector<double> Getyield( vector<double> v1, vector<double> v2);

    ////buy signal if short term cross long term from below
    bool movesAbove(vector<double> shortterm, vector<double> longterm, unsigned long i);
    
    ////sell signal if short term cross long term from behind
    bool movesBelow(vector<double> shortterm, vector<double> longterm, unsigned long i);
    
    ////vector manipulation
    vector<double> divide(const vector<double> vec1, const vector<double> v2);
    
    double YieldSum(vector<double> &vec);
        
#endif // !_TOOLS_H_
        
