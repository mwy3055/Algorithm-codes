#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 100001;
int root[MAX + 1];
ll weight[MAX + 1];
void init()
{
    memset(root, 0xff, sizeof(int) * (MAX + 1));
    memset(weight, 0, sizeof(ll) * (MAX + 1));
}
int find(int n)
{
    auto &r = root[n];
    if (r < 0)
        return n;
    int root_top = find(r);
    weight[n] += weight[r];
    cout << "weight of " << n << " updated to " << weight[n] << ", root: " << root_top << '\n';
    return r = root_top;
}
void union_vertex(int a, int b, ll w) // a is w grams lighter than b: a°¡ ±âÁØ
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;
    root[root1] = root2;
    weight[root1] = w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (n)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            char c;
            int a, b, w;
            cin >> c;
            if (c == '!')
            {
                cin >> a >> b >> w;
                union_vertex(a, b, w);
            }
            else
            {
                cin >> a >> b;
                int root1 = find(a), root2 = find(b);
                if (root1 == root2)
                    cout << -(weight[b] - weight[a]) << '\n';
                else
                    cout << "UNKNOWN" << '\n';
            }
        }
        cin >> n >> m;
    }
}

/* test case
5 10
! 1 2 100
? 2 3
! 2 3 100
? 2 3
? 1 3
! 4 3 150
? 4 1
! 2 5 100
? 1 2
? 1 5
0 0

+ ICPC regional datas

*/