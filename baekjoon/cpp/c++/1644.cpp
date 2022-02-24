#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void prime(vector<int> &pr, int n)
{
    vector<bool> prime(n + 1, true);
    prime[1] = false;
    for (int i = 4; i <= n; i += 2)
        prime[i] = false;
    for (int i = 3; i <= (int)sqrt(n); i += 2)
    {
        if (prime[i] == true)
        {
            for (long j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    for (int i = 1; i <= n; i++)
        if (prime[i])
            pr.push_back(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> pr;
    int n;
    cin >> n;
    prime(pr, n);

    int s = 0, e = -1, cnt = 0, siz = pr.size();
    long sum = 0;
    while (s < siz)
    {
        if (sum == n)
        {
            cnt++;
            sum -= pr[s++];
            if (e < siz - 1)
                sum += pr[++e];
        }
        else if (sum < n)
        {
            if (e < siz - 1)
                sum += pr[++e];
            else
            {
                break;
            }
        }
        else
        {
            sum -= pr[s++];
        }
    }
    cout << cnt;
}