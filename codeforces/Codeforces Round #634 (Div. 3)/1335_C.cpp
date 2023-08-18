#include <bits/stdc++.h>
using namespace std;

bool available(int mid, int cnt, int p)
{
    return mid <= cnt - (mid == p ? 1 : 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (!m.count(a))
                cnt++;
            m[a]++;
        }
        if (n == 1)
        {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (auto &p : m) // 능력이 first인 사람이 second명 있음
        {
            int left = 1, right = p.second;
            int mid = (left + right) / 2; // [left,right]
            while (left <= right)
            {
                mid = (left + right) / 2;
                //cout << left << ' ' << right << '\n';
                if (available(mid, cnt, p.second))
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            ans = max(ans, (available(mid, cnt, p.second) ? mid : mid - 1));
        }
        cout << ans << '\n';
    }
}