#include <bits/stdc++.h>

// count, value
using pii = std::pair<int, int>;

const int MAX = 1000000;
int n;
int a[MAX + 1], f[MAX + 1], ngf[MAX + 1];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        f[a[i]]++;
    }
}

void calc()
{
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    for (int i = n - 1; i >= 0; i--)
    {
        // do what?
        while (!pq.empty() && pq.top().first <= f[a[i]])
            pq.pop();
        if (pq.empty())
            ngf[i] = -1;
        else
            ngf[i] = pq.top().second;
        pq.push(pii(f[a[i]], a[i]));
    }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << ngf[i] << ' ';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    calc();
    print();
}