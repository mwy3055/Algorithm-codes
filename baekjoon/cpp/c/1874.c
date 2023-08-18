#include <stdio.h>

int main()
{
	int n, sti = 0, opi = 0, num = 0; //뒤의 세 개는 인덱스
	int stack[100000] = { 0 };
	char output[200001] = { 0 }; //출력할 결과를 저장하는 배열
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
//sti값이 음수로 떨어지는 경우가 문제였다.