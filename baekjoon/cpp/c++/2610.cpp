#include <bits/stdc++.h>

struct edge
{
    int a, b;
    edge(int a, int b) : a(a), b(b) {}
};

const int MAX = 110;
int root[MAX + 1];
void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}
int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}
void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        std::swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

int d[101][101];

void preprocess(int n)
{
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && j != k && k != i)
                {
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}

int getrep(std::vector<int> &group)
{
    int min_person = -1, min_val = 0x3f3f3f3f;
    for (auto &person : group)
    {
        int dist = 0;
        for (auto &other : group)
        {
            if (other != person)
            {
                dist = std::max(dist, d[other][person]);
            }
        }
        if (dist < min_val)
        {
            min_person = person;
            min_val = dist;
        }
    }
    return min_person;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();
    memset(d, 0x3f, sizeof(d));

    int n, m;
    std::vector<edge> edges;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        d[a][b] = d[b][a] = 1;
        union_vertex(a, b);
    }

    preprocess(n);

    std::vector<int> groups[101];
    for (int i = 1; i <= n; i++)
    {
        int root = find(i);
        groups[root].push_back(i);
    }

    std::vector<int> reps;
    for (int i = 1; i <= n; i++)
    {
        if (!groups[i].empty())
        {
            int rep = getrep(groups[i]);
            reps.push_back(rep);
        }
    }

    std::sort(reps.begin(), reps.end());
    std::cout << reps.size() << '\n';
    for (auto &r : reps)
        std::cout << r << '\n';
}