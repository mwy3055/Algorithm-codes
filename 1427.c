#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main()
{
	int i = 0, input, num[15] = { 0 }, length = 0;
	scanf("%d", &input);
	while(input) //�ڸ��� 1���� �и�
	{
		length++;
		num[i++] = input % 10;
		input /= 10;
	}

	qsort(num, i, sizeof(int), compare); //i ��� length �ᵵ ��

	for (i = 0; i<length; i++)
		printf("%d", num[i]);
}

int compare(const void* n1, const void* n2) //�������� ����
{
	if (*(int*)n1 > *(int*)n2)
		return -1;
	else if (*(int*)n1 < *(int*)n2)
		return 1;
	else
		return 0;
}