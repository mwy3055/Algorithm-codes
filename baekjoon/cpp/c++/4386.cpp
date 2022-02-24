#include <bits/stdc++.h>
using namespace std;

/* union find */
const int MAX = 100;
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

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<double, pii> pdpii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int n;
    cin >> n;
    vector<pdd> stars(n);
    for (auto &star : stars)
        cin >> star.first >> star.second;

    priority_queue<pdpii, vector<pdpii>, greater<pdpii>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dx = stars[i].first - stars[j].first, dy = stars[i].second - stars[j].second;
            double d = sqrt(dx * dx + dy * dy);
            pq.push({d, {i + 1, j + 1}});
        }
    }

    double sum = 0;
    int count = 0;
    while (!pq.empty() && count < n - 1)
    {
        auto top = pq.top();
        pq.pop();

        double &cost = top.first;
        int &u = top.second.first, &v = top.second.second;
        if (find(u) == find(v))
            continue;
        else
        {
            sum += cost;
            count++;

            union_vertex(u, v);
        }
    }

    cout.precision(6);
    cout << sum;
}