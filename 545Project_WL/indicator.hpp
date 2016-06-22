//
//  indicator.hpp
//  545Project
//
//  Created by Jade on 4/27/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef indicator_hpp
#define indicator_hpp
#include "Tools.h"
#include<stdio.h>
#include"Data.h"
#include"Wrapper.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>
#include <map>
#pragma once
//using namespace std;


class indicator{
    
    
    
public:
  
    
    
};

class StochRSI: indicator {
    
    int period;
    vector<double> ERSI;
    
public:
    
    StochRSI(const Wrapper<Data> & data);
    StochRSI(const Wrapper<Data> &data, int period);
    
    vector<double> GetRSI(const Wrapper<Data> &data);
    
    bool overbought(int index);
    bool oversold(int index);
    

    
};

class SMATrend: indicator{
    
    int shortterm;
    int longterm;
    vector<double> SMA_shortterm;
    vector<double> SMA_longterm;
    
public:
    
    SMATrend(const Wrapper<Data> &data);
    SMATrend(const Wrapper<Data> &data, int shortterm, int longterm);
    int getLongterm();
    
    bool uptrend(int index);
    bool downtrend(int index);
  
    
};

#endif /* indicator_hpp */
