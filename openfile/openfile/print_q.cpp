
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	int qTag,colonTag,beginTag=0;
	FILE *pfile;
	if((pfile = fopen("fin_4.txt","r"))== NULL )
	{
		printf("It can't be opened./n");
		system ("pause");
		return(0);
	}

	while (!feof(pfile))
	{
		ch= fgetc(pfile);
		if(ch == 'q')
		{
			qTag = 1;
		}
		if(qTag==1 && ch==':')
		{
			colonTag = 1;
		}
		if(qTag==1 && colonTag==1 && ch=='[')
		{
			beginTag = 1;
		}
	
	// Clean all tags
		if(beginTag == 1 && ch==']')
		{
			qTag = 0;
			colonTag = 0;
			beginTag = 0;
		}


	fclose(pfile);
	system("pause");
	return(0);
}

	