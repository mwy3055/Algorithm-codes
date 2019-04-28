#include <bits/stdc++.h>
using namespace std;

int n, need[10000], limit;

void getinput(int &maxneed)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> need[i];
        maxneed = max(maxneed, need[i]);
    }
    cin >> limit;
}

int getsum(int &limit)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(limit, need[i]);
    }
    return sum;
}
int solve(int nmin, int nmax) //ÀÌºĞÅ½»ö
{
    while (nmin < nmax)
    {
        int mid = (nmin + nmax) / 2 + 1;
        int alloc = getsum(mid);
        if (limit < alloc)
        {
            nmax = mid - 1;
        }
        else
        {
            nmin = mid;
        }
    }

    return nmin;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int maxneed;
    getinput(maxneed);
    cout << solve(0, maxneed);
}