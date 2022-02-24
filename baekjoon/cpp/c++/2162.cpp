#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using segment = pair<pii, pii>;

const int MAX = 3000;
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

int ccw(pair<int, int> x, pair<int, int> y, pair<int, int> z) // (x, y)
{
    int v1x = y.first - x.first, v1y = y.second - x.second;
    int v2x = z.first - y.first, v2y = z.second - y.second;
    int cross = v1x * v2y - v1y * v2x; // overflow!!
    if (cross > 0)
        return 1;
    else if (cross < 0)
        return -1;
    else
        return 0;
}
bool meet_segment(segment &s1, segment &s2) // (x1, y1) ~ (x2, y2), (x3, y3) ~ (x4, y4)
{
    auto &a = s1.first, &b = s1.second, &c = s2.first, &d = s2.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int n;
    cin >> n;
    vector<segment> segments(n);
    for (auto &s : segments)
        cin >> s.first.first >> s.first.second >> s.second.first >> s.second.second;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (meet_segment(segments[i], segments[j]))
            {
                union_vertex(i, j);
            }
        }
    }

    int group = 0, maxsize = 0;
    for (int i = 0; i < n; i++)
    {
        if (root[i] < 0)
        {
            group++;
            maxsize = max(maxsize, -root[i]);
        }
    }
    cout << group << '\n'
         << maxsize;
}