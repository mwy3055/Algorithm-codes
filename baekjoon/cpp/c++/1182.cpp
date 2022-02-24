#include <iostream>
using namespace std;

int org[20], n, s, ans;

void dfs(int i, int sum, bool nullset) //i번째 수를 보는 중
{
	if (i == n)
	{
		if (nullset&&sum == s)
			ans++;
		return;
	}
	dfs(i + 1, sum + org[i], nullset | true);
	dfs(i + 1, sum, nullset);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> org[i];

	dfs(1,org[0],true);
	dfs(1, 0, false);
	cout << ans;
}