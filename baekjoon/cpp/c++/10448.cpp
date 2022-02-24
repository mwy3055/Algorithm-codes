#include <bits/stdc++.h>
using namespace std;

bool eureka(int &n)
{
    static vector<int> v(0);
    if (v.size() == 0)
        for (int i = 1; i * (i + 1) / 2 <= 1000; i++)
            v.push_back(i * (i + 1) / 2);
    static int siz = v.size();

    for (int i = 0; i < siz; i++)
    {
        for (int j = 0; j < siz; j++)
        {
            if (v[i] + v[j] > 1000)
                break;
            for (int k = 0; k < siz; k++)
            {
                if (v[i] + v[j] + v[k] > 1000)
                    break;
                if (v[i] + v[j] + v[k] == n)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << eureka(n) << '\n';
    }
}