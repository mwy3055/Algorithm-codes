#include <bits/stdc++.h>

using vi = std::vector<int>;

const int INF = 100;
int ans;

// chosen: 현재까지 고른 음식의 수
void search(const int &n,
            const int &m,
            std::vector<vi> &eaters,
            std::vector<vi> &can_eat,
            vi &edible,
            int chosen)
{
    // 가장 쉬운 가지치기
    if (chosen >= ans)
    {
        return;
    }

    // 먹을 음식이 하나도 없는 최초의 친구
    auto first = std::find(edible.begin(), edible.end(), 0) - edible.begin();
    if (first == n)
    {
        ans = chosen;
        return;
    }

    for (auto &food : can_eat[first])
    {
        for (auto &eater : eaters[food])
            edible[eater]++;
        search(n, m, eaters, can_eat, edible, chosen + 1);
        for (auto &eater : eaters[food])
            edible[eater]--;
    }
}

// eaters: i번 음식을 먹을 수 있는 친구의 집합
// can_eat: i번 친구가 먹을 수 있는 음식의 집합
// edible: 탐색 과정에서 i번 친구가 먹을 수 있는 음식의 수
int solve(int &n, int &m, std::vector<vi> &eaters)
{
    std::vector<vi> can_eat(n);
    for (int food = 0; food < m; food++)
    {
        for (auto &eater : eaters[food])
        {
            can_eat[eater].push_back(food);
        }
    }
    vi edible(n, 0);
    search(n, m, eaters, can_eat, edible, 0);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = INF;

        int n, m;
        std::cin >> n >> m;
        std::map<std::string, int> nmap;
        for (int j = 0; j < n; j++)
        {
            std::string s;
            std::cin >> s;
            nmap[s] = j;
        }
        std::vector<vi> eaters(m);
        for (int i = 0; i < m; i++)
        {
            int count;
            std::cin >> count;
            for (int j = 0; j < count; j++)
            {
                std::string name;
                std::cin >> name;
                eaters[i].push_back(nmap[name]);
            }
        }
        std::cout << solve(n, m, eaters) << '\n';
    }
}