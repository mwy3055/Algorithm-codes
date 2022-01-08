#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using pipii = std::pair<int, pii>;

// Union-find
const int MAX = 6;

int root[MAX + 1];

void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}

int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}

void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        std::swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}
// Union-find end

struct point
{
    int r, c;
    point(int r = -1, int c = -1) : r(r), c(c) {}
    bool operator!=(point b)
    {
        return this->r != b.r || this->c != b.c;
    }
};

const int INF = 0x3f3f3f3f;
int n, m, map[10][10];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0}, dist[7][7];
bool visit[10][10];
std::vector<std::vector<point>> country;

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> map[i][j];
}

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < m;
}

void find_country(int r, int c, const int &no)
{
    country.emplace_back();
    std::queue<point> q;

    visit[r][c] = true;
    q.emplace(r, c);
    map[r][c] = no;
    country.back().emplace_back(r, c);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = top.r + dr[i], nc = top.c + dc[i];
            if (isin(nr, nc) && map[nr][nc] && !visit[nr][nc])
            {
                visit[nr][nc] = true;
                q.emplace(nr, nc);
                map[nr][nc] = no;
                country.back().emplace_back(nr, nc);
            }
        }
    }
}

void find_countries()
{
    country.emplace_back();
    int country_no = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] && !visit[i][j])
                find_country(i, j, ++country_no);
        }
    }
}

int get_dist(int i, int j)
{
    std::vector<int> dist;
    for (auto &node : country[i])
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int r = node.r, c = node.c, d = 0;
            while (isin(r, c))
            {
                r += dr[dir], c += dc[dir], d++;
                if (isin(r, c) && map[r][c] == j)
                {
                    dist.push_back(d - 1);
                    break;
                }
                else if (map[r][c])
                    break;
            }
        }
    }

    std::sort(dist.begin(), dist.end());
    dist.erase(std::unique(dist.begin(), dist.end()), dist.end());
    dist.push_back(INF);
    return (dist.front() == 1 ? dist[1] : dist.front());
}

void calculate_dist()
{
    int n_node = country.size() - 1;
    for (int i = 1; i <= n_node; i++)
    {
        for (int j = i + 1; j <= n_node; j++)
        {
            dist[i][j] = dist[j][i] = get_dist(i, j);
        }
    }
}

int solve(int &n, std::vector<pipii> &adj)
{
    init();

    int node_count = 0, sum = 0;
    std::sort(adj.begin(), adj.end());
    for (auto &e : adj)
    {
        auto &d = e.first, a = e.second.first, b = e.second.second;
        if (d == INF || find(a) == find(b))
            continue;
        union_vertex(a, b);
        sum += d;
        if (++node_count == n - 1)
            break;
    }
    return (node_count == n - 1 ? sum : -1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    find_countries();

    calculate_dist();

    int n_node = country.size() - 1;
    std::vector<pipii> edges;
    for (int i = 1; i <= n_node; i++)
    {
        for (int j = i + 1; j <= n_node; j++)
        {
            edges.emplace_back(dist[i][j], pii(i, j));
        }
    }
    std::cout << solve(n_node, edges) << '\n';
}