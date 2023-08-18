#include <stdio.h>

int ascending(int *arr)
{
	for (int i = 0; i < 7; i++)
		if (arr[i] >= arr[i + 1])
			return 0;
	return 1;
}
int descending(int *arr)
{
	for (int i = 0; i < 7; i++)
		if (arr[i] <= arr[i + 1])
			return 0;
	return 1;
}

int main()
{
	int arr[8];
	for (int i = 0; i < 8; i++)
		scanf("%d", arr + i);
	if (ascending(arr))
		printf("ascending");
	else if (descending(arr))
		printf("descending");
	else
		printf("mixed");
}