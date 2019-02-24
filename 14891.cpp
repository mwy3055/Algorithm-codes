#include <iostream>
#include <string>
using namespace std;

class gear
{
public:
	string tooth;
	int flag;
	gear() :tooth(""), flag(0) {}
	void turn()
	{
		if (flag == 1)
		{
			tooth = tooth[7] + tooth.substr(0, 7);
		}
		else if (flag == -1)
		{
			tooth = tooth.substr(1) + tooth[0];
		}
		flag = 0;
	}
	void check_right(gear& right)
	{
		if (right.flag == 0)
			return;
		if (tooth[2] == right.tooth[6])
			flag = 0;
		else
			flag = right.flag == 1 ? -1 : 1;
	}
	void check_left(gear& left)
	{
		if (left.flag == 0)
			return;
		if (tooth[6] == left.tooth[2])
			flag = 0;
		else
			flag = left.flag == 1 ? -1 : 1;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	gear g[4];
	int k;
	for (gear& gs : g)
		cin >> gs.tooth;

	int n, op;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n >> op;
		n--;
		g[n].flag = op;
		for (int j = n - 1; j >= 0; j--)
		{
			g[j].check_right(g[j + 1]);
		}
		for (int j = n + 1; j < 4; j++)
		{
			g[j].check_left(g[j - 1]);
		}

		for (gear& gs : g)
		{
			gs.turn();
//			cout << gs.tooth << '\n';
		}
	}

	int ans = 0;
	for (int i = 0; i < 4; i++)
		ans += (g[i].tooth[0] - '0')*(1 << i);
	cout << ans;
}