#include <stdio.h>

int main()
{
	int n, sti = 0, opi = 0, num = 0; //���� �� ���� �ε���
	int stack[100000] = { 0 };
	char output[200001] = { 0 }; //����� ����� �����ϴ� �迭
	scanf("%d", &n);
	while (n--)
	{
		int temp;
		scanf("%d", &temp);
		if (stack[sti] == temp)
		{
			if (sti > 0)
				stack[sti--] = 0;
			else if (sti == 0)
				stack[sti] = 0;
			output[opi++] = '-';

		}
		else if (stack[sti] < temp)
		{
			if (num + 1 > temp) 
			{
				puts("NO");
				return 0;
			}
			while (num + 1 <= temp)
			{
				output[opi++] = '+';
				if (stack[sti] == 0)
					stack[sti] = num + 1;
				else
					stack[++sti] = num + 1;
				num++;
			}
			if (sti > 0)
				stack[sti--] = 0;
			else if (sti == 0)
				stack[sti] = 0;
			output[opi++] = '-';
		}
		else
		{
			puts("NO");
			return 0;
		}
		printf("sti: %d\n", sti);
	}
	n = 0;
	while (n<opi)
		printf("%c\n", output[n++]);
}
//sti���� ������ �������� ��찡 ��������.