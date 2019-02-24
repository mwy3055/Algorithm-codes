#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int qsel(int,int,int);
int sort(int,int);
int arr[5000000];

#define swap(a, b) {int temp=a;a=b;b=temp;}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	printf("%d", qsel(0, n - 1, k));
}

int qsel(int l, int r, int k) //Quick Selection. left, right, kth
{
	int pos = sort(l, r);
	if (pos - l == k - 1)
		return arr[pos];
	else if (pos - l > k - 1)
		return qsel(l, pos - 1, k);
	else
		return qsel(pos + 1, r, k - pos + l - 1);
}
int sort(int l, int r) //임시정렬할 처음, 나중 인덱스
{
	int pivot = arr[l];
	int lf = l + 1, rf = r;
	while (lf <= rf)
	{
		while (lf <= r && arr[lf] <= pivot)
			lf++;
		while (rf >= l + 1 && arr[rf] >= pivot)
			rf--;
		if (lf <= rf)
			swap(arr[lf], arr[rf]);
	}
	swap(arr[l], arr[rf]);
	return rf;
}