#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
typedef pair<int, int> location;
void parse_data(vector<int>& lasers, vector<location>& sticks)
{
	string s;
	cin >> s;

	int idx = 0, len = s.length(); //À§Ä¡
	stack<location> temp;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				lasers.push_back(idx);
				i++;
			}
			else
				temp.push(location(idx, 0));
		}
		else
		{
			location t = temp.top();
			temp.pop();
			t.second = idx;
			sticks.push_back(t);
		}
		idx++;
	}
}
inline bool isin(int loc, location& stick)
{
	return stick.first < loc&&loc < stick.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> lasers;
	vector<location> sticks;
	parse_data(lasers, sticks);
	int ans = sticks.size();
	for (int laser : lasers)
	{
		for (location stick : sticks)
		{
			if (isin(laser, stick))
				ans++;
		}
	}
	cout << ans;
}