#include <stdio.h>
#include <stdlib.h>

void cmp(int*, int); //인덱스 값 조절

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int idx = m - 1, el = 0;
	char* alive = (char*)calloc(n, sizeof(char));
	int* order = (int*)calloc(n, sizeof(int));
	while (1)
	{
		cmp(&idx, n);
		if (alive[idx] == 0)
		{
			alive[idx] = 1;
			order[el++] = idx + 1;
		}
		else
		{
			while (alive[idx] == 1)
			{
				idx++;
				cmp(&idx, n);
			}
			alive[idx] = 1;
			order[el++] = idx + 1;
		}
		if (el == n) //모두 제거하면 탈출
			break;
		int temp = 0;
		while (temp < m)
		{
			idx++;
			cmp(&idx, n);
			if (!alive[idx])
				temp++;
		}
	}
	printf("<");
	for (int i = 0; i < n - 1; i++)
		printf("%d, ", order[i]);
	printf("%d>", order[n - 1]);
	free(alive);
	free(order);
}

void cmp(int* idx, int n)
{
	if (*idx >= n)
		(*idx) -= n;
}