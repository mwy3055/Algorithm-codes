#include <stdio.h>
#include <string.h>

void readinput(char[],char[]);
int apcal(char[],char[]);
void printresult(int);

void main()
{
	char doc[2501],str[51];
	readinput(doc,str);
	printresult(apcal(doc,str));
}
void readinput(char doc[],char str[])
{
	gets(doc);
	gets(str);
}
int apcal(char doc[],char str[])
{
	int count=0,i,j;
	for(i=0;i<=(int)(strlen(doc)-strlen(str));)
	{
		int check;
		for(j=0;j<(int)strlen(str);j++)
		{
			if(doc[i+j]!=str[j])
			{
				check=0;
				break;
			}
			check=1;
		}
		if(check)
		{
			count++;
			i+=strlen(str);
		}
		else i++;
	}
	return count;
}

void printresult(int rst)
{
	printf("%d",rst);
}
