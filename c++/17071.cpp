#include <bits/stdc++.h>

const int MAX = 500000;
// 동생
int arrive[MAX + 1];
// 수빈이가 해당 위치에 도착하는 최소 시간 (0: 짝수 초, 1: 홀수 초)
int subin[2][MAX + 1];
bool visit[2][MAX + 1];

// type: 현재 턴의 타입
void push(std::queue<int> &q, int type, int loc)
{
    if ((0 <= loc && loc <= MAX) && !visit[type][loc])
    {
        q.push(loc);
        visit[type][loc] = true;
    }
}

int solve(int n, int k)
{
    /**
     * 수빈이가 시간 t초에 위치 x에 도착할 수 있다면, t+2, t+4, ... 초에도 x에 도달할 수 있다.
     * x에 도착하는 최초의 시간(짝수 초, 홀수 초 각각)만 알고 있으면 된다.
     */
    std::memset(subin, 0x3f, sizeof(subin));

    std::queue<int> q;
    int time = 0;

    push(q, 0, n);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto cur = q.front();
            auto ctype = time % 2;
            q.pop();

            subin[ctype][cur] = time;

            push(q, 1 - ctype, cur - 1);
            push(q, 1 - ctype, cur + 1);
            push(q, 1 - ctype, cur * 2);
        }
        time++;
    }

    /**
     * 이제 동생을 움직여 보자.
     */
    int ans = MAX;
    int loc = k;
    time = 0;
    while (loc <= MAX)
    {
        if (subin[time % 2][loc] <= time)
            ans = std::min(ans, time);
        time++;
        loc += time;
    }
    return ans == MAX ? -1 : ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::cout << solve(n, k) << '\n';
}