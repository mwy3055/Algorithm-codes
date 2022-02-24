#include <bits/stdc++.h>

struct pair
{
    int value, index;
    pair(int v = 0, int i = -1) : value(v), index(i) {}
};

typedef struct S
{
    int left, right;
    pair data;
} Segment;
const int MAX_DEP = 18, IDENTITY = 1 << 30; // n <= 2^(MAX_DEP-1)
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];

// sum segment tree
void make_tree(int i, std::vector<int> &arr)
{
    auto &now = tree[i];
    if ((1 << (MAX_DEP - 1)) - 1 <= i)
    {
        int idx = i - ((1 << (MAX_DEP - 1)) - 1);
        now.left = now.right = idx;
        if (idx < arr.size())
            now.data = pair(arr[idx], idx);
        else
            now.data = pair(IDENTITY, idx);
    }
    else
    {
        make_tree(2 * i + 1, arr);
        make_tree(2 * i + 2, arr);
        auto lval = tree[2 * i + 1], rval = tree[2 * i + 2];
        now.left = lval.left, now.right = rval.right;
        now.data = lval.data.value <= rval.data.value ? lval.data : rval.data;
    }
}
pair solve(int i, int s, int e)
{
    auto &now = tree[i];
    if (e < now.left || now.right < s)
        return pair(IDENTITY, -1);
    else if (s <= now.left && now.right <= e)
        return now.data;
    else
    {
        auto lval = solve(2 * i + 1, s, e), rval = solve(2 * i + 2, s, e);
        return lval.value <= rval.value ? lval : rval;
    }
}
pair change(int i, int &idx, int &data)
{
    auto &now = tree[i];
    if (now.left == idx && now.right == idx)
    {
        now.data.value = data;
        return now.data;
    }
    else if (now.left == now.right || idx < now.left || now.right < idx)
        return now.data;
    else
    {
        auto lval = change(2 * i + 1, idx, data), rval = change(2 * i + 2, idx, data);
        return now.data = lval.value <= rval.value ? lval : rval;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto &a : arr)
        std::cin >> a;
    make_tree(0, arr);

    int m;
    std::cin >> m;
    for (int t = 0; t < m; t++)
    {
        int type, i, query;
        std::cin >> type >> i >> query;
        if (type == 1)
        {
            change(0, --i, query);
        }
        else
        {
            auto ans = solve(0, --i, --query);
            std::cout << ans.index + 1 << '\n';
        }
    }
}