#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	long rst = 1;
	cin >> n;
	int* divisor = new int[n];
	for (int i = 0; i < n; i++)
		cin >> divisor[i];
	sort(divisor, divisor + n);
	rst = divisor[0] * divisor[n - 1];
	cout << rst;
	delete[] divisor;
}