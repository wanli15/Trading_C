#ifndef _DATA_H_
#define _DATA_H_
#include <string>
#include <vector>
#include "downloadFile.h"
using namespace std;

//Adapter object pattern to use wrapper to wrap data for use in strategy
class Data {
    
    string dataName_;
    unsigned long length;
	string szWebSite;
    
public:
    vector<string> date;
    vector<double> op;
    vector<double> hi;
    vector<double> lo;
    vector<double> cl;
    vector<long> vol;
    vector<double> adjcl;
    
	void reverse();
	//download data from API
	void downloadData();
	void setDataName(string dataName);
	void setWebSite(string webSite);

    unsigned long dataSize;
    //load data from local
    void saveOneLine(string aLine);
    virtual Data* clone() const = 0;
    
	//virtual Data* clone() const = 0;// Prototype Design Pattern, return a clone of concret class
};

class DataForGOOG : public Data {
	string dataName = "GOOG";
public:
	DataForGOOG();
	Data* clone() const;
};

class DataForSXP5 : public Data {
	string dataName = "S&P5";
public:
	DataForSXP5();
	Data* clone() const;
};





#endif