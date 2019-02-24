#include <iostream>
#include <vector>
using namespace std; 
typedef long long ll;
inline bool is_less(vector<int>& line, int& n, ll len)
{
	int sum = 0;
	for (int i : line)
		sum += i / len;
	return sum < n;
}
//시간 초과
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

	while (is_less(line, n, max--));
	cout << max + 1;
}