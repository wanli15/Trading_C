//
//  indicator.cpp
//  545Project
//
//  Created by Jade on 4/27/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "indicator.hpp"
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

    
StochRSI::StochRSI(const Wrapper<Data> & data)
    : period(14)
{
        ERSI = GetRSI(data);
}
    
StochRSI::StochRSI(const Wrapper<Data>& data, int period)
    : period(period)
{
        ERSI = GetRSI(data);
}
    
vector<double> StochRSI::GetRSI(const Wrapper<Data>& data)
{
        
        vector<double> Avgain;
        vector<double> Avloss;
        
        Avgain = EMA(gain(data->adjcl), period);
        Avloss = EMA(loss(data->adjcl), period);
        
        vector<double> RS;
        RS = divide(Avgain, Avloss);
        
        vector<double> RSI;
        for( int i=0; i<RS.size(); ++i){
            RSI.push_back(100 - (100/(1+RS[i])));
        }
        
        vector<double> High;
        vector<double> Low;
        High = Highesthigh(RSI, period);
        Low  = Lowestlow(RSI, period);
        
        
        vector<double> StochRSI;
        for( int i = 0; i<High.size(); ++i){
            
            StochRSI.push_back((RSI[i] - Low[i])/(High[i] - Low[i]));
        }
        
        vector<double>::iterator it;
        it = StochRSI.begin();
        StochRSI.insert(it, 2*period -1, 0);
        
        return StochRSI;
        
}
    
bool StochRSI::overbought(int index){
        
        const double OB_signal = 0.8;
        return ERSI[index] > OB_signal;
}
    
bool StochRSI::oversold(int index){
        
        const double OS_signal = 0.2;
        return ERSI[index] < OS_signal;
}




SMATrend::SMATrend(const Wrapper<Data>& data)
: shortterm(10),longterm(60)
{
        vector<double>::iterator it;
        SMA_shortterm = SMA(data->adjcl, shortterm);
        it = SMA_shortterm.begin();
        SMA_shortterm.insert(it, shortterm, 0);
        
        
        SMA_longterm = SMA(data->adjcl, longterm);
        it = SMA_longterm.begin();
        SMA_longterm.insert(it, longterm, 0);
        
}
    
    
SMATrend::SMATrend(const Wrapper<Data> &data, int shortterm, int longterm):shortterm(shortterm),longterm(longterm)
{
        SMA_shortterm = SMA(data->adjcl, shortterm);
        SMA_longterm = SMA(data->adjcl, longterm);
}
    
int SMATrend::getLongterm(){
        
        return longterm;
}
    
bool SMATrend::uptrend(int index){
        
        return movesAbove(SMA_shortterm, SMA_longterm, index);
}
    
bool SMATrend::downtrend(int index){
        
        return movesBelow(SMA_shortterm, SMA_longterm, index);
}



    
  