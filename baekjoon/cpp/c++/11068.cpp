#include <iostream>
#include <vector>
using namespace std;

bool palin_num(int n, int b) //십진법 수 n을 b진법으로 바꿔보자
{
	vector<int> v;
	while (n / b)
	{
		v.push_back(n%b);
		n /= b;
	}
	v.push_back(n);
	int s = 0, e = v.size() - 1;
	while (s <= e)
	{
		if (v[s++] != v[e--]) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int a, flag = 0;
		cin >> a;
		for (int i = 2; i <= 64; i++)
		{
			if (palin_num(a, i))
			{
				flag = 1;
				break;
			}
		}
		cout << flag << '\n';
	}
}