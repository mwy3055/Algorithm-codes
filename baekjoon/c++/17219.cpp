#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, string> memo;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string add, pw;
        cin >> add >> pw;
        memo[add] = pw;
    }
    for (int i = 0; i < m; i++)
    {
        string add;
        cin >> add;
        cout << memo[add] << '\n';
    }
}