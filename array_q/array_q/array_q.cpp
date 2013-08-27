
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	FILE *pfin, *pfout;
	int i = 0, j = 0, k1 = 0, k2 = 0; 
	int tPos = 0,iPos = 0, mPos = 0;                       // check 'time' position is beside
	int qPos = 0, colonPos = 0;                            // check 'q:' position is beside
	int keypose = 0, joint_name = 0, joint _value = 0;     // save value to array
	int array_i = 0, array_j = 0, array _k = 0;

	pfin= fopen("fin_5.pseq","r");
	pfout = fopen ("layout_5.pseq","w");

	//float array [9][20][20];



	if(pfin == NULL || pfout == NULL )
	{
		printf("It can't be opened./n");
		system ("pause");
		return(0);
	}

	while(!feof(pfin))
	{
		ch = fgetc(pfin);
		i++;

//====== check 'time' position is beside ===========
		
		if (ch == 't')
		{	
			tPos = i;

		}

		if (ch == 'i')
		{
			iPos = i;
		}		

		if (ch == 'm')
		{
			mPos=i;
		}
					
		k1 = iPos-tPos;
		k2 = mPos-iPos;

		if (k1 == 1 && k2 == 1)
		{
			if(i == mPos)
			{
				fprintf(pfout, "\n\n\nTi");
			}

			fprintf(pfout, "%c", ch);
		}
		else
		{
			if (mPos > iPos && iPos > tPos )
			{
				tPos = 0;
				iPos = 0;
				mPos = 0;
			}
			
		}

		if (ch == '\n')
		{
			tPos=0;
			iPos=0;
			mPos=0;							
		}

//====== check 'q:' position is beside ================

		if (ch == 'q')
		{
			qPos = i;
		}

							
		if (ch == ':')
		{
			colonPos = i;	
		}

		


		// check 'q:'' the position is beside
							
		j=colonPos-qPos; 
							
		if (j == 1)
		{
			if(i == colonPos)
			{
				fprintf(pfout, "\nq");
			}

			fprintf(pfout, "%c",ch);
		}
		else 
		{
			if (colonPos > qPos)
			{
				qPos=0;
				colonPos=0;
							
			}
		}

		if (ch == ']')
		{
			qPos=0;
			colonPos=0;
			printf("\n");
								
		}


	}

	fclose(pfin);
	fclose(pfout);
	//system("pause");
	return(0);
}

	
