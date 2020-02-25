#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> num;

typedef pair<int, int> Pair; // value, index
typedef struct S
{
    int seg_s, seg_e;
    Pair val;
} Segment;
const int MAX_DEP = 20, MAX_IDENTITY = 0;
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];
Pair makeValue(Pair a, Pair b)
{
    if (a.first == b.first)
        return a.second < b.second ? a : b;
    return a.first < b.first ? b : a;
}
void makeTree(int i)
{
    auto &now = tree[i];
    if ((1 << (MAX_DEP - 1)) - 1 <= i)
    {
        int idx = i - ((1 << (MAX_DEP - 1)) - 1);
        now.seg_s = now.seg_e = idx;
        if (idx < n)
            now.val = Pair(num[idx], idx);
        else
            now.val = Pair(MAX_IDENTITY, idx);
    }
    else
    {
        auto &left = tree[2 * i + 1], &right = tree[2 * i + 2];
        makeTree(2 * i + 1);
        makeTree(2 * i + 2);
        now.seg_s = left.seg_s, now.seg_e = right.seg_e;
        now.val = makeValue(left.val, right.val);
    }
}
Pair solve(int i, int s, int e)
{
    auto &now = tree[i];
    if (e < now.seg_s || now.seg_e < s)
        return Pair(MAX_IDENTITY, MAX + 1);
    else if (s <= now.seg_s && now.seg_e <= e)
        return now.val;
    else
        return makeValue(solve(2 * i + 1, s, e), solve(2 * i + 2, s, e));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        num.push_back(c - '0');
    }

    makeTree(0);

    int curidx = -1, left = n - k;
    Pair maxval;
    do
    {
        int ridx = (num.end() - left) - num.begin();
        maxval = solve(0, curidx + 1, ridx);
        cout << maxval.first;
        curidx = maxval.second;
        left--;
    } while (left);
}