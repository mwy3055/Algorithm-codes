#include <bits/stdc++.h>

std::vector<int> graph[51]; // [1, n]
int track[51];
std::vector<bool> visit(51);

struct shark
{
    int size, speed, intelli;
    bool operator>(const shark &s)
    {
        return (size > s.size) && (speed > s.speed) && (intelli > s.intelli);
    }
    bool operator>=(const shark &s)
    {
        return (size >= s.size) && (speed >= s.speed) && (intelli >= s.intelli);
    }
    bool operator==(const shark &s)
    {
        return (size == s.size) && (speed == s.speed) && (intelli == s.intelli);
    }
    bool operator!=(const shark &s)
    {
        return !(*this == s);
    }
};

bool dfs(int cur)
{
    for (auto &adj : graph[cur])
    {
        if (visit[adj])
            continue;
        visit[adj] = true;
        if (track[adj] == 0 || dfs(track[adj]))
        {
            track[adj] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<shark> sharks(n);
    for (auto &s : sharks)
        std::cin >> s.size >> s.speed >> s.intelli;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (sharks[i] == sharks[j] && i < j) // equal: only a shark with small index can eat another
                graph[i + 1].push_back(j + 1);
            else if (sharks[i] != sharks[j] && sharks[i] >= sharks[j])
                graph[i + 1].push_back(j + 1);
        }
    }

    int eat = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::fill(visit.begin(), visit.end(), false);
            if (dfs(i))
                eat++;
        }
    }
    std::cout << n - eat << '\n';
}