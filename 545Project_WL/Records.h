
#include <stdio.h>
#define LOG_FILE	"Final_WL.txt"
#pragma once

//Singleton Pattern
class Records
{
public:
	static Records* getInstance();     // get Instance
	void print(char *format, ...);  // print into file

private:
	Records(void);				// cannot intantiate an object
	Records(Records const&){};    // cannot copy
	Records& operator=(const Records&){};
	~Records(void);

	FILE *m_pf;
	static Records* m_pInstance;

};

