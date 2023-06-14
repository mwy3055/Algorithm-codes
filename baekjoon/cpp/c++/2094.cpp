#include <bits/stdc++.h>

int n, m;
std::vector<int> years, rains;
std::string answers[] = {"true", "maybe", "false"};

struct node
{
    int left, right, val;
};

class SegmentTree
{
private:
    std::vector<node> nodes;
    int depth;
    const int OFFSET;
    const int IDENTITY;

public:
    SegmentTree(int depth) : depth(depth), OFFSET((1 << (depth - 1)) - 1), IDENTITY(1)
    {
        nodes.resize(1 << depth);
    }
    node &init(int index, std::vector<int> &value)
    {
        node &cur = nodes[index];
        if (index >= OFFSET)
        {
            int leaf_index = index - OFFSET;
            cur.left = cur.right = leaf_index;
            cur.val = (leaf_index < value.size() ? value[leaf_index] : IDENTITY);
        }
        else
        {
            auto &left = init(index * 2 + 1, value);
            auto &right = init(index * 2 + 2, value);
            cur.left = left.left;
            cur.right = right.right;
            cur.val = std::max(left.val, right.val);
        }
        return cur;
    }
    int query(int index, int l, int r)
    {
        auto &cur = nodes[index];
        if (l <= cur.left && cur.right <= r)
            return cur.val;
        else if (l > r || r < cur.left || cur.right < l)
            return IDENTITY;
        else
        {
            auto lmax = query(index * 2 + 1, l, r);
            auto rmax = query(index * 2 + 2, l, r);
            return std::max(lmax, rmax);
        }
    }
};

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int y, r;
        std::cin >> y >> r;
        years.push_back(y);
        rains.push_back(r);
    }
}

void print(int ans)
{
    std::cout << answers[ans] << '\n';
}

void solve()
{
    SegmentTree tree(17);
    tree.init(0, rains);

    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int y, x;
        std::cin >> y >> x;
        auto lidx = std::lower_bound(years.begin(), years.end(), y) - years.begin();
        auto ridx = std::lower_bound(years.begin(), years.end(), x) - years.begin();
        bool lexists = (years[lidx] == y), rexists = (years[ridx] == x);

        int ans = 0; // 0: 가능, 1: maybe, 불가능: false
        if (lexists && rexists)
        {
            // 모든 ..
            bool cond1 = (x - y == ridx - lidx);
            bool cond2 = (rains[lidx] >= rains[ridx]);
            auto smin = tree.query(0, lidx + 1, ridx - 1);
            bool cond3 = (smin < rains[ridx]);
            if (!cond2 || !cond3)
                ans = 2;
            else
                ans = (cond1 ? 0 : 1);
        }
        else if (lexists)
        {
            if (ridx - lidx <= 1)
                ans = 1;
            else
            {
                auto smax = tree.query(0, lidx + 1, ridx - 1);
                ans = (smax < rains[lidx] ? 1 : 2);
            }
        }
        else if (rexists)
        {
            auto smax = tree.query(0, lidx, ridx - 1);
            ans = (smax < rains[ridx] ? 1 : 2);
        }
        else
        {
            ans = 1;
        }

        print(ans);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}