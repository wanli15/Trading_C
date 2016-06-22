#include "Records.h"
#include <iostream>
#include "Records.h"
#include <stdarg.h>
#include <fstream>
using namespace std;

Records* Records::m_pInstance = new Records();

Records::Records(void)
{
	fopen_s(&m_pf, LOG_FILE, "a"); // open file at first time
}

Records::~Records(void)
{
	if (m_pf) fclose(m_pf); // close file
}


Records* Records::getInstance()
{
	return m_pInstance;
}


void Records::print(char *format, ...) // wrtie formated string into file
{
	va_list marker;
	va_start(marker, format);     /* Initialize variable arguments. */
	vfprintf(m_pf, format, marker);
	va_end(marker);
	fflush(m_pf);
}
