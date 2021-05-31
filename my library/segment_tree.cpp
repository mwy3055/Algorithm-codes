using ll = long long;
typedef struct S
{
    int seg_s, seg_e;
    ll val;
} Segment;
const int MAX_DEP = 17, IDENTITY = 0; // n <= 2^(MAX_DEP-1)
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];

// sum segment tree
Segment &make_tree(int i, std::vector<ll> &arr)
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
        auto &left = make_tree(2 * i + 1, arr);
        auto &right = make_tree(2 * i + 2, arr);
        now.seg_s = left.seg_s;
        now.seg_e = right.seg_e;
        now.val = left.val + right.val;
    }
    return now;
}
ll solve(int i, int s, int e)
{
    auto &now = tree[i];
    if (e < now.seg_s || now.seg_e < s)
        return IDENTITY;
    else if (s <= now.seg_s && now.seg_e <= e)
        return now.val;
    else
        return solve(2 * i + 1, s, e) + solve(2 * i + 2, s, e);
}
ll change(int i, int &idx, int &val)
{
    auto &now = tree[i];
    if (now.seg_s == idx && now.seg_e == idx)
        return now.val = val;
    else if (now.seg_s == now.seg_e || idx < now.seg_s || now.seg_e < idx)
        return now.val;
    else
        return now.val = change(2 * i + 1, idx, val) + change(2 * i + 2, idx, val);
}