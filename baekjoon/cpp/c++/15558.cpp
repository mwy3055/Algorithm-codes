#include <bits/stdc++.h>

bool visit[2][100000];

struct loc
{
    int pos, idx;
    loc(int pos, int idx) : pos(pos), idx(idx) {}
};

void push_if(std::queue<loc> &q, std::vector<std::string> &map, int pos, int idx, int t)
{
    if (idx < t)
        return;
    if (idx >= map[0].length())
        q.push(loc(pos, idx));
    else if (map[pos][idx] == '1' && !visit[pos][idx])
    {
        q.push(loc(pos, idx));
        visit[pos][idx] = true;
    }
}

bool solve(int n, int k, std::vector<std::string> &map)
{
    std::queue<loc> q;

    q.push(loc(0, 0));
    visit[0][0] = true;
    for (int t = 0; t <= n; t++)
    {
        int siz = q.size();
        while (siz--)
        {
            auto top = q.front();
            auto &pos = top.pos, &idx = top.idx;
            q.pop();
            if (idx >= n)
                return true;
            if (idx < t)
                continue;

            push_if(q, map, pos, idx + 1, t);
            push_if(q, map, pos, idx - 1, t);
            push_if(q, map, 1 - pos, idx + k, t);
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::string left, right;
    std::vector<std::string> map;
    std::cin >> n >> k >> left >> right;
    map.push_back(left);
    map.push_back(right);

    std::cout << solve(n, k, map);
}