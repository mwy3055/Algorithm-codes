#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;
inline ll max(ll a, ll b)
{
	return a < b ? b : a;
}
long long solve(vector<int>& arr)
{
	stack<int> st; //¿Œµ¶Ω∫
	long long ans = 0;
	int n = arr.size();

	for (int i = 0; i < n; i++) //left = i
	{
		while (!st.empty() && arr[i] < arr[st.top()])
		{
			ll h = arr[st.top()], width;
			st.pop();
			width = st.empty() ? i : i - 1 - st.top();
			ans = max(ans, h*width);
		}
		st.push(i);
	}
	while (!st.empty())
	{
		ll h = arr[st.top()], width;
		st.pop();
		width = st.empty() ? n : n - 1 - st.top();
		ans = max(ans, h*width);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n != 0)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << solve(arr) << '\n';
		cin >> n;
	}
}