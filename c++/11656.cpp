#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	vector<string> prefix;
	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; i++)
		prefix.push_back(str.substr(i, len - i));

	sort(prefix.begin(), prefix.end());
	for (string s : prefix)
		cout << s << '\n';
}