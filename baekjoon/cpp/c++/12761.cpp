#include <bits/stdc++.h>

using pii = std::pair<int, int>; // jump count, cur index
using PQ = std::priority_queue<pii, std::vector<pii>, std::greater<pii>>;
bool visit[100001];

bool isin(int i)
{
    return 0 <= i && i <= 100000;
}

void push_if(std::queue<int> &q, int loc)
{
    if (isin(loc) && !visit[loc])
    {
        q.push(loc);
        visit[loc] = true;
    }
}

int solve(int a, int b, int n, int m)
{
    std::queue<int> q;
    q.push(n);
    int count = 0;
    while (!q.empty())
    {
        int siz = q.size();
        while (siz--)
        {
            auto cur = q.front();
            q.pop();
            if (cur == m)
                return count;
            push_if(q, cur - 1);
            push_if(q, cur + 1);
            push_if(q, cur + a);
            push_if(q, cur - a);
            push_if(q, cur + b);
            push_if(q, cur - b);
            push_if(q, cur * a);
            push_if(q, cur * b);
        }
        count++;
    }
    return 0;
}

int main()
{
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;
    std::cout << solve(a, b, n, m);
}