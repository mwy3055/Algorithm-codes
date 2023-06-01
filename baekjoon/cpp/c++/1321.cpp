#include <bits/stdc++.h>

int n, army[600001];

struct Node
{
    int left, right;
    int val;
    Node(int left = 0, int right = 0, int val = 0) : left(left), right(right), val(val) {}
};

class SegmentTree
{
private:
    std::vector<Node> nodes;
    const int IDENTITY = 0;
    const int DEPTH;
    const int OFFSET;

public:
    // 1-indexed
    SegmentTree(int depth) : nodes(std::vector<Node>()), DEPTH(depth), OFFSET(1 << (depth - 1))
    {
        nodes.resize(1 << depth);
    }

    Node &init(int index)
    {
        auto &cur = nodes[index];
        if (index >= OFFSET)
        {
            auto leaf_index = index - OFFSET;
            cur.left = cur.right = leaf_index;
            cur.val = army[leaf_index];
        }
        else
        {
            auto &lnode = init(index * 2);
            auto &rnode = init(index * 2 + 1);
            cur.left = lnode.left;
            cur.right = rnode.right;
            cur.val = lnode.val + rnode.val;
        }
        return cur;
    }

    // pos 위치의 값을 val만큼 바꿀 때
    int update(int index, int pos, int val)
    {
        auto &cur = nodes[index];
        if (pos < cur.left || cur.right < pos)
        {
            return cur.val;
        }
        else if (cur.left == pos && cur.right == pos)
        {
            return cur.val += val;
        }
        else
        {
            auto lval = update(index * 2, pos, val);
            auto rval = update(index * 2 + 1, pos, val);
            return cur.val = lval + rval;
        }
    }

    // [1, q]의 합이 sum 이상인 최초의 q를 찾자
    int search(int sum)
    {
        int cur = 1;
        while (nodes[cur].left != nodes[cur].right)
        {
            auto &left = nodes[cur * 2], &right = nodes[cur * 2 + 1];
            if (left.val >= sum)
            {
                cur = cur * 2;
            }
            else
            {
                cur = cur * 2 + 1;
                sum -= left.val;
            }
        }
        return nodes[cur].left;
    }
};

void getinput()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> army[i];
    }
}

void solve()
{
    SegmentTree tree(20);
    tree.init(1);

    int m;
    std::cin >> m;
    for (int q = 0; q < m; q++)
    {
        int type, i;
        std::cin >> type >> i;
        if (type == 1)
        {
            int a;
            std::cin >> a;
            tree.update(1, i, a);
        }
        else if (type == 2)
        {
            // i번
            int ans = tree.search(i);
            std::cout << ans << '\n';
        }
        else
            exit(-1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}