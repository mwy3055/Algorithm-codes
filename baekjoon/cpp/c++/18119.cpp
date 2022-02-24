#include <bits/stdc++.h>
using namespace std;

vector<int> converted;
int know = 0x7fffffff;

int getbit(string &s)
{
    set<char> temp(s.begin(), s.end());
    int ans = 0;
    for (auto &c : temp)
    {
        ans |= 1 << (c - 'a');
    }
    return ans;
}
int query(int &o, char &x)
{
    if (o == 1)
        know ^= 1 << (x - 'a');
    else
        know |= 1 << (x - 'a');

    int ans = 0;
    for (auto &word : converted)
    {
        if ((word & know) == word)
            ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        converted.push_back(getbit(s));
    }

    for (int i = 0; i < m; i++)
    {
        int o;
        char x;
        cin >> o >> x;
        cout << query(o, x) << '\n';
    }
}