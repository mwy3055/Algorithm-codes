#include <bits/stdc++.h>

using pii = std::pair<int, int>;

const int INF = 0x3f3f3f3f;
int n, original[20][20], d[20][20];

class UnionFind
{
private:
    int size;
    std::vector<int> root;

public:
    UnionFind(int size) : size(size)
    {
        root.resize(size + 1, -1);
    }
    int find(int n)
    {
        if (root[n] < 0)
            return n;
        return root[n] = find(root[n]);
    }
    void union_node(int a, int b)
    {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        if (root1 > root2)
            std::swap(root1, root2);
        root[root1] += root[root2];
        root[root2] = root1;
    }
};

// start, dest 사이의 거리
int get_dist(int start, int dest)
{
    int result = INF;
    bool visit[20][20] = {false};
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    pq.push(pii(0, start));
    visit[start][start] = true;
    while (!pq.empty())
    {
        auto [dist, cur] = pq.top();
        pq.pop();
        if (cur == dest)
        {
            result = std::min(result, dist);
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (!visit[i][cur] && d[i][cur] != -1)
            {
                pq.push(pii(dist + d[i][cur], i));
                visit[i][cur] = visit[cur][i] = true;
            }
        }
    }
    return result;
}

int solve(std::vector<std::pair<int, pii>> &edges)
{
    auto union_find = UnionFind(n);
    int ans = 0;
    std::sort(edges.begin(), edges.end());
    // connect with greedy
    for (auto &edge : edges)
    {
        auto [cost, nodes] = edge;
        auto [n1, n2] = nodes;
        // 연결되어 있지 않거나, 더 큰 값으로 연결되어 있는 경우
        if (cost < get_dist(n1, n2))
        {
            ans += cost;
            d[n1][n2] = d[n2][n1] = cost;
            union_find.union_node(n1, n2);
        }
    }

    // 정답 검증
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = get_dist(i, j);
            if (original[i][j] != dist)
                return -1;
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::memset(d, -1, sizeof(d));

    std::vector<std::pair<int, pii>> edges;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> original[i][j];
            if (i < j)
                edges.emplace_back(original[i][j], pii(i, j));
        }
    }

    std::cout << solve(edges) << '\n';
}