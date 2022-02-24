#include <bits/stdc++.h>

using ll = long long;
typedef struct S
{
    int seg_s, seg_e;
    ll val;
} Segment;
const int MAX_DEP = 18, IDENTITY = 0; // n <= 2^MAX_DEP
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];

void make_tree(int i, int n, ll *arr)
{
    auto &now = tree[i];
    if ((1 << (MAX_DEP - 1)) - 1 <= i)
    {
        int idx = i - ((1 << (MAX_DEP - 1)) - 1);
        now.seg_s = now.seg_e = idx;
        if (idx < n)
            now.val = arr[idx];
        else
            now.val = IDENTITY;
    }
    else
    {
        make_tree(2 * i + 1, n, arr);
        make_tree(2 * i + 2, n, arr);
        now.seg_s = tree[2 * i + 1].seg_s, now.seg_e = tree[2 * i + 2].seg_e;
        now.val = tree[2 * i + 1].val + tree[2 * i + 2].val;
    }
}
ll solve(int i, int s, int e)
{
    auto &now = tree[i];
    if (e < now.seg_s || now.seg_e < s)
        return 0;
    else if (s <= now.seg_s && now.seg_e <= e)
        return now.val;
    else
        return solve(2 * i + 1, s, e) + solve(2 * i + 2, s, e);
}
ll change(int i, int &idx, ll &val)
{
    auto &now = tree[i];
    if (now.seg_s == idx && now.seg_e == idx)
        return now.val = val;
    else if (now.seg_s == now.seg_e || idx < now.seg_s || now.seg_e < idx)
        return now.val;
    else
        return now.val = change(2 * i + 1, idx, val) + change(2 * i + 2, idx, val);
}

ll num[100000];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++)
        std::cin >> num[i];
    make_tree(0, n, num);

    for (int i = 0; i < q; i++)
    {
        int x, y, a;
        ll b;
        std::cin >> x >> y >> a >> b;
        if (x > y)
            std::swap(x, y);
        std::cout << solve(0, x - 1, y - 1) << '\n';
        if (num[--a] != b)
        {
            num[a] = b;
            change(0, a, b);
        }
    }
}