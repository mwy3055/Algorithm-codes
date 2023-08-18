#include <iostream>
#include <cmath>
using namespace std;
bool isSquare(int i)
{
	int sq = sqrt(i);
	return (i == sq * sq);
}

int main()
{
	int n, m, sum = 0;
	cin >> m >> n;
	int rt_m = sqrt(m), rt_n = sqrt(n);
	int l_bound = (rt_m*rt_m == m) ? (rt_m) : (rt_m + 1), r_bound = rt_n;
	for (int i = l_bound; i <= r_bound; i++)
		sum += i * i;

	cout << l_bound << " " << r_bound << '\n';

	if (rt_m == rt_n && !isSquare(m) && !isSquare(n))
		cout << -1;
	else
		cout << sum << '\n' << l_bound * l_bound;
}