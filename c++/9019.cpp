#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 10000;

char op[10000];
int path[10000]; //역추적용
bool visit[10000];

string bfs(int& a, int& b)
{
	queue<int> q;

	int tval;
	visit[a] = true;
	q.push(a);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (top == b)
			break;

		tval = (top * 2) % MOD;
		if (!visit[tval])
		{
			q.push(tval);
			path[tval] = top;
			op[tval] = 'D';
			visit[tval] = true;
			if (tval == b)
				break;
		}
		tval = top ? top - 1 : 9999;
		if (!visit[tval])
		{
			q.push(tval);
			path[tval] = top;
			op[tval] = 'S';
			visit[tval] = true;
			if (tval == b)
				break;
		}
		tval = (top % 1000) * 10 + top / 1000;
		if (!visit[tval])
		{
			q.push(tval);
			path[tval] = top;
			op[tval] = 'L';
			visit[tval] = true;
			if (tval == b)
				break;
		}
		tval = (top % 10) * 1000 + (top / 10);
		if (!visit[tval])
		{
			q.push(tval);
			path[tval] = top;
			op[tval] = 'R';
			visit[tval] = true;
			if (tval == b)
				break;
		}
	}

	string ans = "";
	int i = b;
	while (i != a)
	{
		ans += op[i];
		i = path[i];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, a, b;
	cin >> t;
	while (t--)
	{
		fill(op, op + 10000, NULL);
		fill(path, path + 10000, 0);
		fill(visit, visit + 10000, false);
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}
}