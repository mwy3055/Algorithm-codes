#include <bits/stdc++.h>

int n, graph[1001][1001], degree[1001];

void search(int cur)
{
    for (int j = 1; j <= n; j++)
    {
        if (graph[cur][j] > 0)
        {
            graph[cur][j]--;
            graph[j][cur]--;
            search(j);
        }
    }
    std::cout << cur << ' ';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    bool has_circuit = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> graph[i][j];
            degree[i] += graph[i][j];
        }
        if (degree[i] % 2 == 1)
            has_circuit = false;
    }

    if (has_circuit)
        search(1);
    else
        std::cout << -1;
}