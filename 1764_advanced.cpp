#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string* lis;
vector<string> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, i;
	cin >> n >> m;
	lis = new string[n];
	for (i = 0; i < n; i++)
		cin >> lis[i];
	sort(lis, lis + n);

	vector<int> idx;
	for (i = 0; i < m; i++)
	{
		string t;
		cin >> t;
		if (binary_search(lis, lis + n, t)) //ÇÙ½É
			ans.push_back(t);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (string t : ans)
		cout << t << '\n';

	delete[] lis;
}