#include <iostream>
#include <queue>
using namespace std;

typedef struct coord {
	int y, x;
	bool operator==(const coord& a) 
	{
		return this->y == a.y&&this->x == a.x;
	}
} coord;
inline bool isin(int i, int j, int l)
{
	return 0 <= i && i < l && 0 <= j && j < l;
}
int bfs(int& l, coord& s, coord& e)
{
	queue<coord> q;
	int src[8][2] = { {-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1} }, ans = 0;
	bool visit[300][300] = { false };

	q.push(s);
	visit[s.y][s.x] = true;
	while (true)
	{
		int siz = q.size();
		for (int i = 0; i < siz; i++)
		{
			coord& top = q.front();
			q.pop();
			if (top == e)
				return ans;
			for (int j = 0; j < 8; j++)
			{
				int sy = top.y + src[j][0], sx = top.x + src[j][1];
				if (isin(sy, sx, l) && !visit[sy][sx])
				{
					q.push({ sy, sx });
					visit[sy][sx] = true;
				}
			}
		}
		ans++;
	}
}

void solve()
{
	int l;
	coord start, end;
	cin >> l >> start.y >> start.x >> end.y >> end.x;
	cout << bfs(l, start, end) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}