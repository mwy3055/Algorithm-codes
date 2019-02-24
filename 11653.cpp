#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> Pair;

void che(bool* prime, int N)
{
	fill(prime + 1, prime + N + 1, true);
	prime[1] = false;
	prime[2] = true;
	for (int i = 4; i <= N; i += 2)
		prime[i] = false;
	for (int i = 3; i <= (int)sqrt(N); i += 2)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= N; j += i)
				prime[j] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	bool* prime = new bool[n + 1]; //true이면 소수
	vector<Pair> ans;
	che(prime, n);
	int prnum = 2, temp = n;
	while (temp != 1)
	{
		int cnt = 0;
		while (temp%prnum == 0)
		{
			temp /= prnum;
			cnt++;
		}
		if (cnt != 0)
			ans.push_back(Pair(prnum, cnt));
		prnum++;
		while (prnum <= n && !prime[prnum])
			prnum++;
	}

	for (Pair t : ans)
	{
		int pr = t.first, cnt = t.second;
		for (int i = 0; i < cnt; i++)
			cout << pr << '\n';
	}


	delete[] prime;
}