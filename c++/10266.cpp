#include <bits/stdc++.h>
using namespace std;

const int MOD = 360000;

int pi[MOD + 1]; // length of pattern
void getpi(vector<int> &p)
{
    int j = 0;
    for (int i = 1; i < p.size(); i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
}
bool kmp(int &n, vector<int> &t, vector<int> &p)
{
    int j = 0;
    for (int i = 0; i < t.size(); i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
        {
            if (j == n - 1)
            {
                return true;
            }
            else
            {
                j++;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c1(n), c2(n);

    for (auto &c : c1)
        cin >> c;
    for (auto &c : c2)
        cin >> c;

    // make diff array
    int s1 = 0, s2 = 0;
    vector<int> diff1(n * 2), diff2(n);
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    for (int i = 0; i < n - 1; i++)
    {
        diff1[i] = (c1[(i + 1)] - c1[i]) % MOD;
        diff2[i] = (c2[(i + 1)] - c2[i]) % MOD;
        s1 += diff1[i];
        s2 += diff2[i];
    }
    diff1[n - 1] = MOD - s1;
    diff2[n - 1] = MOD - s2;

    // make circle string
    for (int i = n; i < 2 * n; i++)
        diff1[i] = diff1[i - n];

    // find diff2 from diff1
    getpi(diff2);
    cout << (kmp(n, diff1, diff2) ? "possible" : "impossible");
}