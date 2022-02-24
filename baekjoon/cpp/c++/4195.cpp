#include <bits/stdc++.h>
using namespace std;

map<string, int> hashmap;

const int MAX = 100005;
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

int solve(string &a, string &b)
{
    int ai, bi; // index of each person
    if (hashmap.find(a) != hashmap.end())
        ai = hashmap[a];
    else
    {
        int siz = hashmap.size();
        ai = hashmap[a] = siz;
    }

    if (hashmap.find(b) != hashmap.end())
        bi = hashmap[b];
    else
    {
        int siz = hashmap.size();
        bi = hashmap[b] = siz;
    }

    union_vertex(ai, bi);
    return -root[find(ai)];
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
        int f;
        cin >> f;
        for (int i = 0; i < f; i++)
        {
            string a, b;
            cin >> a >> b;
            cout << solve(a, b) << '\n';
        }
    }
}