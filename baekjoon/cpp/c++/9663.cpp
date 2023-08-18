#include <iostream>
using namespace std;

int ans = 0, n;
inline int abs(int a)
{
	return a > 0 ? a : -a;
}
bool is_promising(int* map, int n_curr)
{
	for (int i = 0; i < n_curr; i++)
	{
		if (map[i] == map[n_curr] || abs(map[i] - map[n_curr]) == n_curr - i)
			return false;
	}
	return true;
}
void solve(int* map, int n_curr)
{
	if (n == n_curr)
	{
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		map[n_curr] = i;
		if (is_promising(map, n_curr))
			solve(map, n_curr + 1);
	}
}
int main()
{
	cin >> n;
	int* map = new int[n];

	solve(map, 0);
	cout << ans;
	delete[] map;
}