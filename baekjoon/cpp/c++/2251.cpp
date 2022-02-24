#include <bits/stdc++.h>
using namespace std;

int limit[3];
class State
{
public:
    int w[3];
    State(int wa, int wb, int wc)
    {
        w[0] = wa;
        w[1] = wb;
        w[2] = wc;
    }
    int toint()
    {
        int rtn = 0;
        for (int i = 0; i < 3; i++)
            rtn = rtn * 1000 + w[i];
        return rtn;
    }
    State pour(int from, int to)
    {
        State temp = *this;
        if (w[from] == 0)
            ;
        else if (w[to] + w[from] <= limit[to])
        {
            //모두 담을 수 있음
            temp.w[to] += temp.w[from];
            temp.w[from] = 0;
        }
        else
        {
            //넘침
            temp.w[from] -= (limit[to] - temp.w[to]);
            temp.w[to] = limit[to];
        }
        return temp;
    }
};

void bfs(State first, set<int> &ans)
{
    set<int> s;
    queue<State> q;

    ans.insert(first.w[2]);
    s.insert(first.toint());
    q.push(first);

    int src[][2] = {0, 1, 0, 2, 1, 0, 1, 2, 2, 0, 2, 1};

    while (!q.empty())
    {
        State top = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            State next = top.pour(src[i][0], src[i][1]);
            int mask = next.toint();

            if (s.find(mask) == s.end())
            {
                s.insert(mask);
                q.push(next);
                if (next.w[0] == 0)
                    ans.insert(next.w[2]);
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 3; i++)
        scanf("%d", limit + i);

    set<int> ans;
    bfs(State(0, 0, limit[2]), ans);

    for (auto &i : ans)
        printf("%d ", i);
}