#include <iostream>
using namespace std;

typedef pair<int, int> coord; //x,y
typedef pair<coord, bool> animal;
inline int max(int a, int b)
{
	return a < b ? a : b;
}
inline int abs(int a)
{
	return a > 0 ? a : -a;
}
int dist(animal a, int b)
{
	return a.first.second + abs(a.first.first - b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int m, n, l;
	cin >> m >> n >> l;
	bool* gun = new bool[m];
	animal* anm = new animal[n];

	for (int i = 0; i < m; i++)
	{
		int g;
		cin >> g;
		gun[g] = true;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> anm[i].first.first >> anm[i].first.second;
		anm[i].second = false;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = max(1,j+anm[i].first.first); j <= anm[i].first.first+l; j++)
		{
			int x = j + anm[i].first.first;
			if (x <= 0)
				continue;

			if (gun[x])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;


	delete[] anm;
	delete[] gun;
}