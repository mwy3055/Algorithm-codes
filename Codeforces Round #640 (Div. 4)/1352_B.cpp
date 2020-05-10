#include <bits/stdc++.h>
using namespace std;

void solve1(int n, int k)
{
    if (n - k + 1 <= 0)
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < k - 1; i++)
        cout << 1 << ' ';
    cout << (n - k + 1) << '\n';
}
void solve2(int n, int k)
{
    if (n - (k - 1) * 2 <= 0)
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < k - 1; i++)
        cout << 2 << ' ';
    cout << n - (k - 1) * 2 << '\n';
}
void solve3(int n, int k)
{
    cout << "NO" << '\n';
}
void solve4(int n, int k)
{
    if (n - k + 1 <= 0)
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < k - 1; i++)
        cout << 1 << ' ';
    cout << n - k + 1 << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0 && k % 2 == 0)
            solve1(n, k);
        else if (n % 2 == 0 && k % 2)
            solve2(n, k);
        else if (n % 2 && k % 2 == 0)
            solve3(n, k);
        else
            solve4(n, k);
    }
}