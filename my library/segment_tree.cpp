using ll = long long;
typedef struct S
{
    int seg_s, seg_e;
    ll val;
} Segment;
const int MAX_DEP = 17, IDENTITY = 0; // n <= 2^MAX_DEP
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];

// sum segment tree
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
            now.val = 0;
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
ll change(int i, int &idx, int &val)
{
    auto &now = tree[i];
    if (now.seg_s == idx && now.seg_e == idx)
    {
        return now.val = val;
    }
    else if (now.seg_s == now.seg_e || idx < now.seg_s || now.seg_e < idx)
        return now.val;
    else
        return now.val = change(2 * i + 1, idx, val) + change(2 * i + 2, idx, val);
}