#include <bits/stdc++.h>

using vi = std::vector<int>;
std::vector<vi> tubes, included;

bool visit[100001];
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
                return ans;

            for (auto &tube : included[cur])
            {
                for (auto &elem : tubes[tube])
                {
                    if (!visit[elem])
                    {
                        q.push(elem);
                        visit[elem] = true;
                    }
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
    included.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        tubes.push_back(vi());
        for (int j = 0; j < k; j++)
        {
            int x;
            std::cin >> x;
            tubes.back().push_back(x);
        }
    }

    std::sort(tubes.begin(), tubes.end());
    tubes.erase(std::unique(tubes.begin(), tubes.end()), tubes.end());

    for (int i = 0; i < tubes.size(); i++)
    {
        for (auto &elem : tubes[i])
        {
            included[elem].push_back(i);
        }
    }

    std::cout << solve(n) << '\n';
}