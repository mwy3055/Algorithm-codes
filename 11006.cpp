#include <iostream>
using namespace std;

void solve()
{
	int n, m, s;
	cin >> n >> m;
	s = m;
	while (n != s)
		n -= 2, s--;
	cout << s << " " << m - s << '\n';
}

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