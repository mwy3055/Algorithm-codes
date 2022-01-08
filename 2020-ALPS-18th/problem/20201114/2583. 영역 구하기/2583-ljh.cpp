//�迭 �ε����� �򰥸��� �ʰ� 1���� �ҷ����ߴµ� �̹� �־��� ������ 0 0�� �����ϰ� �ִ� ���
//�ε����� 0���� �������� �������� �ε��� �Ǽ� ���� 
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int N, M, K, cnt;
bool check[MAX + 1][MAX + 1];
int board[MAX + 1][MAX + 1];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<int> v;

void dfs(int y, int x)
{
	check[y][x] = true;

	cnt++;

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && board[ny][nx] == 0 && !check[ny][nx])
		{
			dfs(ny, nx);
		}
	}
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int fx, fy, lx, ly;
		cin >> fx >> fy >> lx >> ly;
		for (int j = fy; j < ly; j++)
		{
			for (int k = fx; k < lx; k++)
			{
				board[j][k] = 1;
			}
		}
	}


	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0 && !check[i][j])
			{
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << '\n';

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
