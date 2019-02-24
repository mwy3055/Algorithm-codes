#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	vector<bool> prime(n + 1, true);
	prime[1] = false;
	for (int i = 4; i <= n; i += 2)
		prime[i] = false;
	for (int i = 3; i <= (int)sqrt(n); i += 2)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
	
	for (int i = m; i <= n; i++)
		if (prime[i])
			cout << i << '\n';
}