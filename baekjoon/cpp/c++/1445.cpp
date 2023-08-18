#include <bits/stdc++.h>

using pii = std::pair<int, int>;

struct node
{
    int r, c;
    int g, ng;
    node(int r, int c, int g, int ng) : r(r), c(c), g(g), ng(ng) {}
};

int n, m;
char map[50][51];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

bool is_garbage[50][50], is_near_garbage[50][50];
std::vector<pii> garbages;

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < m;
}

pii find(char c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == c)
                return pii(i, j);
        }
    }
    exit(-1);
}

void check_garbage()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'g')
            {
                is_garbage[i][j] = true;
                garbages.emplace_back(i, j);
            }
        }
    }
}

void check_near_garbage()
{
    for (auto &[r, c] : garbages)
    {
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (isin(nr, nc) && map[nr][nc] == '.')
            {
                is_near_garbage[nr][nc] = true;
            }
        }
    }
}

bool visit[50][50];
struct comp
{
    bool operator()(const node &a, const node &b)
    {
        if (a.g != b.g)
        {
            return a.g > b.g;
        }
        return a.ng > b.ng;
    }
};

pii solve()
{
    check_garbage();
    check_near_garbage();

    auto [sr, sc] = find('S');
    auto [fr, fc] = find('F');

    std::priority_queue<node, std::vector<node>, comp> pq;

    pq.emplace(sr, sc, 0, 0);
    while (!pq.empty())
    {
        auto [r, c, g, near_g] = pq.top();
        pq.pop();

        if (r == fr && c == fc)
            return pii(g, near_g);

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (isin(nr, nc) && !visit[nr][nc])
            {
                visit[nr][nc] = true;
                int new_g = g + is_garbage[nr][nc];
                int new_near_g = near_g + is_near_garbage[nr][nc];
                pq.emplace(nr, nc, new_g, new_near_g);
            }
        }
    }
    return pii(-1, -1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    auto ans = solve();
    std::cout << ans.first << ' ' << ans.second << '\n';
}