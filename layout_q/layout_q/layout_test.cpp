
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	FILE *pfin, *pfout;
	int qTag=0, colonTag=0, beginTag=0;
	pfin= fopen("fin_4.txt","r");
	pfout = fopen ("layout_q.txt","w");

	if(pfin== NULL || pfout == NULL )
	{
		printf("It can't be opened./n");
		system ("pause");
		return(0);
	}


	while (!feof(pfin))
	{
		ch= fgetc(pfin);
		if(ch=='q')
		{
			fprintf(pfout,"%c",ch);
		}



	}

	fclose(pfin);
	fclose(pfout);
	system("pause");
	return(0);
}

	
