#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> pdpii;
int n, m;
vector<pii> points;
set<pii> connected;

const int MAX = 1000;
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
        swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

double dist(pii &a, pii &b)
{
    ll dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
double solve()
{
    priority_queue<pdpii, vector<pdpii>, greater<pdpii>> pq;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (connected.find({i, j}) != connected.end())
            {
                continue;
            }
            double d = dist(points[i - 1], points[j - 1]);
            pq.push({d, {i, j}});
        }
    }

    double sum = 0;
    int cnt = connected.size();
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        double &d = top.first;
        int &a = top.second.first, &b = top.second.second;
        if (find(a) == find(b))
            continue;

        union_vertex(a, b);
        sum += d;
        cnt++;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n >> m;
    points = vector<pii>(n);
    for (auto &point : points)
        cin >> point.first >> point.second;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        connected.insert({a, b});
        union_vertex(a, b);
    }

    cout.precision(2);
    cout << fixed << solve();
}