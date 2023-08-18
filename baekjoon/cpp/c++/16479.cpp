#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int k, d1, d2;
	cin >> k >> d1 >> d2;
	if (d1 == d2)
		cout << k * k;
	else
	{
		int d = (d1 - d2) / 2;
		cout << (k*k) - (d*d);
	}
}