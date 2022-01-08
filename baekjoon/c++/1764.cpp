#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Hash set 공부하기
string lis[500000], see[500000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, i;
	cin >> n >> m;
#ifdef dma
	string* lis = new string[n];
	string* see = new string[m];
#endif
	for (i = 0; i < n; i++)
		cin >> lis[i];
	for (i = 0; i < m; i++)
		cin >> see[i];

	sort(lis, lis + n);
	sort(see, see + m);
/*
	cout << "lis sorted\n";
	for (i = 0; i < n; i++)
		cout << lis[i] << '\n';
	cout << "see sorted\n";
	for (i = 0; i < m; i++)
		cout << see[i] << '\n';
	cout << "\n\n";
*/
	int lidx = 0, sidx = 0, cnt = 0;
	vector<int> v;
	while (lidx < n && sidx < m)
	{
		if (lis[lidx] > see[sidx])
			sidx++;
		else if (lis[lidx] < see[sidx])
			lidx++;
		else
		{
			v.push_back(lidx);
			cnt++;
			lidx++;
			sidx++;
		}
	}

	cout << cnt << '\n';
	for (int t : v)
	{
		cout << lis[t] << '\n';
	}
#ifdef dma
	delete[] lis;
	delete[] see;
#endif
}