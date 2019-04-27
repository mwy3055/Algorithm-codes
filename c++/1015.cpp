#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int a, idx, p;
};

bool psort(const Pair &a, const Pair &b)
{
    if (a.a == b.a)
        return a.idx < b.idx;
    return a.a < b.a;
}
bool isort(const Pair &a, const Pair &b)
{
    return a.idx < b.idx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    Pair p[50];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        p[i] = {a, i, 0};
    }

    sort(p, p + n, psort);
    for (int i = 0; i < n; i++)
        p[i].p = i;

    sort(p, p + n, isort);
    for (int i = 0; i < n; i++)
        cout << p[i].p << " ";
}