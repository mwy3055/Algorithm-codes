#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, cnt = 0;
	cin >> n >> k;
	vector<bool> prime(n + 1, true);

	while (true)
	{
		int p = 1;
		while (!prime[++p]);
		for (int i = p; i <= n; i += p)
		{
//			cout << i << '\n';
			if (prime[i])
			{
				prime[i] = false;
				cnt++;
			}
			if (cnt == k)
			{
				cout << i;
				return 0;
			}
		}
	}
}