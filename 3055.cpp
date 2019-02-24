#include <iostream>
#include <queue>
using namespace std;

struct coord {
	int y, x;
	bool operator==(coord b)
	{
		return (this->y == b.y)&&(this->x == b.x);
	}
};

int r, c;
char map[50][50];
bool wvisit[50][50], avisit[50][50];

inline bool isin(int i, int j)
{
	return map[i][j] != 'X' && (0 <= i && i < r && 0 <= j && j < c);
}
inline bool iswater(coord& s)
{
	return map[s.y][s.x] == '*';
}

int bfs(coord& s, coord& e)
{
	int src[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	queue<coord> q;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == '*')
			{
				q.push({ i,j });
				wvisit[i][j] = true;
			}
	q.push(s);
	avisit[s.y][s.x] = true;

	for (int t = 1; !q.empty(); t++)
	{
		coord top;
		while (iswater((top = q.front())))
		{
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int sy = top.y + src[i][0], sx = top.x + src[i][1];
				if (isin(sy, sx) && map[sy][sx] != 'D'&&!wvisit[sy][sx])
				{
					map[sy][sx] = '*';
					q.push({ sy,sx }); //고슴도치가 왔는데 물이 덮친다면, 큐에 있던 좌표는?
					wvisit[sy][sx] = true;
				}
			}
		}
		while (!iswater((top = q.front())))
		{
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int sy = top.y + src[i][0], sx = top.x + src[i][1];
				if (isin(sy, sx) && !avisit[sy][sx])
				{
					if (map[sy][sx] == '*')
						break;
					if (e == coord{ sy,sx })
						return t;
					q.push({ sy,sx });
					avisit[sy][sx] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	coord start, end;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
				start = { i,j };
			else if (map[i][j] == 'D')
				end = { i,j };
		}
	}

	int ans = bfs(start, end);
	if (ans)
		cout << ans;
	else
		cout << "KAKTUS";
}