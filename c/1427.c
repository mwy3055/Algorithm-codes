#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main()
{
	int i = 0, input, num[15] = { 0 }, length = 0;
	scanf("%d", &input);
	while(input) //자릿수 1개씩 분리
	{
		length++;
		num[i++] = input % 10;
		input /= 10;
	}

	qsort(num, i, sizeof(int), compare); //i 대신 length 써도 됨

	for (i = 0; i<length; i++)
		printf("%d", num[i]);
}

int compare(const void* n1, const void* n2) //내림차순 정렬
{
	if (*(int*)n1 > *(int*)n2)
		return -1;
	else if (*(int*)n1 < *(int*)n2)
		return 1;
	else
		return 0;
}