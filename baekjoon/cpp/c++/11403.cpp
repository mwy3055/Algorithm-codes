#include <iostream>
using namespace std;

void floyd_warshall(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	floyd_warshall(n);
}

void floyd_warshall(int n) //n*n 맵
{
	int i, j, k;
	bool** adj = new bool*[n];
	for (i = 0; i < n; i++)
		adj[i] = new bool[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> k;
			adj[i][j] = k ? true : false;
		}
	}

	for (k = 0; k < n; k++)          //거쳐가는 점
	{
		for (i = 0; i < n; i++)      //출발점
		{
			for (j = 0; j < n; j++)  //도착점
			{
				if (adj[i][j])
					continue;
				else
					adj[i][j] = adj[i][k] & adj[k][j];
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << (adj[i][j] ? 1 : 0) << " ";
		}
		cout << '\n';
	}

	for (i = 0; i < n; i++)
		delete[] adj[i];
	delete[] adj;
}