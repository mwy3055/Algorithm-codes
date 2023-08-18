#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k, op;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++)
	{
		cin >> op;
		if (op) s.push(op);
		else s.pop();
	}

	int siz = s.size(), sum = 0;
	for (int i = 0; i < siz; i++)
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
}