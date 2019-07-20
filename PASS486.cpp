#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000000;
int minFactor[MAX + 1], factor[MAX + 1]; //minFactor[i]: i의 가장 작은 소인수, factor[i]: i의 약수의 개수

void eratosthenes()
{
    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i <= MAX; i++)
        minFactor[i] = i;

    int sqrtMax = (int)sqrt(MAX);
    for (int i = 2; i <= sqrtMax; i++)
    {
        if (minFactor[i] == i)
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                if (minFactor[j] == j)
                    minFactor[j] = i;
            }
        }
    }
}
int factorNum(int n)
{
    int ans = 1;
    while (n > 1)
    {
        if (factor[n])
        {
            ans *= factor[n];
            break;
        }
        int cnt = 0, tempFactor = minFactor[n];
        do
        {
            n /= minFactor[n];
            cnt++;
        } while (tempFactor == minFactor[n]);
        ans *= (cnt + 1);
    }
    return ans;
}
void preprocess()
{
    for (int i = 2; i <= MAX; i++)
    {
        factor[i] = factorNum(i);
    }
}

int solve(int c, int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        if (factor[i] == c)
            ans++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    eratosthenes();
    preprocess();

    int t;
    cin >> t;
    while (t--)
    {
        int c, lo, hi;
        cin >> c >> lo >> hi;
        cout << solve(c, lo, hi) << '\n';
    }
}