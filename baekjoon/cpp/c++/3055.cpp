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
	int widx = 0, sidx = 1;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (map[i][j] == '*')
			{
				q.push({ i,j });
				wvisit[i][j] = true;
				widx++;
			}
	q.push(s);
	avisit[s.y][s.x] = true;


	for (int t = 1; !q.empty(); t++)
	{
		int wtemp = 0, stemp = 0;
		coord top;
		for (int k = 0; k < widx; k++)
		{
			top = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int sy = top.y + src[i][0], sx = top.x + src[i][1];
				if (isin(sy, sx) && map[sy][sx] != 'D' && !wvisit[sy][sx])
				{
					map[sy][sx] = '*';
					q.push({ sy,sx });
					wvisit[sy][sx] = true;
					wtemp++;
				}
			}
		}

		for (int k = 0; k < sidx; k++)
		{
			top = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int sy = top.y + src[i][0], sx = top.x + src[i][1];
				if (isin(sy, sx) && !avisit[sy][sx] && map[sy][sx] != '*')
				{
					if (map[sy][sx] == 'D')
						return t;
					q.push({ sy,sx });
					avisit[sy][sx] = true;
					stemp++;
				}
			}
		}
		widx = wtemp;
		sidx = stemp;
	}
	return 0;
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