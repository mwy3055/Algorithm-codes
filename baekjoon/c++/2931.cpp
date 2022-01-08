#include <bits/stdc++.h>
using namespace std;

struct node
{
	int y, x, dir; // 아래의 인덱스를 따름
	node(int y = 0, int x = 0, int dir = 0) : y(y), x(x), dir(dir) {}
};
const int INF = 99999;
int r, c, cnt, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char board[25][26], block[] = {'|', '-', '+', '1', '2', '3', '4'};
node m, z;

bool isin(int y, int x)
{
	return 0 <= y && y < r && 0 <= x && x < c;
}
bool isin(node &n)
{
	return 0 <= n.y && n.y < r && 0 <= n.x && n.x < c;
}
int rotate(int y, int x, int dir)
{
	if (board[y][x] == '|' && dir % 2)
		return dir;
	else if (board[y][x] == '-' && dir % 2 == 0)
		return dir;
	else if (board[y][x] == '+')
		return dir;
	else if (board[y][x] == '1' && dir == 3)
		return 0;
	else if (board[y][x] == '1' && dir == 2)
		return 1;
	else if (board[y][x] == '2' && dir == 1)
		return 0;
	else if (board[y][x] == '2' && dir == 2)
		return 3;
	else if (board[y][x] == '3' && dir == 1)
		return 2;
	else if (board[y][x] == '3' && dir == 0)
		return 3;
	else if (board[y][x] == '4' && dir == 0)
		return 1;
	else if (board[y][x] == '4' && dir == 3)
		return 2;
	return INF;
}
void start(node &n)
{
	auto &y = n.y, &x = n.x, &dir = n.dir;
	dir = -1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + src[i][0], nx = x + src[i][1];
		if (isin(ny, nx) && board[ny][nx] != '.')
		{
			dir = i;
			return;
		}
	}
}
bool cango(node &cur, int &left)
{
	while (isin(cur))
	{
		if (board[cur.y][cur.x] == '.')
			return false;
		auto &dir = cur.dir;
		cur.y += src[dir][0], cur.x += src[dir][1];
		if (board[cur.y][cur.x] == 'Z')
			return true;
		auto ndir = rotate(cur.y, cur.x, dir);
		if (ndir == INF)
			return false;
		dir = ndir;
		left--;
	}
	return left <= 0;
}

bool canstart(node &cur) // (y, x)에서 dir 방향으로 갈 수 있는지
{
	auto &dir = cur.dir;
	int ny = cur.y + src[dir][0], nx = cur.x + src[dir][1];
	if (board[ny][nx] == '|' && dir % 2)
		return true;
	else if (board[ny][nx] == '-' && dir % 2 == 0)
		return true;
	else if (board[ny][nx] == '+')
		return true;
	else if (board[ny][nx] == '1' && (dir == 2 || dir == 3))
		return true;
	else if (board[ny][nx] == '2' && (dir == 1 || dir == 2))
		return true;
	else if (board[ny][nx] == '3' && (dir == 0 || dir == 1))
		return true;
	else if (board[ny][nx] == '4' && (dir == 0 || dir == 3))
		return true;
	return false;
}
void solve1(node cur)
{
	for (int i = 0; i < 4; i++)
	{
		auto test = cur;
		int ny = test.y + src[i][0], nx = test.x + src[i][1];
		test.dir = i;
		if (isin(ny, nx))
		{
			for (int b = 0; b < 7; b++)
			{
				board[ny][nx] = block[b];
				if (canstart(test) && cango(test, cnt))
				{
					cout << ny + 1 << ' ' << nx + 1 << ' ' << block[b];
					return;
				}
			}
		}
	}
}
void solve2(node cur)
{
	int count = cnt;
	cango(cur, count);

	int ny = cur.y, nx = cur.x;
	cur.y -= src[cur.dir][0], cur.x -= src[cur.dir][1];
	for (int b = 0; b < 7; b++)
	{
		board[ny][nx] = block[b];
		if (canstart(cur))
		{
			auto test = cur;
			auto tcount = count;
			if (cango(test, tcount))
			{
				cout << ny + 1 << ' ' << nx + 1 << ' ' << block[b];
				return;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'M')
				m = node(i, j);
			else if (board[i][j] == 'Z')
				z = node(i, j);
			if (board[i][j] != 'M' && board[i][j] != 'Z' && board[i][j] != '.')
				cnt++;
		}
	}

	node cur = m;
	start(cur);
	if (cur.dir == -1)
	{
		// 시작점에서 나갈 수 없음
		solve1(cur);
	}
	else
	{
		// 일단 출발해 보자
		solve2(cur);
	}
}