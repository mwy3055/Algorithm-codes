#include <bits/stdc++.h>
using namespace std;

int pi[1000001], match[1000001];

string getstring(int n)
{
    string rtn = "I";
    for (int i = 0; i < n; i++)
    {
        rtn.push_back('O');
        rtn.push_back('I');
    }
    return rtn;
}
void getpi(string &target)
{
    int i, j = 0, m = target.length();
    for (i = 1; i < m; i++)
    {
        while (j > 0 && target[i] != target[j])
            j = pi[j - 1];
        if (target[i] == target[j])
            pi[i] = ++j;
    }
}
int kmp(string &s, string &target)
{
    int ans = 0, i, j = 0;
    int n = s.length(), m = target.length();
    for (i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != target[j])
            j = pi[j - 1];
        if (s[i] == target[j])
        {
            if (j == m - 1)
            {
                match[++ans] = i - m + 2;
                j = pi[j];
            }
            else
                j++;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    string s;
    cin >> n >> m >> s;

    string target = getstring(n);
    getpi(target);

    cout << kmp(s, target);
}