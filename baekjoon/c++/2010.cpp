#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, sum = 0, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		sum += temp;
	}
	cout << sum - (n - 1);
}