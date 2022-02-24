#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> color;
	color["black"] = 0;
	color["brown"] = 1;
	color["red"] = 2;
	color["orange"] = 3;
	color["yellow"] = 4;
	color["green"] = 5;
	color["blue"] = 6;
	color["violet"] = 7;
	color["grey"] = 8;
	color["white"] = 9;

	string a, b, c;
	cin >> a >> b >> c;
	long val = color[a] * 10 + color[b];
	for (int i = 0; i < color[c]; i++)
		val *= 10;
	cout << val;
}