#include <iostream>
#include <algorithm>
using namespace std;

void find(int& a, int& b, int& sum,int* arr)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				a = i;
				b = j;
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int h[9], sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> h[i];
		sum += h[i];
	}
	sort(h, h + 9);

	int a, b;
	find(a, b, sum, h);
	for (int i = 0; i < 9; i++)
	{
		if (i == a || i == b)
			continue;
		cout << h[i] << '\n';
	}
}