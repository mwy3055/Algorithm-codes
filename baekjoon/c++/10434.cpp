#include <bits/stdc++.h>
using namespace std;

bool notprime[10001], cnt[10001];

void init()
{
    notprime[0] = notprime[1] = true;
    for (int i = 2; i * i <= 10000; i++)
    {
        if (notprime[i] == false)
        {
            for (int j = i * i; j <= 10000; j += i)
                notprime[j] = true;
        }
    }
}
bool solve(int n)
{
    for (int i = 0; i <= 10000; i++)
        cnt[i] = false;
    while (true)
    {
        if (n == 1)
            return true;
        else if (cnt[n])
            return false;
        cnt[n] = true;
        int temp = 0;
        while (n)
        {
            temp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = temp;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int p;
    cin >> p;
    while (p--)
    {
        int nth, m;
        cin >> nth >> m;
        if (!notprime[m] && solve(m))
            cout << nth << ' ' << m << ' ' << "YES" << '\n';
        else
            cout << nth << ' ' << m << ' ' << "NO" << '\n';
    }
}