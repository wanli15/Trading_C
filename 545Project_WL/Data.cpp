#include "Data.h"
#include <string>
#include <iostream>
#include<iostream>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include<cmath>
#include <fstream>
#include <string>
#pragma comment(lib, "urlmon.lib")




void Data::saveOneLine(string aLine)
{
    char* pc_line = (char*)aLine.c_str();
    char* pchar;	// one piece of the line
    
    string stk_date;
    double stk_open;
    double stk_high;
    double stk_low;
    double stk_close;
    long stk_volume;
    double stk_adj_close;
    
    pchar = strtok(pc_line, ",");
    stk_date = pchar;
    date.push_back(stk_date);
    pchar = strtok(NULL, ",");
    stk_open = atof(pchar);
    op.push_back(stk_open);
    pchar = strtok(NULL, ",");
    stk_high = atof(pchar);
    hi.push_back(stk_high);
    pchar = strtok(NULL, ",");
    stk_low = atof(pchar);
    lo.push_back(stk_low);
    pchar = strtok(NULL, ",");
    stk_close = atof(pchar);
    cl.push_back(stk_close);
    pchar = strtok(NULL, ",");
    stk_volume = atol(pchar);
    vol.push_back(stk_volume);
    pchar = strtok(NULL, ",");
    stk_adj_close = atof(pchar);
    adjcl.push_back(stk_adj_close);
    
}

void Data::reverse()
{
	unsigned long n = date.size();
	vector<string> date1(n, " ");
	vector<double> op1(n, 0);
	vector<double> hi1(n, 0);
	vector<double> lo1(n, 0);
	vector<double> cl1(n, 0);
	vector<long> vol1(n, 0);
	vector<double> adjcl1(n, 0);

	int j;

	for (unsigned long i = 0; i < n; i++)
	{
		j = n - i - 1;
		date1[i] = date[j];
		op1[i] = op[j];
		hi1[i] = hi[j];
		lo1[i] = lo[j];
		cl1[i] = cl[j];
		vol1[i] = vol[j];
		adjcl1[i] = adjcl[j];
	}

	for (int i = 0; i < n; ++i){
		date[i] = date1[i];
		op[i] = op1[i];
		hi[i] = hi1[i];
		lo[i] = lo1[i];
		cl[i] = cl1[i];
		vol[i] = vol1[i];
		adjcl[i] = adjcl1[i];
	}


}

void Data::downloadData()
{
	stringstream strStream;
	downloadFile(szWebSite, strStream);

	char TradeDate[26] = " ";
	char szSub[100];

	date.empty();
	op.empty();
	hi.empty();
	lo.empty();
	cl.empty();
	vol.empty();
	adjcl.empty();

	while (strStream.good())
	{
		if (!strStream.getline(szSub, sizeof(szSub), ','))
			break;

		strcpy_s(TradeDate, sizeof(TradeDate), szSub);
		date.push_back(TradeDate);

		strStream.getline(szSub, sizeof(szSub), ',');
		op.push_back(atof(szSub));

		strStream.getline(szSub, sizeof(szSub), ',');
		hi.push_back(atof(szSub));

		strStream.getline(szSub, sizeof(szSub), ',');
		lo.push_back(atof(szSub));

		strStream.getline(szSub, sizeof(szSub), ',');
		cl.push_back(atof(szSub));

		strStream.getline(szSub, sizeof(szSub), ',');
		vol.push_back((long)atof(szSub));

		strStream.getline(szSub, sizeof(szSub));
		adjcl.push_back(atof(szSub));

	};
	dataSize = adjcl.size() ;
	reverse();
}

void Data::setWebSite(string webSite)
{
	szWebSite = webSite;
}

void Data::setDataName(string dataName)
{
    dataName_ = dataName;
}

DataForGOOG::DataForGOOG()
{
	setDataName("GOOG");
	setWebSite("http://ichart.yahoo.com/table.csv?s=GOOG&a=02&b=27&c=2010&d=04&e=28&f=2016&g=d&ignore=.csv");
	downloadData();
}

Data * DataForGOOG::clone() const
{
	return new DataForGOOG(*this);
}

DataForSXP5::DataForSXP5()
{
	setDataName("S&P5");
	setWebSite("http://ichart.yahoo.com/table.csv?s=%5EGSPC&a=02&b=27&c=2010&d=04&e=28&f=2016&g=d&ignore=.csv");
	downloadData();
}

Data * DataForSXP5::clone() const
{
	return new DataForSXP5(*this);
}

