#pragma GCC optimize("Ofast")
#include <iostream>
using namespace std;

int org[13], n;
bool sub[13];

void dfs(int i, int cnt)
{
	if (i == n)
	{
		if (cnt == 6)
		{
			for (int i = 0; i < n; i++)
				if (sub[i])
					cout << org[i] << " ";
			cout << '\n';
		}
		return;
	}
	sub[i] = true;
	dfs(i + 1, cnt + 1);
	sub[i] = false;
	dfs(i + 1, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while (n!=0)
	{
		for (int i = 0; i < n; i++)
			cin >> org[i];
		sub[0] = true;
		dfs(1, 1);
		sub[0] = false;
		dfs(1, 0);
		cout << '\n';
		cin >> n;
	}
}