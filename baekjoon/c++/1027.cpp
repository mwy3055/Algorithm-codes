#include <bits/stdc++.h>

using ll = long long;

// Is it able to see building j from building i?
bool cansee(int i, int j, std::vector<ll> &h)
{
    bool condition = true;
    if (i < j)
    {
        for (int k = i + 1; k < j; k++)
        {
            if ((k - i) * (h[j] - h[i]) <= (j - i) * (h[k] - h[i]))
            {
                condition = false;
            }
        }
    }
    else
    {
        for (int k = j + 1; k < i; k++)
        {
            if ((k - i) * (h[j] - h[i]) >= (j - i) * (h[k] - h[i]))
                condition = false;
        }
    }
    return condition;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<ll> heights;
    for (int i = 0; i < n; i++)
    {
        ll h;
        std::cin >> h;
        heights.push_back(h);
    }

    int maxcount = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (cansee(i, j, heights))
                count++;
        }
        maxcount = std::max(maxcount, count);
    }
    std::cout << maxcount;
}