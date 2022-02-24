#include <bits/stdc++.h>

int n, order[3001], parent[3001], dist[3001];
std::vector<int> graph[3001];
bool cycle[3001];
// 사이클의 시작점, 끝점
int cycle_start;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        std::sort(graph[i].begin(), graph[i].end());
}

void make_cycle(int end, int start)
{
    int cur = end;
    do
    {
        cycle[cur] = true;
        cur = parent[cur];
    } while (cur != start);
    cycle[start] = true;
}

// 사이클 탐색
void dfs(int cur, int from)
{
    parent[cur] = from;
    for (auto &child : graph[cur])
    {
        if (child == from)
            continue;
        if (order[child] == 0)
        {
            order[child] = order[cur] + 1;
            dfs(child, cur);
        }
        else if (order[child] < order[cur])
        {
            // cycle!
            cycle_start = cur;
            make_cycle(cur, child);
        }
    }
}

// 거리 탐색
void find_dist(int cur, int from)
{
    if (cycle[cur])
        dist[cur] = 0;
    else
        dist[cur] = dist[from] + 1;
    for (auto &child : graph[cur])
    {
        if (dist[child] == -1)
            find_dist(child, cur);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();

    order[1] = 1;
    dfs(1, 1);

    std::memset(dist, -1, sizeof(dist));
    find_dist(cycle_start, cycle_start);

    for (int i = 1; i <= n; i++)
        std::cout << dist[i] << ' ';
}