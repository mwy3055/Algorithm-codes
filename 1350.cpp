#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, csize, ans = 0;
	cin >> n;
	int* size = new int[n];
	for (int i = 0; i < n; i++)
		cin >> size[i];
	cin >> csize;
	for (int i = 0; i < n; i++)
	{
		if (size[i] == 0)
			continue;
		ans += ((size[i] - 1) / csize + 1)*csize;
	}

	cout << ans;
	delete[] size;
}