#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int sum(priority_queue<int, vector<int>, greater<int>> q)
{
	int result = 0;
	while (!q.empty())
	{
		result += q.top();
		q.pop();
	}
	return result;
}

int main()
{
	priority_queue<int, vector<int>, greater<int>> v;
	int x, temp;
	cin >> x;

	v.push(64);
	while ((temp = sum(v)) != x)
	{
		int shortest = v.top();
		v.pop();
		if (temp - shortest / 2 < x)
			v.push(shortest / 2);
		v.push(shortest / 2);
	}
	if (v.top() == 0)
		v.pop();

	cout << v.size();
}