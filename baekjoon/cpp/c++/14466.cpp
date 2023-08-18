#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, k, r;
std::vector<bool> road[10000], visit[100];
std::vector<pii> cows, d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int number[100][100];

int idx(int r, int c)
{
    return r * n + c;
}

int idx(pii &p)
{
    return idx(p.first, p.second);
}

void getinput()
{
    // all 0-indexed
    std::cin >> n >> k >> r;
    for (int i = 0; i < n * n; i++)
    {
        road[i].resize(n * n, false);
    }
    for (int i = 0; i < r; i++)
    {
        // convert 2d index to 1d
        int r1, c1, r2, c2;
        std::cin >> r1 >> c1 >> r2 >> c2;
        road[idx(r1 - 1, c1 - 1)][idx(r2 - 1, c2 - 1)] = true;
        road[idx(r2 - 1, c2 - 1)][idx(r1 - 1, c1 - 1)] = true;
    }
    for (int i = 0; i < k; i++)
    {
        int r, c;
        std::cin >> r >> c;
        cows.emplace_back(r - 1, c - 1);
    }
}

pii sum(pii a, pii b)
{
    return pii(a.first + b.first, a.second + b.second);
}

bool isin(pii &p)
{
    auto &r = p.first, &c = p.second;
    return 0 <= r && r < n && 0 <= c && c < n;
}

bool can_visit(pii &cur, pii &next)
{
    return isin(next) && !visit[next.first][next.second] && !road[idx(cur)][idx(next)];
}

void set_visit(pii &p)
{
    visit[p.first][p.second] = true;
}

void set_number(pii &p, int &num)
{
    number[p.first][p.second] = num;
}

void bfs(int &r, int &c, int &num)
{
    std::queue<pii> q;

    q.push({r, c});
    visit[r][c] = true;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        set_number(cur, num);
        for (auto &delta : d)
        {
            auto next = sum(cur, delta);
            if (can_visit(cur, next))
            {
                q.push(next);
                set_visit(next);
            }
        }
    }
}

bool can_meet(int &cow1, int &cow2)
{
    auto r1 = cows[cow1].first, c1 = cows[cow1].second;
    auto r2 = cows[cow2].first, c2 = cows[cow2].second;
    return number[r1][c1] == number[r2][c2];
}

int solve()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        visit[i].resize(n, false);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // visit all areas from current area
            if (!visit[i][j])
            {
                bfs(i, j, ++cnt);
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (!can_meet(i, j))
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}