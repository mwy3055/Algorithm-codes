#include <iostream>
using namespace std;
int root[1000001];
int find(int i)
{
	if (root[i] == i) 
		return i;
	else 
		return root[i] = find(root[i]);
}
void Union(int a, int b)
{
	if (a > b) swap(a, b);
	int pa = find(a), pb = find(b);
	root[pb] = pa;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		root[i] = i;

	int op, a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> op >> a >> b;
		if (op)
			cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
		else
			Union(a, b);
	}
}