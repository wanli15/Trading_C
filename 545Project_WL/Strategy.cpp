//
//  Strategy.cpp
//  545Project
//
//  Created by Jade on 4/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//
#
#include "Strategy.hpp"
#include <cmath>
using namespace std;


Strategy::Strategy(const Wrapper<Data> &dataPtr)
:dataPtr(dataPtr)
{
}

string & Strategy::getName()
{
    return strategyName_;
}


void Strategy::setName(string name)
{
    strategyName_ = name;
}


//StochRSI rsi;
//SMATrend trend;
ModerateStrategy::ModerateStrategy(const Wrapper<Data>& dataPtr)
:Strategy(dataPtr),rsi(StochRSI(dataPtr)),trend(SMATrend(dataPtr))
{
    setName("Moderate Strategy");
    index = trend.getLongterm() - 1;
    length = dataPtr->dataSize;
}

ModerateStrategy::ModerateStrategy(const Wrapper<Data>& dataPtr, int rsiperiod, int shortterm, int longterm):Strategy(dataPtr),rsi(StochRSI(dataPtr,rsiperiod)),trend(SMATrend(dataPtr,shortterm, longterm))
{
    setName("Moderate Strategy");
    index = trend.getLongterm() - 1;
    length = dataPtr->dataSize;
}


int ModerateStrategy::buysignal(int t)
{
    int i;
    int number = 0;
    for( i = t; i< length; ++i)
    {
        
          if(trend.uptrend(i))
          {
        
              for(int j = i; j<length; ++j)
              {
        
                  if(rsi.oversold(j))
                  {
                     
                      number = j;
                      break;
                      
                  }
              }
             i = int(length);
          }
    }
    
    return number;
}


int ModerateStrategy::sellsignal(int t)
{
    int number = 0;
    int temp = t - 1;
    int i;
    for( i = t; i< length; ++i){
        
        if( dataPtr->lo[t] < (0.95 * dataPtr->adjcl[temp]))
        {
            
            number = t;  //loss stop
            break;
        } else if(trend.downtrend(i))
        {
            
            for(int j = i; j<length; ++j)
            {
                
                if(rsi.overbought(j))
                {
                    
                    number = j;
                    break;
                }
            }
            i = int(length);
        }
    }
    
    return number;
}



void ModerateStrategy::execution(){
    
    int buypoint;
    int sellpoint;
    int i = index;

    
  while(i <length & i != 0)
  {
        buypoint = buysignal(i);
        if (buypoint == 0){
            
           // cout<<" No more buy signal, done "<<endl;
            i = 0;
            
        } else
        {
           
            buyindex.push_back(buypoint);
            buyprice.push_back(dataPtr->adjcl[buypoint]);
            
            if(buypoint > 2/3 * length){
                
            sellindex.push_back(int(length));
            sellprice.push_back(dataPtr->adjcl[length-2]);
            }
            
            sellpoint = sellsignal(buypoint+1);
            if( sellpoint == 0){
            
          //  cout<<" No more sell signal, done "<<endl;
            i = 0;
             
            } else
            {
             
            sellindex.push_back(sellpoint);
            sellprice.push_back(dataPtr->adjcl[sellpoint]);
            i = sellpoint + 1;
                 
            }
            
        }
      
    }
    cout<<"Moderate Strategy Done, check the performance "<<endl<<endl;
}

vector<double> ModerateStrategy::performance(){
    
    vector<double> yield;
    yield = Getyield(buyprice, sellprice);
    return yield;

}


PassiveStrategy ::PassiveStrategy(const Wrapper<Data>& dataPtr)
:Strategy(dataPtr)
{
    length = dataPtr->dataSize;
    
}

void PassiveStrategy::execution(){

     buyprice[dataPtr->date[1]] = dataPtr->adjcl[1];
     sellprice[dataPtr->date[length - 2]]= dataPtr->adjcl[length - 2];
    cout<<"PassiveStrategy done, please check performance "<<endl<<endl;
    
}

vector<double> PassiveStrategy::performance(){
    
    map<string, double>::iterator it1;
    map<string, double>::iterator it2;
    it1 = buyprice.begin();
    it2 = sellprice.begin();
    
    vector<double> yield;
    yield.push_back(log(it2->second/it1->second));
    cout<<"Trade Date:  "<<it1->first<< " to "<<it2->first<<endl;
    return yield;
    
    
}


