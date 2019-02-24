#include <iostream>
#include <string>
using namespace std;

int to_eight(string s)
{
	int r = 0;
	r += (s.at(0) - '0') * 4;
	r += (s.at(1) - '0') * 2;
	r += s.at(2) - '0';
	return r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	while (s.length() % 3 != 0)
		s = "0" + s;

	string ans = "";
	int fr = 0, fin = s.length();
	while (fr != fin)
	{
		ans.append(to_string(to_eight(s.substr(fr, 3))));
		fr += 3;
	}

	cout << ans;
}