#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct star
{
    int idx, x, y, z;
};

typedef pair<int, int> edge;
typedef pair<int, edge> element;
vector<element> edges;
bool cmp1(const star &a, const star &b)
{
    return a.x < b.x;
}
bool cmp2(const star &a, const star &b)
{
    return a.y < b.y;
}
bool cmp3(const star &a, const star &b)
{
    return a.z < b.z;
}
void make(int &n, vector<star> &stars)
{
    sort(stars.begin(), stars.end(), cmp1);
    for (int i = 0; i < n - 1; i++)
        edges.push_back({abs(stars[i].x - stars[i + 1].x), {stars[i].idx, stars[i + 1].idx}});
    sort(stars.begin(), stars.end(), cmp2);
    for (int i = 0; i < n - 1; i++)
        edges.push_back({abs(stars[i].y - stars[i + 1].y), {stars[i].idx, stars[i + 1].idx}});
    sort(stars.begin(), stars.end(), cmp3);
    for (int i = 0; i < n - 1; i++)
        edges.push_back({abs(stars[i].z - stars[i + 1].z), {stars[i].idx, stars[i + 1].idx}});
}

const int MAX = 100000;
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
ll solve(int &n)
{
    init();
    sort(edges.begin(), edges.end());

    int cnt = 0;
    ll ans = 0;
    for (auto &e : edges)
    {
        if (cnt == n - 1)
            break;

        auto &d = e.first, &a = e.second.first, &b = e.second.second;
        if (find(a) == find(b))
            continue;
        union_vertex(a, b);
        ans += d;
        cnt++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<star> stars(n);
    for (int i = 0; i < n; i++)
    {
        auto &s = stars[i];
        s.idx = i;
        cin >> s.x >> s.y >> s.z;
    }

    make(n, stars);
    cout << solve(n) << '\n';
}