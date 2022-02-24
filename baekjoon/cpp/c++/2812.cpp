#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        int t = c - '0';
        while (!ans.empty() && ans.back() < t && k)
        {
            ans.pop_back();
            k--;
        }
        ans.push_back(t);
    }

    while (k--)
        ans.pop_back();

    for (auto &a : ans)
        cout << a;
}