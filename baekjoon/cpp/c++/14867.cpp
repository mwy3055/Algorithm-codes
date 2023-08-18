#include <bits/stdc++.h>

using pii = std::pair<int, int>;

void search(std::set<pii> &s, std::queue<pii> &q, pii p)
{
    if (s.find(p) == s.end())
    {
        s.insert(p);
        q.push(p);
    }
}

// std::map으로 되네..
int solve(int a, int b, int c, int d)
{
    std::set<pii> s;
    std::queue<pii> q;

    auto begin = pii(0, 0), end = pii(c, d);
    s.insert(begin);
    q.push(begin);

    int count = 0;
    while (!q.empty())
    {
        auto size = q.size();
        while (size--)
        {
            auto top = q.front();
            q.pop();
            if (top == end)
                return count;

            auto wa = top.first, wb = top.second;
            search(s, q, pii(a, wb));
            search(s, q, pii(wa, b));
            search(s, q, pii(0, wb));
            search(s, q, pii(wa, 0));
            // M(a, b)
            if (a - wa > wb)
            {
                // B의 물을 A에 모두 부을 수 있음
                search(s, q, pii(wa + wb, 0));
            }
            else
            {
                search(s, q, pii(a, wb - (a - wa)));
            }
            // M(b, a)
            if (b - wb > wa)
            {
                search(s, q, pii(0, wa + wb));
            }
            else
            {
                search(s, q, pii(wa - (b - wb), b));
            }
        }
        count++;
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    std::cout << solve(a, b, c, d) << '\n';
}