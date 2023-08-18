#include <bits/stdc++.h>
using namespace std;

int pi[1000000]; // length of pattern
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l;
    string s;
    cin >> l >> s;
    getpi(s);
    cout << l - pi[l - 1];
}