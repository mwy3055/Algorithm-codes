#include <bits/stdc++.h>

using vi = std::vector<int>;
using ll = long long;
struct segment
{
    int s, e;
    ll val;
};
const int MAX_DEP = 21, IDENTITY = 1;
const int MAX = (1 << MAX_DEP) - 1, MOD = 1000000007;
segment tree[MAX];

void maketree(int idx, vi &arr)
{
    auto &now = tree[idx];
    if ((1 << (MAX_DEP - 1)) - 1 <= idx) // if tree's leaf node
    {
        int cidx = idx - ((1 << (MAX_DEP - 1)) - 1);
        now.s = now.e = cidx;
        if (cidx < arr.size())
            now.val = arr[cidx];
        else
            now.val = IDENTITY;
    }
    else
    {
        auto lchild = 2 * idx + 1, rchild = 2 * idx + 2;
        maketree(lchild, arr);
        maketree(rchild, arr);
        now.s = tree[lchild].s;
        now.e = tree[rchild].e;
        now.val = (tree[lchild].val * tree[rchild].val) % MOD;
    }
}

ll updateval(int cur, int &target, int &val)
{
    ll rtn = 1;
    auto &left = tree[cur].s, &right = tree[cur].e;
    auto &cval = tree[cur].val;
    if (left == target && right == target)
    {
        cval = val;
        rtn = val;
    }
    else if (target < left || right < target)
    {
        rtn = cval;
    }
    else
    {
        rtn = (rtn * updateval(2 * cur + 1, target, val)) % MOD;
        rtn = (rtn * updateval(2 * cur + 2, target, val)) % MOD;
    }
    return cval = rtn;
}

ll getval(int cur, int s, int e)
{
    ll rtn = IDENTITY;
    auto &left = tree[cur].s, &right = tree[cur].e;
    if (s <= left && right <= e)
    {
        rtn = tree[cur].val;
    }
    else if (right < s || e < left)
    {
        rtn = IDENTITY;
    }
    else
    {
        ll lval = getval(2 * cur + 1, s, e), rval = getval(2 * cur + 2, s, e);
        rtn = (rtn * lval) % MOD;
        rtn = (rtn * rval) % MOD;
    }
    return rtn;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    vi arr(n);
    for (auto &a : arr)
        std::cin >> a;
    maketree(0, arr);

    for (int i = 0; i < m + k; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c; // b, c: starts from 1
        if (a == 1)
        {
            updateval(0, --b, c);
        }
        else if (a == 2)
        {
            std::cout << getval(0, b - 1, c - 1) << '\n';
        }
    }
}