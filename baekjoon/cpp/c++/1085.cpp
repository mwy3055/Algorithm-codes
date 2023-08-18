#include <iostream>
using namespace std;

inline int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int x, y, h, w;
	cin >> x >> y >> w >> h;

	cout << min(x, min(w - x, min(y, h - y)));
}