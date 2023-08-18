#include <iostream>
#include <algorithm>
using namespace std;
inline int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int* rope = new int[n];
	for (int i = 0; i < n; i++)
		cin >> rope[i];
	sort(rope, rope + n);

	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
		ans = max(ans, (n - i)*rope[i]);
	cout << ans;

	delete[] rope;
}