#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//선: x와 x+1 사이
struct line
{
    bool vertical; //선 자체의 방향
    int y, x;
    line(int y = -1, int x = -1, bool v = false) : y(y), x(x), vertical(v) {}
};

char num[101][101];
ll sum[101][101], n, m;

ll subsum(int y1, int x1, int y2, int x2)
{
    return sum[y2][x2] - sum[y2][x1 - 1] - sum[y1 - 1][x2] + sum[y1 - 1][x1 - 1];
}

ll submtp(line &l1, line &l2)
{
    if (l1.vertical && l2.vertical)
    {
        //둘 다 세로선
        ll n1 = subsum(1, 1, n, l1.x), n2 = subsum(1, l1.x + 1, n, l2.x), n3 = subsum(1, l2.x + 1, n, m);
        return n1 * n2 * n3;
    }
    else if (l1.vertical || l2.vertical)
    {
        //세로선 하나, 가로선 하나
        ll n1 = subsum(1, 1, l2.y, l1.x), n2 = subsum(1, l1.x + 1, l2.y, m), n3 = subsum(l2.y + 1, 1, n, m);
        ll n4 = subsum(1, 1, l2.y, m), n5 = subsum(l2.y + 1, 1, n, l1.x), n6 = subsum(l2.y + 1, l1.x + 1, n, m);
        ll n7 = subsum(1, 1, n, l1.x), n8 = subsum(1, l1.x + 1, l2.y, m), n9 = subsum(l2.y + 1, l1.x + 1, n, m);
        ll n10 = subsum(1, 1, l2.y, l1.x), n11 = subsum(l2.y + 1, 1, n, l1.x), n12 = subsum(1, l1.x + 1, n, m);
        return max(n1 * n2 * n3, max(n4 * n5 * n6, max(n7 * n8 * n9, n10 * n11 * n12)));
    }
    else
    {
        //둘 다 가로선
        ll n1 = subsum(1, 1, l1.y, m), n2 = subsum(l1.y + 1, 1, l2.y, m), n3 = subsum(l2.y + 1, 1, n, m);
        return n1 * n2 * n3;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> num[i][j];
            num[i][j] -= '0';

            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + num[i][j];
        }
    }

    ll ans = 0;
    for (int x1 = 1; x1 < m; x1++)
    {
        line l1(-1, x1, true);
        //세로선 2개
        for (int x2 = x1 + 1; x2 < m; x2++)
        {
            line l2(-1, x2, true);

            ll temp = submtp(l1, l2);
            ans = max(ans, temp);
        }

        //세로선 l1, 가로선 l2
        for (int y1 = 1; y1 < n; y1++)
        {
            line l2(y1, -1, false);

            ll temp = submtp(l1, l2);
            ans = max(ans, temp);
        }
    }

    //가로선 2개
    for (int y1 = 1; y1 < n; y1++)
    {
        line l1(y1, -1, false);
        for (int y2 = y1 + 1; y2 < n; y2++)
        {
            line l2(y2, -1, false);

            ll temp = submtp(l1, l2);
            ans = max(ans, temp);
        }
    }

    cout << ans;
}