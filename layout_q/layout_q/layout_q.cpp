
#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

int _tmain(int argc, _TCHAR* argv[])
{
	char ch;
	FILE *pfin, *pfout;
	int i = 0, j = 0, k1 = 0, k2 = 0;
	int tPos = 0,iPos = 0, mPos = 0;
	int qPos = 0, colonPos = 0;
	pfin= fopen("fin_4.txt","r");
	pfout = fopen ("layout_q2.txt","w");

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
		//fprintf(pfout, "qPos=%d\n",qPos);
							
		if (ch == ':')
		{
			colonPos = i;	
		}
		//fprintf(pfout, "colonPos=%d\n",colonPos);
		


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

	
