#include <bits/stdc++.h>

std::vector<int> graph[101001];
bool visit[101001];
const int OFFSET = 100000;

int solve(int n)
{
    std::queue<int> q;

    q.push(1);
    visit[1] = true;
    int ans = 0;
    while (!q.empty())
    {
        ans++;
        int siz = q.size();
        while (siz--)
        {
            int cur = q.front();
            q.pop();
            if (cur == n)
                return (ans / 2) + 1;

            for (auto &adj : graph[cur])
            {
                if (!visit[adj])
                {
                    q.push(adj);
                    visit[adj] = true;
                }
            }
        }
    }
    return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int x;
            std::cin >> x;
            graph[x].push_back(OFFSET + i);
            graph[OFFSET + i].push_back(x);
        }
    }

    std::cout << solve(n) << '\n';
}