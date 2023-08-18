#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, m;
char board[20][21];
int dr[] = {-1, 1, 0, 0}; // 상 하 좌 우
int dc[] = {0, 0, -1, 1};

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> board[i];
}

bool isin(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

int pack(int r, int c)
{
    return r * m + c;
}

int pack(pii p)
{
    return pack(p.first, p.second);
}

pii unpack(int x)
{
    return pii(x / m, x % m);
}

pii find_first_coin()
{
    std::vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'o')
            {
                coins.push_back(pack(i, j));
            }
        }
    }
    std::sort(coins.begin(), coins.end());
    return pii(coins[0], coins[1]);
}

int move(int pos, int dir)
{
    auto [r, c] = unpack(pos);
    auto nr = r + dr[dir], nc = c + dc[dir];
    if (isin(nr, nc) && board[nr][nc] != '#')
        return pack(nr, nc);
    else
        return pack(r, c);
}

bool is_outside(int pos, int dir)
{
    auto [r, c] = unpack(pos);
    r += dr[dir];
    c += dc[dir];
    return !(0 <= r && r < n && 0 <= c && c < m);
}

int solve()
{
    std::queue<pii> q; // 무조건 작은 수가 먼저 옴
    std::set<pii> visit;

    auto first_coin = find_first_coin();
    q.push(first_coin);
    visit.insert(first_coin);

    int count = 0; // 버튼을 누른 횟수
    bool avail = false;
    while (!q.empty())
    {
        count++;
        int size = q.size();
        while (size--)
        {
            auto [c1, c2] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int outside = 0;
                if (is_outside(c1, dir))
                    outside++;
                if (is_outside(c2, dir))
                    outside++;
                if (outside == 1)
                {
                    avail = true;
                    break;
                }
                else if (outside == 0)
                {
                    auto n1 = move(c1, dir), n2 = move(c2, dir);
                    if (n1 > n2)
                        std::swap(n1, n2);
                    auto next = pii(n1, n2);
                    if (visit.find(next) == visit.end())
                    {
                        q.push(next);
                        visit.insert(next);
                    }
                }
                // else: outside = 2: 더이상 이동할 수 없음
                else
                    continue;
            }
        }
        if (avail)
            break;
    }
    if (avail && count <= 10)
        return count;
    else
        return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}