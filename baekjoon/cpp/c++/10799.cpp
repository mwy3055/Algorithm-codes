#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.length(), ans = 0, size = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			if (s[i + 1] == ')')
			{
				ans += size;
				i++;
			}
			else
			{
				size++;
			}
		}
		else
		{
			size--;
			ans++;
		}
	}
	cout << ans;
}