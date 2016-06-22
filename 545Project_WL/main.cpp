//
//  main.cpp
//  545Project
//
//  Created by Jade on 4/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
#include "Records.h"
#include "Strategy.hpp"
#include "indicator.hpp"
#include "Performance.hpp"
#include "Data.h"
#include <string>
#include <iostream>
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include<fstream>
using namespace std;

int main() {
    
	//For Moderate Strategy
	 cout << "Strategy executed on Time period 2010 to 2016 " << endl;
	 DataForGOOG GOOG;
	 ModerateStrategy  ms(GOOG);
     Performance *m = new Performance(ms);
	 m->execution();
	 cout << "GOOG Stock:" << endl;
	 vector<double> j;
	 j = m->performance();

	 //Created file to record moderate results
	 Records::getInstance()->print("Moderate Startegy");
	 for (int i = 0; i < j.size(); ++i){
	 Records::getInstance()->print("the trade %i ", i + 1);
	 Records::getInstance()->print("time of the return is  %g  ", j[i]);
	 }
	 cout << endl;


	 cout << endl;
	 //For Passive Strategy
	 DataForSXP5 SP5;
	 PassiveStrategy ps(SP5);
	 Performance *p = new Performance(ps);
	 p->execution();
	 cout << "S&P500 Stock:" << endl;
	 vector<double> k;
	 k = p->performance();

	 //Create file to record passive strategy results
	 Records::getInstance()->print("\n\n");
	 Records::getInstance()->print("Passive Startegy ");
	 for (int i = 0; i < k.size(); ++i){

		 Records::getInstance()->print("the trade %i ", i + 1);
		 Records::getInstance()->print("time of the return is  %g  ", k[i]);
	 }
	 cout << endl;
	 int a;
	 cin >> a;
	 
}
