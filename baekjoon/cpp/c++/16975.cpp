#include <bits/stdc++.h>

// 구간 업데이트, 점 쿼리 펜윅 트리
// 수열 A가 주어질 때, 다음의 수열 B를 정의하자.
// B[1] = A[1], B[i] = A[i] - A[i-1] (i >= 2)

// 1. 구간 업데이트: [l, r] 구간에 k만큼 더한다고 하면
// B[l] = (A[i] + k) - A[i-1]는 k만큼 증가.
// B[l+1]..B[r]은 그대로
// B[r+1] = A[r+1] - (A[i] + k)는 k만큼 감소.
// 따라서 A의 [l, r] 구간에 k만큼 더하는 구간 업데이트는
// B[l]에 k만큼, B[r+1]에 -k만큼 더하는 점 업데이트로 바꿀 수 있다.

// 2. 점 쿼리
// A[i]를 구하고 싶다면 B[1]부터 B[i]까지 모두 더하면 된다.
// A[i]를 제외하고 모두 소거되기 때문.
// 따라서 A[i]를 구하는 점 쿼리는 B의 [1, i] 구간 쿼리(합)으로 바꿀 수 있다.
// 펜윅 트리 구현은 동일.

using ll = long long;
ll tree[100001];

int n, m;
std::vector<ll> a;

void update(int i, ll d)
{
    while (i <= n)
    {
        tree[i] += d;
        i += i & -i;
    }
}

void update(int l, int r, ll d)
{
    update(l, d);
    update(r + 1, -d);
}

ll sum(int i)
{
    ll ans = 0;
    while (i > 0)
    {
        ans += tree[i];
        i -= i & -i;
    }
    return ans;
}

ll get(int i)
{
    return sum(i);
}

void getinput()
{
    // a: 원본 수
    // b: a[i] - a[i-1] (i = 1: a[i])
    std::cin >> n;
    a.resize(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    std::cin >> m;
}

void query1()
{
    int i, j, k;
    std::cin >> i >> j >> k;
    update(i, j, k);
}

ll query2()
{
    int x;
    std::cin >> x;
    return get(x);
}

void solve()
{
    // make b
    for (int i = 1; i <= n; i++)
    {
        ll val = (i == 1 ? a[i] : a[i] - a[i - 1]);
        update(i, val);
    }

    for (int i = 0; i < m; i++)
    {
        int query;
        std::cin >> query;
        if (query == 1)
        {
            query1();
        }
        else if (query == 2)
        {
            std::cout << query2() << '\n';
        }
        else
            std::exit(-1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}