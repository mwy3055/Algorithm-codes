#include <bits/stdc++.h>
using namespace std;

int pi[1000000];
void getpi(string &p)
{
    // pi[0] = 0
    int j = 0;
    for (int i = 1; i < p.size(); i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
}
void kmp(vector<int> &ans, string &t, string &p)
{
    int j = 0, tlen = t.size(), plen = p.size();
    for (int i = 0; i < tlen; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
        {
            if (j == plen - 1)
            {
                ans.push_back(i - plen + 1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    getpi(pattern);
    vector<int> ans;
    kmp(ans, text, pattern);
    cout << ans.size() << '\n';
    for (auto &a : ans)
        cout << a + 1 << ' ';
}