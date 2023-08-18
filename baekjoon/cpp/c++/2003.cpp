#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int* num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int s = 0, e = -1, sum = 0, ans = 0;
	while (s < n)
	{
		if (m <= sum) sum -= num[s++];
		else if (e == n - 1) break;
		else sum += num[++e];
		if (sum == m) ans++;
	}
	cout << ans;

	delete[] num;
}