#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b%a)
		return GCD(a, b%a);
	else
		return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long sum = 0;
		cin >> n;
		int* num = new int[n];
		for (int i = 0; i < n; i++)
			cin >> num[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				sum += GCD(num[i], num[j]);
			}
		}
		cout << sum << '\n';



		delete[] num;
	}
}