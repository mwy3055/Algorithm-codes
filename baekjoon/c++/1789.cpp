#include <iostream>
using namespace std;

int main()
{
	long long s, n = 1;
	cin >> s;

	while (n*(n + 1) / 2 < s)n++;
	if (n*(n + 1) / 2 != s)n--;
	cout << n;
}