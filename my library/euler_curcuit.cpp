#include <bits/stdc++.h>

/**
 * n: 정점의 개수
 * graph[i][j]: i번과 j번 정점을 연결하는 간선의 개수
 * degree[i]: i번 정점의 차수
 */
int n, graph[1001][1001], degree[1001];

void search(int cur)
{
    // 방문 가능한 모든 정점을 방문하고 다시 현재 위치로 돌아옴
    for (int j = 1; j <= n; j++)
    {
        if (graph[cur][j] > 0)
        {
            graph[cur][j]--;
            graph[j][cur]--;
            search(j);
        }
    }
    // 방문 종료
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
        // 정점의 차수가 모두 짝수여야만 오일러 회로가 존재
        if (degree[i] % 2 == 1)
            has_circuit = false;
    }

    if (has_circuit)
        search(1);
    else
        std::cout << -1;
}