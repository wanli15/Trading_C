#include "Tools.h"
#include <cmath>
#include <string>
#include <iostream>
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>


vector<double> gain(vector<double> price){
    
    vector<double> gain;
    
    for(int t = 1; t<= price.size(); ++t){
        
        
        if(price[t-1] < price[t]){
            
            gain.push_back(price[t] - price[t-1]);
            
        }else{
            
            gain.push_back(0);
        }
    }
    return gain;
}

vector<double> loss(vector<double> price){
    
    vector<double> loss;
    
    for(int t = 1; t<= price.size(); ++t){
        
        if(price[ t-1 ] > price[t]){
            
            loss.push_back(price[t - 1] - price[t]);
            
        }else{
            
            loss.push_back(0);
        }
    }
    return loss;
}



vector<double> SMA( vector<double> price, int period){
    
    vector<double> sma;
    double sum = 0;
    
    for( int t=0; t<price.size(); ++t){
        
        sum += price[t];
        
        
        if( t >= period )
        {
            sma.push_back( sum / period );
            sum -= price[t - period];
        }
        
    }
    return sma;
    
}

vector<double> EMA(vector<double> price, int period){
    
    vector<double> ema;
    
    double beta = 2.0/(period + 1);
    
    double sum = 0;
    
    for( int t=0; t< period; ++t){
        
        sum += price[t];
    }
    
    double avg = sum / period;
    
    ema.push_back(avg);
    
    double val;
    
    for(int t = period; t<price.size(); ++t){
        
        val = beta * price[t] + (1 - beta) * ema.back();
        ema.push_back(val);
    }
    
    
    return ema;
}

vector<double> Highesthigh(vector<double> index, int period){
    
    vector<double> highesthigh;
    double maximum = 0.0;
    
    for( int j = 0; j<(index.size() - period); ++j){
        
        for( int i = j;i < (j + period); ++i){
            
            maximum = fmax(maximum, index[i]);

        }
        
        highesthigh.push_back(maximum);
    }
    
    return highesthigh;
}


vector<double> Lowestlow(vector<double> index, int period){
    
    vector<double> lowestlow;
    double minimum = 0.0;
    
    for( int j =0; j<index.size() - period; ++j){
        
        for(int i = j;i < j + period; ++i){
            
            minimum = fmin(minimum, index[i]);
    }
        
        lowestlow.push_back(minimum);
    }
    
    return lowestlow;
}



bool movesAbove(vector<double> v1, vector<double> v2, unsigned long i){
    
    return v1[i - 1] <= v2[i - 1] && v1[i] > v2[i];
    
}

bool movesBelow(vector<double> v1, vector<double> v2, unsigned long i){
    return v1[i - 1] >= v2[i - 1] && v1[i] < v2[i];
}


vector<double>  Getyield( vector<double> v1, vector<double> v2){
    
   unsigned long size;
    
    if(v1.size() != v2.size()){
        
        size = fmin(v1.size(),v2.size());
        
    } else {
        
        size = v1.size();
    }
    
    vector<double> yield;
    
    for(unsigned long i = 0; i<size; ++i){
        
        yield.push_back(log(v2[i]/v1[i]));
        
    }
    //sum all yield up;
    //yield = YieldSum(yield);
    return yield;
    
}



double YieldSum(vector<double> &vec){
    
    double sum = 0;
    for (unsigned long i = 0; i < vec.size(); ++i) {
        
        sum = sum + vec[i];
        
    }
    return sum;
}




vector<double> divide(const vector<double> vec1, const vector<double> vec2){
    
    if (vec1.size() != vec2.size()) {
        perror("Size does not Match");
        return vector<double>();
    }
    vector<double> divide(vec1.size(),0);
    for( int i = 0; i<vec1.size(); ++i){
        divide[i] = (vec1[i] / vec2[i]);
    }
    
    return divide;
    
}
