#include <bits/stdc++.h>

using ll = long long;
const int MAX = 1000000;
ll mul[MAX + 1], add[MAX + 1];

int n, m, k;

void update_tree(int idx, ll dmul, ll dadd)
{
    while (idx <= n)
    {
        mul[idx] += dmul;
        add[idx] += dadd;
        idx += (idx & -idx);
    }
}

void update(int l, int r, ll d)
{
    update_tree(l, d, -d * (l - 1));
    update_tree(r + 1, -d, d * r);
}

ll sum(int e)
{
    ll smul = 0, sadd = 0;
    int i = e;
    while (i > 0)
    {
        smul += mul[i];
        sadd += add[i];
        i -= (i & -i);
    }
    return smul * e + sadd;
}

ll sum(int s, int e)
{
    return sum(e) - sum(s - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        ll num;
        std::cin >> num;
        update(i + 1, i + 1, num);
    }

    // 구간 업데이트 및 합 계산을 로그 시간에 수행하는 펜윅 트리
    for (int i = 0; i < m + k; i++)
    {
        int a;
        std::cin >> a;
        if (a == 1)
        {
            int b, c;
            ll d;
            std::cin >> b >> c >> d;
            update(b, c, d);
        }
        else
        {
            int b, c;
            std::cin >> b >> c;
            std::cout << sum(b, c) << '\n';
        }
    }
}