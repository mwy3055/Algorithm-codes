#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
std::vector<int> graph[801];
int capacity[801][801], flow[801][801];

// https://blog.naver.com/kks227/220804885235

int getin(int index)
{
    if (index == 1 || index == 2)
        return index;
    return 2 * index - 3;
}
int getout(int index)
{
    if (index == 1 || index == 2)
        return index;
    return 2 * index - 2;
}

int solve(int start, int end)
{
    std::vector<int> track(801);
    int rtn = 0;
    while (true)
    {
        std::fill(track.begin(), track.end(), -1);
        std::queue<int> q;
        q.push(start);
        track[start] = start;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto &adj : graph[top])
            {
                if (capacity[top][adj] - flow[top][adj] > 0 && track[adj] == -1)
                {
                    track[adj] = top;
                    q.push(adj);
                    if (adj == end)
                        break;
                }
            }
        }
        if (track[end] == -1)
            break;
        int maxflow = INF, cur = end;
        while (cur != start)
        {
            auto before = track[cur];
            maxflow = std::min(maxflow, capacity[before][cur] - flow[before][cur]);
            cur = before;
        }

        cur = end;
        while (cur != start)
        {
            auto before = track[cur];
            flow[before][cur] += maxflow;
            flow[cur][before] -= maxflow;
            cur = before;
        }
        rtn += maxflow;
    }
    return rtn;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, p;
    std::cin >> n >> p;
    // split node
    for (int i = 3; i <= n; i++)
    {
        int in = getin(i), out = getout(i);
        graph[in].push_back(out);
        capacity[in][out] = 1;
    }
    for (int i = 0; i < p; i++)
    {
        int a, b;
        std::cin >> a >> b;
        auto ain = getin(a), aout = getout(a);
        auto bin = getin(b), bout = getout(b);
        // pair of edge: for negative flows
        graph[aout].push_back(bin);
        graph[bin].push_back(aout);
        capacity[aout][bin] = 1;

        graph[bout].push_back(ain);
        graph[ain].push_back(bout);
        capacity[bout][ain] = 1;
    }

    std::cout << solve(1, 2) << '\n';
}