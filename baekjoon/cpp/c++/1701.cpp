#include <bits/stdc++.h>
using namespace std;

vector<int> pi;
int getpi(string p)
{
    pi.clear();
    pi.resize(p.length(), 0);
    int j = 0, ans = 0;
    for (int i = 1; i < p.size(); i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
        ans = max(ans, pi[i]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        ans = max(ans, getpi(s.substr(i)));
    }
    cout << ans;
}