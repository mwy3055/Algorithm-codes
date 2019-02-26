#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> nodeinfo; //출발점, 도착점
typedef pair<int, nodeinfo> edge;

void union_init(int *p, int &n)
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
}
int get_parent(int *p, int i)
{
    if (p[i] == i)
        return p[i];
    return p[i] = get_parent(p, p[i]);
}
void union_parent(int *p, nodeinfo &n)
{
    int pi = get_parent(p, n.first), pj = get_parent(p, n.second);
    if (pi < pj)
        p[pj] = pi;
    else
        p[pi] = pj;
}

int kruskal(int &n, vector<edge> &adj)
{
    int *p = new int[n+1];
    union_init(p, n);

    int unum = 0, sum = 0;
    sort(adj.begin(), adj.end());
    for (edge &e : adj)
    {
        if (get_parent(p, e.second.first) == get_parent(p, e.second.second))
            continue;

        union_parent(p, e.second);
        sum += e.first;
        if (++unum == n - 1)
            break;
    }

    delete[] p;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    vector<edge> adj;
    cin >> n >> m; //0~(n-1)번 정점 존재
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj.push_back({c, {a, b}});
    }

    cout << kruskal(n, adj);
}