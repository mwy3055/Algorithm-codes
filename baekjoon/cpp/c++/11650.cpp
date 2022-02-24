#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> Pair;

bool compare(const Pair& a, const Pair& b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<Pair> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back(Pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	for (Pair i : v)
		cout << i.first << " " << i.second << '\n';
}