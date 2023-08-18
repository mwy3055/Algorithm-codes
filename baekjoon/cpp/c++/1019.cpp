#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// from https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019
ll n, arr[10];

void naive(ll n, ll coef)
{
    do
    {
        arr[n % 10] += coef;
        n /= 10;
    } while (n);
}
void solve(ll a, ll b, ll coef)
{
    while (a % 10 != 0 && a <= b)
    {
        naive(a++, coef);
    }
    if (a > b)
        return;
    while (b % 10 != 9 && a <= b)
    {
        naive(b--, coef);
    }
    ll count = b / 10 - a / 10 + 1;
    for (int i = 0; i <= 9; i++)
        arr[i] += count * coef;
    solve(a / 10, b / 10, coef * 10);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    solve(1, n, 1);
    for (int i = 0; i <= 9; i++)
        cout << arr[i] << ' ';
}