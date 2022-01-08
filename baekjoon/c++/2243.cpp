#include <bits/stdc++.h>

using ll = long long;
typedef struct S
{
    int seg_s, seg_e;
    ll val;
} Segment;
const int MAX_DEP = 21; // n <= 2^MAX_DEP
const int MAX = (1 << MAX_DEP) - 1, OFFSET = (1 << (MAX_DEP - 1)) - 1;
Segment tree[MAX];

void make_tree(int i)
{
    auto &now = tree[i];
    if (OFFSET <= i)
    {
        int idx = i - OFFSET;
        now.seg_s = now.seg_e = idx;
    }
    else
    {
        make_tree(2 * i + 1);
        make_tree(2 * i + 2);
        now.seg_s = tree[2 * i + 1].seg_s;
        now.seg_e = tree[2 * i + 2].seg_e;
    }
}
ll query(int cur, int k) // find k-th element
{
    auto &now = tree[cur];
    auto &s = now.seg_s, &e = now.seg_e;
    if (s == e)
        return s;
    if (tree[2 * cur + 1].val < k)
        return query(2 * cur + 2, k - tree[2 * cur + 1].val); // go to right child
    else
        return query(2 * cur + 1, k); // go to left child
}
ll update(int cur, int idx, int val) // add val to idx-th element
{
    auto &now = tree[cur];
    if (now.seg_s == idx && now.seg_e == idx)
    {
        now.val += val;
        return now.val;
    }
    else if (now.seg_s == now.seg_e || idx < now.seg_s || now.seg_e < idx)
        return now.val;
    else
        return now.val = update(2 * cur + 1, idx, val) + update(2 * cur + 2, idx, val);
}

// index: flavor of the candy
// value: number of the candy

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    make_tree(0);

    int n;
    std::cin >> n;
    while (n--)
    {
        int a;
        std::cin >> a;
        if (a == 1)
        {
            int b;
            std::cin >> b;
            int candy = query(0, b);
            std::cout << candy << '\n';
            update(0, candy, -1);
        }
        else
        {
            int b, c;
            std::cin >> b >> c;
            update(0, b, c);
        }
    }
}