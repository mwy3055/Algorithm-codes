#include <bits/stdc++.h>

using vi = std::vector<int>;
using graph = std::vector<vi>;

int n, m;
int d[][2] = {
    {-1, -1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 1},
    {-1, 1},
};
char room[80][81];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> room[i];
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

bool can_cunning(int r1, int c1, int r2, int c2)
{
    auto dr = r2 - r1, dc = c2 - c1;
    return room[r2][c2] == '.' && std::abs(dr) <= 1 && std::abs(dc) == 1;
}

int index(int r, int c)
{
    return r * m + c;
}

void make_graph(graph &g)
{
    g.resize(n * m, vi());
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c += 2)
        {
            if (room[r][c] == 'x')
                continue;
            auto &cur_graph = g[index(r, c)];
            for (int i = 0; i < 6; i++)
            {
                int nr = r + d[i][0], nc = c + d[i][1];
                if (isin(nr, nc) && can_cunning(r, c, nr, nc))
                {
                    cur_graph.push_back(index(nr, nc));
                }
            }
        }
    }
}

// bipartite matching
bool dfs(int cur, graph &g, vi &track, std::vector<bool> &visit)
{
    for (auto &adj : g[cur])
    {
        if (visit[adj])
            continue;
        visit[adj] = true;
        if (track[adj] == -1 || dfs(track[adj], g, track, visit))
        {
            track[adj] = cur;
            return true;
        }
    }
    return false;
}

int get_total_seat()
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            total += (room[i][j] == '.');
        }
    }
    return total;
}

int solve()
{
    // node: seat, graph: cunning-able-adjacent seat
    graph g;
    make_graph(g);

    // bipartite matching
    std::vector<bool> visit(n * m, false);
    vi track(n * m, -1);
    int match = 0;
    for (int i = 0; i < n * m; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i, g, track, visit))
            match++;
    }

    // answer = maximum independent set
    //        = total - minimum vertex cover(=match)
    auto all = get_total_seat();
    return all - match;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        getinput();
        std::cout << solve() << '\n';
    }
}