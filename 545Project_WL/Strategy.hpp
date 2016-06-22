//
//  Strategy.hpp
//  545Project
//
//  Created by Jade on 4/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef Strategy_hpp
#define Strategy_hpp

#include<stdio.h>
#include<map>
#include<vector>
#include "indicator.hpp"
#include "Wrapper.h"
#include "Data.h"


class Strategy {

protected:
    
    string strategyName_;
    Wrapper<Data> dataPtr;
    
public:
    //Adaptor pattern to use data
    Strategy(const Wrapper<Data> &dataPtr);
    string &getName();
    void setName(string name);
    void close(double amount);
    
    virtual void execution() = 0;
    virtual vector<double> performance() = 0;
    
};

class ModerateStrategy : public Strategy {
    
    StochRSI rsi;
    SMATrend trend;
    
    int index;
    unsigned long length;
    
    vector<int> buyindex;
    vector<double> buyprice;
    vector<double> sellprice;
    vector<int> sellindex;
    
public:
    
    ModerateStrategy(const Wrapper<Data> &dataPtr);
    ModerateStrategy(const Wrapper<Data>& dataPtr, int rsiperiod, int shortterm, int longterm);
    
    int buysignal(int t);
    int sellsignal(int t);
    
    virtual void execution();
    virtual vector<double> performance();


};

class PassiveStrategy : public Strategy {
  
    unsigned long length;
    map<string, double> buyprice;
    map<string, double> sellprice;

    
public:
    
    PassiveStrategy(const Wrapper<Data> &dataPtr);
    virtual void execution();
    virtual vector<double> performance();
    

};

#endif /* Strategy_hpp */