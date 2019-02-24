#include <iostream>
#include <queue>
using namespace std;

typedef struct area {
	int y, x, r;
	bool visit;
} area;

inline int sq(int i)
{
	return i * i;
}
inline bool adj(area& i, area& j)
{
	return (sq(i.r + j.r)) >= (sq(i.x - j.x) + sq(i.y - j.y));
}
void solve();
void bfs(area*, int, int);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}

void solve()
{
	int n, cnt = 0;
	cin >> n;
	area* a = new area[n];
	for (int i = 0; i < n; i++)
	{
		int x, y, r;
		cin >> x >> y >> r;
		a[i] = { x,y,r,false };
	}

	for (int i = 0; i < n; i++)
	{
		if (!a[i].visit)
		{
			bfs(a, n, i);
			cnt++;
		}
	}






	cout << cnt << '\n';
	delete[] a;
}

void bfs(area* a, int n, int start)
{
	queue<pair<int, area>> q;

	a[start].visit = true;
	q.push(make_pair(start, a[start]));
	while (!q.empty())
	{
		int t = q.front().first;
		area now = q.front().second;
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (i == t) continue;
			if (!a[i].visit && adj(a[i], now))
			{
				a[i].visit = true;
				q.push(make_pair(i, a[i]));
			}
		}
	}
}