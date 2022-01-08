#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string vowel = "aeiou";
char org[15];
int l, c;
bool sub[15];

void dfs(int i, int cnt)
{
	if (i == c)
	{
		if (cnt == l)
		{
			int vow = 0, con = 0;
			for (int i = 0; i < c; i++)
			{
				if (sub[i])
				{
					vowel.find(org[i]) == vowel.npos ? con++ : vow++;
				}
			}
			if (1 <= vow && 2 <= con)
			{
				for (int i = 0; i < c; i++)
					if (sub[i])
						cout << org[i];
				cout << '\n';
			}
		}
		return;
	}
	sub[i] = true;
	dfs(i + 1, cnt + 1);
	sub[i] = false;
	dfs(i + 1, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> org[i];
	sort(org, org + c);
	sub[0] = true;
	dfs(1, 1);
	sub[0] = false;
	dfs(1, 0);
}