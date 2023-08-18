#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
bool prime[1000001];

void che()
{
	fill(prime + 1, prime + MAX + 1, true);
	prime[1] = false;
	prime[2] = true;

	for (int i = 4; i <= MAX; i += 2) //Â¦¼ö´Â »©°í
		prime[i] = false;

	for (int i = 3; i <= (int)sqrt(MAX); i += 2) //È¦¼ö¸¸ °Ë»ç
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= MAX; j += i) //iÀÇ ¹è¼ö´Â ¸ðµÎ ¼Ò¼ö°¡ ¾Æ´Ô
				prime[j] = false;
		}
	}
}
void solve(int n)
{
	int a = 3, b = n - 3;
	while (!(prime[a] && prime[b]))
	{
		while (!prime[++a]);
		b = n - a;
	}
	cout << n << " = " << a << " + " << b << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	che();
	int n;
	cin >> n;
	do
	{
		solve(n);
		cin >> n;
	} while (n != 0);


}