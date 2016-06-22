//
//  Performance.cpp
//  545Project
//
//  Created by Jade on 4/28/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "Performance.hpp"
#include "Strategy.hpp"

using namespace std;


Performance::Performance(Strategy &Inner):Strategy(Inner)
{
    this->Inner = &Inner;
}

vector<double> Performance::performance(){
    
    vector<double> yield;
    yield = Inner->performance();
    for( int i = 0; i<yield.size(); ++i){
        cout<< i + 1 <<" trade time : "<<yield[i]*100<<" % return"<<endl;
    }
    cout<<endl;
    cout<<"Total return : "<<YieldSum(yield)*100<<" % "<<endl;
    return yield;
}

void Performance::execution(){

    Inner->execution();
}

