#include <iostream>
#include <algorithm>
using namespace std;

struct coord {
	int y, x;
};

int map[9][9], eidx;
coord ec[81];
bool ans = false;

bool ispromising(coord& c)
{
	int& y = c.y, &x = c.x;

	//가로줄
	bool check[10] = { false };
	for (int j = 0; j < 9; j++)
	{
		if (map[y][j] == 0)
			continue;
		if (check[map[y][j]])
			return false;
		check[map[y][j]] = true;
	}

	//세로줄
	fill(check, check + 10, false);
	for (int i = 0; i < 9; i++)
	{
		if (map[i][x] == 0)
			continue;
		if (check[map[i][x]])
			return false;
		check[map[i][x]] = true;
	}

	//네모
	int sy = (y / 3) * 3, sx = (x / 3) * 3;
	fill(check, check + 10, false);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!map[sy + i][sx + j])
				continue;
			if (check[map[sy + i][sx + j]])
				return false;
			check[map[sy + i][sx + j]] = true;
		}
	}
	return true;
}

void dfs(int dep)
{
	if (dep == eidx)
	{
		ans = true;
		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		map[ec[dep].y][ec[dep].x] = i;
		if (ispromising(ec[dep]))
			dfs(dep + 1);
		if (ans)
			return;
	}
	map[ec[dep].y][ec[dep].x] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
				ec[eidx++] = { i,j };
		}
	}

	dfs(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << " ";
		cout << '\n';
	}
}