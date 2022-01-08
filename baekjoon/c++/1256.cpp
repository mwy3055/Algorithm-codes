#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m, k;
int comb[101][101];
char word[201] = {'\0'};

int calc(int a, int z)
{
    int &rtn = comb[a][z];
    if (a == 0 || z == 0)
        return rtn = 1;
    if (rtn != -1)
        return rtn;

    return rtn = min(calc(a - 1, z) + calc(a, z - 1), INF + 1);
}

bool solve(int n, int m, int k)
{
    int idx = 0, len = n + m;
    while (idx < len)
    {
        if (n == 0)
        {
            while (m-- && idx < len)
                word[idx++] = 'z';
            break;
        }
        else if (m == 0)
        {
            while (n-- && idx < len)
                word[idx++] = 'a';
            break;
        }

        int a_first = calc(n - 1, m), z_first = calc(n, m - 1);
        if (k < a_first)
        {
            word[idx++] = 'a';
            n--;
        }
        else if (k <= INF)
        {
            word[idx++] = 'z';
            m--;
            k -= a_first;
        }
        else
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(comb, -1, sizeof(comb));

    cin >> n >> m >> k;
    if (k <= calc(n, m) && solve(n, m, k - 1))
        cout << word;
    else
        cout << -1;
}