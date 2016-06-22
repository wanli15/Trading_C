//
//  Performance.hpp
//  545Project
//
//  Created by Jade on 4/28/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef Performance_hpp
#define Performance_hpp
#include <string>
#include <iostream>
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>
#include "Data.h"
#include "Strategy.hpp"
#include <stdio.h>

//Decorator pattern design
class Performance:public Strategy {
        
    Strategy *Inner;

public:
    
    Performance(Strategy &Inner);
    vector<double> performance();
    void execution();
    
};



#endif /* Performance_hpp */
