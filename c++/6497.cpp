#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int MAX = 200000;
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

int solve(int &m, int &n, priority_queue<edge, vector<edge>, greater<edge>> &pq)
{
    int sum = 0, cnt = 0;
    while (!pq.empty() && cnt < m - 1)
    {
        auto top = pq.top();
        pq.pop();

        int &d = top.first, &a = top.second.first, &b = top.second.second;
        if (find(a) != find(b))
        {
            union_vertex(a, b);
            sum += d;
        }
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    while (m)
    {
        init();
        int totalsum = 0;
        priority_queue<edge, vector<edge>, greater<edge>> pq;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            pq.push({z, {x, y}});
            totalsum += z;
        }
        cout << totalsum - solve(m, n, pq) << '\n';

        cin >> m >> n;
    }
}