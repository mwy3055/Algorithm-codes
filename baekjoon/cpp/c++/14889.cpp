#include <iostream>
#include <vector>
using namespace std;

int map[20][20], n, ans = 0x7fffffff;
bool team[20]; //true:스타트,false:링크

inline int min(int a, int b)
{
	return a < b ? a : b;
}
void search(int dep)
{
	if (dep == n)
		return;
	if (ans == 0)
		return;

	//n-1-dep명이 남음.
	int snum = 0, lnum = 0;
	for (int i = 0; i < dep; i++)
		team[i] ? snum++ : lnum++;
	if (snum == n / 2)
	{
		vector<int> start, link;
		int ss = 0, sl = 0;
		for (int i = 0; i < n; i++)
			team[i] ? start.push_back(i) : link.push_back(i);
		for (int i : start)
			for (int j : start)
				ss += map[i][j];
		for (int i : link)
			for (int j : link)
				sl += map[i][j];
		ans = min(ans, abs(ss - sl));
	}

	team[dep] = true;
	search(dep + 1);
	team[dep] = false;
	search(dep + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	search(0);
	cout << ans;
}