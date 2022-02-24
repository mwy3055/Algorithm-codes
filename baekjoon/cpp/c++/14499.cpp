#include <iostream>
using namespace std;

int map[20][20], val[7], roll[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int TOP = 1, FRONT = 2, BACK = 5, RIGHT = 3, LEFT = 4, BOTTOM = 6;
inline bool isin(int& x, int& y, int& n, int& m)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}
void move(int op)
{
	if (op == 1)
	{
		//top right bottom left를 오른쪽으로
		int temp = LEFT;
		LEFT = BOTTOM;
		BOTTOM = RIGHT;
		RIGHT = TOP;
		TOP = temp;
	}
	else if (op == 2)
	{
		//서쪽-top right bottom left를 왼쪽으로
		int temp = TOP;
		TOP = RIGHT;
		RIGHT = BOTTOM;
		BOTTOM = LEFT;
		LEFT = temp;
	}
	else if (op == 3)
	{
		//top front bottom back을 오른쪽으로
		int temp = BACK;
		BACK = BOTTOM;
		BOTTOM = FRONT;
		FRONT = TOP;
		TOP = temp;
	}
	else
	{
		//top front bottom back을 왼쪽으로
		int temp = TOP;
		TOP = FRONT;
		FRONT = BOTTOM;
		BOTTOM = BACK;
		BACK = temp;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	for (int i = 0; i < k; i++)
	{
		int op;
		cin >> op;
		int sx = x + roll[op - 1][0], sy = y + roll[op - 1][1];
		if (isin(sx, sy, n, m))
		{
			x = sx;
			y = sy;
			move(op);
			if (map[x][y] == 0)
			{
				map[x][y] = val[BOTTOM];
			}
			else
			{
				val[BOTTOM] = map[x][y];
				map[x][y] = 0;
			}
			cout << val[TOP] << '\n';
		}
	}
}