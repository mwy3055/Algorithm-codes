#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, f;
	cin >> n >> f;
	n = (n / 100) * 100;
	while (n%f != 0) n++;
	int a = n % 10 + (n % 100 / 10) * 10;
	cout << setfill('0') << setw(2) << a;
}