#include <bits/stdc++.h>

struct edge
{
    int dest, cost;
    edge(int d, int c) : dest(d), cost(c) {}
};

std::vector<edge> graph[10001];
std::vector<int> track[10001]; // track[i]: 최장 경로에서 i 이후의 노드(들)
int dist[10001];               // dist[i]: 최장 경로에서, i번 노드에서 도착 노드까지의 거리

int search(int cur, int &finish) // cur에서 finish까지의 최장 거리를 반환
{
    auto &ret = dist[cur];
    if (cur == finish)
    {
        return ret = 0;
    }
    if (ret != -1)
        return ret;
    ret = 0;
    for (auto &e : graph[cur])
    {
        int d = search(e.dest, finish) + e.cost;
        if (ret < d)
        {
            ret = d;
            track[cur].clear();
            track[cur].push_back(e.dest);
        }
        else if (ret == d)
        {
            track[cur].push_back(e.dest);
        }
    }
    return ret;
}

bool visit[10001];
int count_edge(int &start, int &finish)
{
    std::queue<int> q;
    q.push(start);
    visit[start] = true;

    int count = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        if (cur == finish)
            continue;

        count += track[cur].size();
        for (auto &adj : track[cur])
        {
            if (!visit[adj])
            {
                q.push(adj);
                visit[adj] = true;
            }
        }
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(dist, -1, sizeof(dist));

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, d, c;
        std::cin >> s >> d >> c;
        graph[s].emplace_back(d, c);
    }

    int start, finish;
    std::cin >> start >> finish;
    std::cout << search(start, finish) << '\n'
              << count_edge(start, finish) << '\n';
}