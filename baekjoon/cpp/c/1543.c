#include <stdio.h>
#include <string.h>


int main()
{
	int count = 0;
	char doc[2501], str[51];
	gets(doc);
	gets(str);
	char* temp = strstr(doc, str); //strstr:doc에 str이 있으면 doc에서의 처음 주소를 반환. 없으면 NULL 반환.
	while (temp != NULL)
	{
		count++;
		temp = strstr(temp + strlen(str) * sizeof(char), str);
	}
	printf("%d", count);
}

/*void readinput(char[], char[]);
int apcal(char[], char[]);
void printresult(int);


void main()
{
	char doc[2501], str[51];
	readinput(doc, str);
	printresult(apcal(doc, str));
}

void readinput(char doc[], char str[])
{
	gets(doc);
	gets(str);
}

int apcal(char doc[], char str[])
{
	int count = 0;
	int i, j;
	for (i = 0; i <= strlen(doc) - strlen(str); )
	{
		int check;
		for (j = 0; j < strlen(str); j++)
		{
			if (doc[i + j] != str[j])
			{
				check = 0;
				break;
			}
			check = 1;
		}
		if (check)
		{
			count++;
			i += strlen(str);
		}
		else
			i++;
	}
	return count;
}

void printresult(int rst)
{
	printf("%d", rst);
}*/