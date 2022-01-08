#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii; // cost, {a, b}
int n, m;

/* union find */
int root[100001];
void init()
{
    for (int i = 0; i <= 100000; i++)
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
        swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

template <typename T>
bool contains(set<T> &s, T elem)
{
    return s.find(elem) != s.end();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    priority_queue<pipii, vector<pipii>, greater<pipii>> edges;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push({c, {a, b}});
    }

    // Kruskal Algorithm to make Minimum Spanning Tree
    int sum = 0, maxcost = 0;
    vector<pii> edge;
    while (!edges.empty() && edge.size() < n - 1)
    {
        auto top = edges.top();
        edges.pop();

        int &cost = top.first, &u = top.second.first, &v = top.second.second;
        if (find(u) == find(v)) // cycle
            continue;
        else
        {
            sum += cost;
            maxcost = max(maxcost, cost);

            edge.push_back(top.second);
            union_vertex(u, v);
        }
    }

    cout << sum - maxcost;
}