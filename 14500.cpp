#include <iostream>
using namespace std;
typedef struct coord {
	int y, x;
} coord;
typedef struct polio {
	coord block[4];
} polio;
int map[500][500], n, m, ans;
polio polios[] = { {0,0,0,1,0,2,0,3},{0,0,0,1,1,0,1,1},{0,0,1,0,2,0,3,0},{0,0,1,0,2,0,2,1},{0,0,1,0,2,0,2,-1},
{0,0,0,1,1,0,2,0},{0,0,0,1,1,1,2,1},{0,0,1,0,1,1,2,1},{0,0,1,0,1,-1,2,-1},{0,0,0,1,1,0,1,-1},
{0,0,0,1,1,1,1,2},{0,0,0,1,0,2,1,1},{0,0,1,0,2,0,1,-1},{0,0,1,0,2,0,1,1},{0,0,1,-1,1,0,1,1},
{0,0,1,0,0,1,0,2},{0,0,0,1,0,2,1,2},{0,0,1,0,1,1,1,2},{0,0,1,-2,1,-1,1,0} };
inline bool isin(int y, int x)
{
	return 0 <= y && y < n && 0 <= x && x < m;
}
void check(int y, int x)
{
	int sum;
	for (int k = 0; k < 19; k++)
	{
		sum = 0;
		bool flag = true;
		for (int i = 0; i < 4; i++)
		{
			int sy = polios[k].block[i].y + y, sx = polios[k].block[i].x + x;
			if (isin(sy, sx))
				sum += map[sy][sx];
			else
			{
				flag = false;
				break;
			}
		}
		if (flag && ans < sum)
			ans = sum;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			check(i, j);

	cout << ans;
}