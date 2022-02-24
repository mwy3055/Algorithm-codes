#include <iostream>
#include <ctime>
using namespace std;
typedef long long ll;

ll mtp(ll a, ll b, ll c)
{
	if (b == 0)
		return 1;

	if (b % 2 == 1) return a * mtp(a, b - 1, c) % c;
	else
	{
		ll temp = mtp(a, b / 2, c);
		return (temp * temp) % c;
	}
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;

	cout << mtp(a%c, b, c);
}