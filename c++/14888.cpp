#include <iostream>
#include <algorithm>
using namespace std;

int num[11], n, op[4], used[10], used_num[4], MIN = 0x7fffffff, MAX = 0x80000001; //used[i]:i, i+1번 숫자 사이의 연산자
enum
{
	PLUS,
	MINUS,
	MULT,
	DIV
};

int calc()
{
	int ans = num[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (used[i] == 0)
			ans += num[i + 1];
		else if (used[i] == 1)
			ans -= num[i + 1];
		else if (used[i] == 2)
			ans *= num[i + 1];
		else
			ans /= num[i + 1];
	}
	return ans;
}
void dfs(int i)
{
	if (i == n - 1)
	{
		int cal = calc();
		MIN = min(MIN, cal);
		MAX = max(MAX, cal);
		return;
	}
	
	for (int j = 0; j < 4; j++)
	{
		if (used_num[j] < op[j])
		{
			used[i] = j;
			used_num[j]++;
			dfs(i + 1);
			used_num[j]--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int& i : op)
		cin >> i;

	dfs(0);
	cout << MAX << '\n' << MIN;
}