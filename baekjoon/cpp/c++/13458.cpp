#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int b, c;
	long long ans = 0;
	cin >> b >> c;
	for (int i = 0; i < n; i++)
	{
		int left = arr[i] - b;
		ans++;
		if (left <= 0)
			continue;
		if (left%c)
			ans += left / c + 1;
		else
			ans += left / c;
	}

	cout << ans;
	delete[] arr;
}