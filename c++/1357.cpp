#include <iostream>
#include <string>
using namespace std;

int rev(string s)
{
	int ans = 0, len = s.length();
	for (int i = len - 1; i >= 0; i--)
		ans = ans * 10 + (s.at(i) - '0');
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;
	cout << rev(to_string(rev(a) + rev(b)));
}