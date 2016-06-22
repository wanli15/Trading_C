//
//                 downloadFile.cpp
//
//


#include <tchar.h>
#include <urlmon.h>
#include "downloadFile.h"


void downloadFile(const std::string & szWebSite, std::stringstream &strStream)
{
	IStream* pStream=0;

	URLOpenBlockingStream( 0, szWebSite.c_str(), &pStream, 0, 0); // Open WebLink
	if (pStream==0) return ;  // failure 

	while( pStream!=0 )
	{
		DWORD dwGot=0;
		char szBuffer[200]="";

		if (pStream->Read( szBuffer, sizeof(szBuffer)-1, &dwGot )!=S_OK)	
			break; 

		strStream << szBuffer; 
	};

	if (pStream)	pStream->Release();
};