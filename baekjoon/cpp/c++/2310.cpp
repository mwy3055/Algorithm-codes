#include <bits/stdc++.h>

const int MAX = 1001;
using pii = std::pair<int, int>; // money, room

int n;
char type[MAX];
int price[MAX];
std::vector<int> graph[MAX];

void getinput()
{
    std::cin >> n;
    if (n == 0)
        exit(0);
    for (int i = 1; i <= n; i++)
    {
        graph[i].clear();
        std::cin >> type[i] >> price[i];
        int adj;
        while (true)
        {
            std::cin >> adj;
            if (adj == 0)
                break;
            graph[i].push_back(adj);
        }
    }
}

int move(int dest, int money)
{
    switch (type[dest])
    {
    case 'E':
        return money;
    case 'L':
        return std::max(money, price[dest]);
    case 'T':
        return money - price[dest];
    default:
        exit(-1);
    }
}

bool solve()
{
    // 돈이 제일 많은 경우부터 탐색
    std::priority_queue<pii> pq;
    std::vector<bool> visit(MAX, false);
    std::vector<int> max_money(MAX, -1);

    pq.emplace(0, 1);
    visit[1] = true;
    while (!pq.empty())
    {
        auto [money, room] = pq.top();
        pq.pop();
        if (room == n)
            return true;
        for (auto &adj : graph[room])
        {
            auto next_money = move(adj, money);
            if (next_money > max_money[adj])
            {
                pq.emplace(next_money, adj);
                max_money[adj] = next_money;
            }
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    while (true)
    {
        getinput();
        std::cout << (solve() ? "Yes" : "No") << '\n';
    }
}