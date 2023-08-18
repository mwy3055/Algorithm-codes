#include <bits/stdc++.h>
using namespace std;

const int MAX = 20000;
int root[MAX + 1], dist[MAX + 1];
void init()
{
    memset(root, 0xff, sizeof(int) * (MAX + 1));
    memset(dist, 0, sizeof(int) * (MAX + 1));
}
int find(int n)
{
    if (root[n] < 0)
        return n;
    int root_top = find(root[n]);
    dist[n] += dist[root[n]];
    return root[n] = root_top;
}
void union_vertex(int a, int b) // connect a to b?
{
    int root1 = find(a);
    if (root1 == b)
        return;
    root[root1] = b;
    dist[root1] = (abs(root1 - b)) % 1000;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();

        int n;
        cin >> n;
        while (true)
        {
            char c;
            int i, j;
            cin >> c;
            if (c == 'O')
                break;
            else if (c == 'E')
            {
                cin >> i;
                find(i);
                cout << dist[i] << '\n';
            }
            else if (c == 'I')
            {
                cin >> i >> j;
                union_vertex(i, j);
            }
        }
    }
}