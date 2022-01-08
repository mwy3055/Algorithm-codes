#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, pair<int, int>> Medal;
typedef pair<Medal, int> Country; //메달, 순위
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	Medal temp;
	cin >> n >> k;
	Country* arr = new Country[n];
	for (int i = 0; i < n; i++)
	{
		int t, a, b, c;
		cin >> t >> a >> b >> c;
		arr[i].first = Medal(a, { b, c });
		if (k == t)
			temp = arr[i].first;
	}
	sort(arr, arr + n);

	for (int i = n - 1; i >= 0; i--)
	{
		if (i < n - 1 && arr[i + 1].first == arr[i].first)
			arr[i].second = arr[i + 1].second;
		else
			arr[i].second = n - i;

		if (arr[i].first == temp)
		{
			cout << arr[i].second;
			break;
		}
	}


	delete[] arr;
}