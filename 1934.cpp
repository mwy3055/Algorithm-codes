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
		int a, b;
		cin >> a >> b;
		cout << a * b / GCD(a, b) << '\n';
	}
}