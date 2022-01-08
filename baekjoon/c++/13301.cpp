#include <iostream>
using namespace std;

typedef long long ll;

void fib(int &n, ll &fn, ll &fn1)
{
    ll f[81] = {0, 1, 1};
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    fn = f[n];
    fn1 = f[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll fn, fn1;
    cin >> n;
    fib(n, fn, fn1);

    cout << 2 * (2 * fn + fn1);
}