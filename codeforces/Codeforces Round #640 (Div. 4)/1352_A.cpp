#include <bits/stdc++.h>
using namespace std;

int getcypher(int n)
{
    int cnt = 0;
    do
    {
        n /= 10;
        cnt++;
    } while (n);
    return cnt;
}

int p[] = {1, 10, 100, 1000, 10000, 100000};

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
        vector<int> ans;
        int cnt = 0;
        while (n)
        {
            if (n % 10)
                ans.push_back((n % 10) * p[cnt]);
            n /= 10;
            cnt++;
        }
        cout << ans.size() << '\n';
        for (auto &a : ans)
            cout << a << ' ';
        cout << '\n';
    }
}