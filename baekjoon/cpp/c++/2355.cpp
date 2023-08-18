#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long a, b;
	cin >> a >> b;
	if (a == b)
		cout << a;
	else
	{
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		cout << (b * (b + 1) / 2) - ((a - 1)*a / 2);
	}
}