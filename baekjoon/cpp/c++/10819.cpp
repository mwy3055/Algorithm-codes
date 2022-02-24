#include <iostream>
#include <algorithm>
using namespace std;
inline int abs(int a) { return a > 0?a:-a; }
int main()
{
	int n, sum = 0;
	cin >> n;
	int* org = new int[n];
	int* arr = new int[n]; //¿Ï¼º
	for (int i = 0; i < n; i++)
		cin >> org[i];
	sort(org, org + n);

	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		int nth = (n - 1) / 2 - i;
		if (i % 2)
			arr[i] = org[n - 1 - nth];
		else
			arr[i] = org[nth];
	}
	for (int i = (n - 1) / 2 + 1; i < n; i++)
	{
		int nth = i - ((n - 1) / 2 + 1);
		if (i % 2)
			arr[i] = org[n - 1 - nth];
		else
			arr[i] = org[nth];
	}
	for (int i = 0; i < n - 1; i++)
		sum += abs(arr[i] - arr[i + 1]);

	if (n % 2)
	{
		int tsum = 0;
		for (int i = (n - 1) / 2; i >= 0; i--)
		{
			int nth = (n - 1) / 2 - i;
			if (i % 2)
				arr[i] = org[nth];
			else
				arr[i] = org[n - 1 - nth];
		}
		for (int i = (n - 1) / 2 + 1; i < n; i++)
		{
			int nth = i - ((n - 1) / 2 + 1);
			if (i % 2)
				arr[i] = org[nth];
			else
				arr[i] = org[n - 1 - nth];
		}
		for (int i = 0; i < n - 1; i++)
			tsum += abs(arr[i] - arr[i + 1]);
		if (sum < tsum)
			sum = tsum;
	}

	cout << sum;

	delete[] org;
	delete[] arr;
}