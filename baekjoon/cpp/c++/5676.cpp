#include <bits/stdc++.h>

using vi = std::vector<int>;

using ll = long long;
typedef struct S
{
    int seg_s, seg_e;
    ll val;
} Segment;
const int MAX_DEP = 18, IDENTITY = 1; // n <= 2^MAX_DEP
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];

// sum segment tree
void make_tree(int i, std::vector<ll> &arr)
{
    auto &now = tree[i];
    if ((1 << (MAX_DEP - 1)) - 1 <= i)
    {
        int idx = i - ((1 << (MAX_DEP - 1)) - 1);
        now.seg_s = now.seg_e = idx;
        if (idx < arr.size())
            now.val = arr[idx];
        else
            now.val = IDENTITY;
    }
    else
    {
        make_tree(2 * i + 1, arr);
        make_tree(2 * i + 2, arr);
        now.seg_s = tree[2 * i + 1].seg_s, now.seg_e = tree[2 * i + 2].seg_e;
        now.val = tree[2 * i + 1].val * tree[2 * i + 2].val;
    }
}
ll solve(int i, int s, int e)
{
    auto &now = tree[i];
    if (e < now.seg_s || now.seg_e < s)
        return IDENTITY;
    else if (s <= now.seg_s && now.seg_e <= e)
        return now.val;
    else
        return solve(2 * i + 1, s, e) * solve(2 * i + 2, s, e);
}
ll change(int i, int &idx, int val)
{
    auto &now = tree[i];
    if (now.seg_s == idx && now.seg_e == idx)
    {
        return now.val = val;
    }
    else if (now.seg_s == now.seg_e || idx < now.seg_s || now.seg_e < idx)
        return now.val;
    else
        return now.val = change(2 * i + 1, idx, val) * change(2 * i + 2, idx, val);
}

int encode(int val)
{
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    while (std::cin >> n >> k)
    {
        memset(tree, 0, sizeof(tree));
        std::vector<ll> numbers;
        for (int i = 0; i < n; i++)
        {
            int x;
            std::cin >> x;
            numbers.push_back(encode(x));
        }
        make_tree(0, numbers);

        for (int i = 0; i < k; i++)
        {
            char type;
            std::cin >> type;
            if (type == 'C')
            {
                int i, v;
                std::cin >> i >> v;
                change(0, --i, encode(v));
            }
            else
            {
                int i, j;
                std::cin >> i >> j;
                int ans = solve(0, --i, --j);
                if (ans > 0)
                    std::cout << '+';
                else if (ans < 0)
                    std::cout << '-';
                else
                    std::cout << '0';
            }
        }
        std::cout << '\n';
    }
}