#include <bits/stdc++.h>

using pii = std::pair<int, int>; // cost, dest
int n;
std::vector<pii> graph[1001];
int par[1001], sd[1001];
bool visit[1001];

void init()
{
    std::memset(par, 0, sizeof(par));
    std::memset(sd, 0, sizeof(sd));
    std::memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= 1000; i++)
    {
        graph[i].clear();
    }
}

void getinput()
{
    int m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        std::cin >> a >> b >> d;
        graph[a].emplace_back(d, b);
        graph[b].emplace_back(d, a);
    }
}

int search(int x)
{
    visit[x] = true;
    for (auto &[cost, child] : graph[x])
    {
        if (!visit[child])
        {
            visit[child] = true;
            par[child] = cost;
            auto rtn = search(child);
            if (rtn == 0)
                sd[x] += cost;
            else
                sd[x] += rtn;
        }
    }
    return sd[x];
}

// x의 서브 트리에서 간선을 제거한다면?
int remove_edge(int x)
{
    visit[x] = true;
    int sum = 0;
    for (auto &[cost, child] : graph[x])
    {
        if (!visit[child])
        {
            visit[child] = true;
            if (sd[child] == 0) // 리프는 무조건 잘라야
            {
                sum += cost;
            }
            else
            {
                // 밑에서 cut? 여기서 cut?
                auto child_cut = remove_edge(child);
                sum += std::min(child_cut, cost);
            }
        }
    }
    return sum;
}

int solve()
{
    // 트리 만들고
    search(1);
    std::memset(visit, 0, sizeof(visit));
    // 자른다.
    int ans = remove_edge(1);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        init();
        getinput();
        std::cout << solve() << '\n';
    }
}