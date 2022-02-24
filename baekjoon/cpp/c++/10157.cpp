#include <iostream>
using namespace std;

typedef pair<int, int> coord; //x, y
coord operator+(coord a, coord b)
{
	return coord(a.first + b.first, a.second + b.second);
}

bool map[1001][1001];
int c, r, k;
inline bool is_end(coord now, int dir)
{
	switch (dir)
	{
	case 0:
		return now.second == r;
	case 1:
		return now.first == c;
	case 2:
		return now.second == 1;
	default:
		return now.first == 1;
	}
}

inline bool is_visited(coord next)
{
	return map[next.first][next.second];
}

int main()
{
	cin >> c >> r >> k;
	if (c*r < k)
	{
		cout << 0;
		return 0;
	}

	coord dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
	coord curr = coord(1, 1);
	int didx = 0;
	map[1][1] = true;
	for (int i = 1; i <= k - 1; i++)
	{
		curr = curr + dir[didx];
		map[curr.first][curr.second] = true;
		if (is_end(curr, didx) || is_visited(curr + dir[didx]))
		{
			didx = (didx + 1) % 4;
		}
	}
	cout << curr.first << " " << curr.second;
}