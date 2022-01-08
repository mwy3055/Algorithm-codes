#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

inline bool is_more(vector<int>& line, int& n, ll len)
{
	int sum = 0;
	for (int i : line)
		sum += i / len;
	return n <= sum;
}//true: len로 자를 때 k개 이상으로 쪼개짐

int prm_search(vector<int>& line, int& n, int& max)
{
	ll left = 1, right = max, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (is_more(line, n, mid))
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return is_more(line, n, mid) ? mid : mid - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, n, max = 0;
	cin >> k >> n;
	vector<int> line(k);
	for (int i = 0; i < k; i++)
	{
		cin >> line[i];
		max = max <= line[i] ? line[i] : max;
	}

	cout << prm_search(line, n, max);

}