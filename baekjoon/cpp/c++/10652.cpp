#include <bits/stdc++.h>

using ll = long long;

int b, e, p, n, m;
std::vector<int> graph[40001];
int dist[3][40001]; // distance between (1 or 2) to n
bool visit[40001];

void getinput()
{
    std::cin >> b >> e >> p >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p1, p2;
        std::cin >> p1 >> p2;
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
}

void set_dist(int i, int j, int d)
{
    if (i <= 2)
        dist[i - 1][j] = d;
    else
        dist[2][j] = d;
}

int get_dist(int i, int j)
{
    if (i <= 2)
        return dist[i - 1][j];
    return dist[2][j];
}

void bfs(int start)
{
    std::memset(visit, 0, sizeof(visit));
    std::queue<int> q;

    ll cnt = 0;
    q.push(start);
    visit[start] = true;
    while (!q.empty())
    {
        auto size = q.size();
        while (size--)
        {
            auto cur = q.front();
            q.pop();
            set_dist(start, cur, cnt);

            for (auto &adj : graph[cur])
            {
                if (!visit[adj])
                {
                    q.push(adj);
                    visit[adj] = true;
                }
            }
        }
        cnt++;
    }
}

ll solve()
{
    // 일단 거리 구해놓고
    bfs(1);
    bfs(2);
    bfs(n);
    ll ans = 0x3f3f3f3f;
    // min(i번 field에서 만나서 갈 때의 에너지)를 구한다.
    for (int i = 1; i <= n; i++)
    {
        ll bessie = b * get_dist(1, i);
        ll elsie = e * get_dist(2, i);
        ll piggyback = p * get_dist(n, i);
        ans = std::min(ans, bessie + elsie + piggyback);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}