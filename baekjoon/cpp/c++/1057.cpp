#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, K, L, stage = 1;
	cin >> n >> K >> L;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (true)
	{
		if (K == L) break;

		int nidx = 1;
		for (int i = 1; i <= n; i++)
		{
			q.pop();
			if (i == K)
				K = nidx;
			if (i == L)
				L = nidx;
			if (i % 2 == 0)
			{
				q.push(nidx++);
			}
		}
		n = (int)(n / 2.0 + 0.5);
		stage++;
	}
	cout << stage-1;
}