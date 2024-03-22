#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using tree = std::pair<pii, int>;
using treeindex = std::pair<tree, int>;

int n, q;
std::vector<treeindex> treeindices;
std::vector<tree> trees;

int group[200000], index_map[200000];

void getinput()
{
    std::cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int x1, x2, q;
        std::cin >> x1 >> x2 >> q;
        treeindices.emplace_back(std::make_pair(std::make_pair(x1, x2), q), i);
    }
}

bool meets(tree &t1, tree &t2)
{
    return t2.first.first <= t1.first.second;
}

void bfs(int start, int gno)
{
    int cur = start;
    auto virtual_tree = trees[cur];

    group[start] = gno;
    while (true)
    {
        if (cur + 1 < n && meets(virtual_tree, trees[cur + 1]))
        {
            group[cur + 1] = gno;
            virtual_tree.first.second = std::max(virtual_tree.first.second, trees[cur + 1].first.second);
            cur++;
        }
        else
        {
            break;
        }
    }
}

void preprocess()
{
    std::sort(treeindices.begin(), treeindices.end());
    for (int i = 0; i < n; i++)
    {
        index_map[treeindices[i].second] = i;
        trees.push_back(treeindices[i].first);
    }

    int gno = 1;
    for (int i = 0; i < n; i++)
    {
        if (group[i] == 0)
        {
            bfs(i, gno++);
        }
    }
}

bool solve(int n1, int n2)
{
    return group[n1] == group[n2];
}

void solve()
{
    preprocess();

    for (int i = 0; i < q; i++)
    {
        int n1, n2;
        std::cin >> n1 >> n2;
        int nidx1 = index_map[n1 - 1], nidx2 = index_map[n2 - 1];
        std::cout << solve(nidx1, nidx2) << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}