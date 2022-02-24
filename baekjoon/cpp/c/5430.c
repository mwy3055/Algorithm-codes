#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rmain();
//void exer(int*,int*);
int exed(int*,int*,int*);
void print(int*,int,int);

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
		rmain();
}

void rmain()
{
	int i = 0, n, tp = 0;
	char func[100001] = { 0 };
	scanf("%s", func);
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	/*for (j = 0; i < n; j++)
	{
		if (isdigit(inp[j]))
			arr[i] = arr[i] * 10 + (inp[j] - '0');
		else
			i++;
	}
	free(inp);*/
	while (i < n)
		scanf("%d", arr+(i++));
	printf("Func: %s\n", func);
	int fr = 0, bk = n - 1; //인덱스
	for (i = 0; i < (int)strlen(func); i++)
	{
		if ((i < (int)strlen(func) - 1) && (func[i] == 'R') && (func[i + 1] == 'R')) //RR=상쇄
			i++;
		else if (func[i] == 'R')
		{
			int temp = fr;
			fr = bk;
			bk = temp;
			/*if (dir)
				dir = 0;
			else
				dir = 1;*/
		}
		else if (func[i] == 'D')
			if (exed(arr, &fr, &bk))
			{
				puts("error");
				return;
			}
	}
//	printf("fr=%d, bk=%d\n", fr, bk);
	print(arr, fr, bk);
}
/*void exer(int* ar, int* siz)
{
	if (*siz == 0 || *siz == 1)
		return;
	int* temp = (int*)calloc(*siz, sizeof(int));
	memcpy(temp, ar, (*siz) * sizeof(int));
	for (int i = 0; i < *siz; i++)
		ar[i] = temp[*siz - 1 - i];
	free(temp);
}*/
int exed(int* ar, int* fr,int* bk)
{
	if (*bk == -1 || ar[*bk] == 0)
		return 1;
	else
	{
		if (*fr == *bk)
			ar[*fr] = 0;
		else
		{
			if (*fr < *bk) //정방향
				ar[(*fr)++] = 0;
			else           //역방향
				ar[(*fr)--] = 0;
		}
	}
	return 0;
	/*if (*siz == 0)
		return 1;
	else if (*siz == 1)
	{
		ar[0] = *siz = 0;
		return 0;
	}
	if (dir)
	{
		memmove(ar, ar + 1, *siz * sizeof(int));
		ar[(*siz)--] = 0;
	}
	else
		ar[(*siz)--] = 0;
	return 0;*/
}

void print(int* ar, int f, int b)
{
	printf("PR");
	int i;
	if (f == b)
	{
		if (ar[f])
			printf("[%d]a\n", ar[f]);
		else
			puts("[]b");
	}
	else
	{
		printf("[");
		if (f < 0 || b < 0)
			puts("]");
		else if (f > b)
		{
			for (i = f; i > b; i--)
				printf("%d,", ar[i]);
			printf("%d]c\n", ar[b]);
		}
		else
		{
			for (i = f; i < b; i++)
				printf("%d,", ar[i]);
			printf("%d]d\n", ar[b]);
		}
	}
}