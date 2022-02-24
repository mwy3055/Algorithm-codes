#include <iostream>
#include <queue>
using namespace std;

class coord {
public:
	int y, x;
	coord(int y, int x):y(y),x(x){}
};
inline bool isin(int& i,int& j, int& h, int& w)
{
	return 0 <= i && i < h && 0 <= j && j < w;
}
void bfs(coord s, int& h, int& w, bool(*map)[50], bool(*visit)[50])
{
	queue<coord> q;
	int src[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };

	map[s.y][s.x] = true;
	q.push(s);
	while (!q.empty())
	{
		coord& top = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int sy = top.y + src[i][0], sx = top.x + src[i][1];
			if (isin(sy, sx, h, w) && map[sy][sx] && !visit[sy][sx])
			{
				q.push(coord(sy, sx));
				visit[sy][sx] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int w, h;
	cin >> w >> h;
	while (!(w == 0 || h == 0))
	{
		bool map[50][50]; //true:land,false:sea
		bool visit[50][50] = { false };
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		int ans = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] && !visit[i][j])
				{
					bfs(coord(i, j), h, w, map, visit);
					ans++;
				}
			}
		}
		cout << ans << '\n';
		cin >> w >> h;
	}
}