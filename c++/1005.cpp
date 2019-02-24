#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int memoi[1001], btime[1001];
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int search(int w, vector<vector<int>>& parent)
{
    if (memoi[w] != -1)
        return memoi[w];
    if (parent[w].size() == 0)
        return memoi[w] = btime[w];

    int maxv = -1;
    for (int p : parent[w])
    {
        maxv = max(maxv, search(p, parent));
    }
    return memoi[w] = btime[w] + maxv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        vector<vector<int>> parent;
        int n, k, w;
        cin >> n >> k;

        memset(memoi, -1, (n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++)
        {
            cin >> btime[i];
            parent.push_back(vector<int>());
        }
        parent.push_back(vector<int>());
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            parent[y].push_back(x);
        }
        cin >> w;
        cout << search(w, parent) << '\n';
    }
}