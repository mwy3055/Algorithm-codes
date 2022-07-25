#include <bits/stdc++.h>

int board, star_count;
std::vector<bool> visit(1 << 25, false);
int d[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void getinput()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            char c;
            std::cin >> c;
            if (c == '*')
            {
                star_count++;
                board |= (1 << (i * 5 + j));
            }
        }
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < 5 && 0 <= c && c < 5;
}

// check if all stars are connected
bool adjacent(int cur)
{
    bool cvisit[25] = {false};
    int count = 0;
    std::queue<int> q;

    // start bfs
    for (int i = 0; i < 25; i++)
    {
        if (cur & (1 << i))
        {
            q.push(i);
            cvisit[i] = true;
            count++;
            break;
        }
    }
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            auto nr = top / 5 + d[i][0], nc = top % 5 + d[i][1];
            auto nidx = nr * 5 + nc;
            if (isin(nr, nc) && !cvisit[nidx] && (cur & (1 << nidx)))
            {
                q.push(nidx);
                cvisit[nidx] = true;
                count++;
            }
        }
    }
    return count == star_count;
}

void search(std::queue<int> &q, int cur)
{
    for (int i = 0; i < 25; i++)
    {
        // search if star exists
        if (cur & (1 << i))
        {
            for (int j = 0; j < 4; j++)
            {
                int nr = i / 5 + d[j][0], nc = i % 5 + d[j][1];
                // move i-th star to (nr, nc)
                auto next = cur ^ (1 << i) | (1 << (nr * 5 + nc));
                if (isin(nr, nc) && !visit[next])
                {
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
    }
}

int solve()
{
    std::queue<int> q;

    // bfs with bitmask
    q.push(board);
    visit[board] = true;
    int count = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto cur = q.front();
            q.pop();
            if (adjacent(cur))
            {
                return count;
            }
            search(q, cur);
        }
        count++;
    }
    std::cout << "FAIL" << '\n';
    exit(-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}