typedef pair<int, int> Pair; // min, max
typedef struct S
{
    int seg_s, seg_e;
    Pair val;
} Segment;
const int MAX_DEP = 18, MAX_IDENTITY = 0, MIN_IDENTITY = 0x7fffffff; // n <= 2^MAX_DEP
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];
Pair makeValue(Pair a, Pair b)
{
    return Pair(min(a.first, b.first), max(a.second, b.second));
}
void make_tree(int i, int n, int *arr)
{
    auto &now = tree[i];
    if ((1 << (MAX_DEP - 1)) - 1 <= i)
    {
        int idx = i - ((1 << (MAX_DEP - 1)) - 1);
        now.seg_s = now.seg_e = idx;
        if (idx < n)
            now.val = Pair(arr[idx], arr[idx]);
        else
            now.val = Pair(MIN_IDENTITY, MAX_IDENTITY);
    }
    else
    {
        make_tree(2 * i + 1, n, arr);
        make_tree(2 * i + 2, n, arr);
        now.seg_s = tree[2 * i + 1].seg_s, now.seg_e = tree[2 * i + 2].seg_e;
        now.val = makeValue(tree[2 * i + 1].val, tree[2 * i + 2].val);
    }
}
Pair solve(int i, int s, int e)
{
    auto &now = tree[i];
    if (e < now.seg_s || now.seg_e < s)
        return Pair(MIN_IDENTITY, MAX_IDENTITY);
    else if (s <= now.seg_s && now.seg_e <= e)
        return now.val;
    else
        return makeValue(solve(2 * i + 1, s, e), solve(2 * i + 2, s, e));
}