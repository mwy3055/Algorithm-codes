#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<int> inst;
int dp[100000][5][5]; // 왼발이 k, 오른발이 j에 있는 상태에서 i~끝 발판을 밟을 때 필요한 힘
int cost[5][5] = {{1, 2, 2, 2, 2},
                  {2, 1, 3, 4, 3},
                  {2, 3, 1, 3, 4},
                  {2, 4, 3, 1, 3},
                  {2, 3, 4, 3, 1}};

int solve(int cidx, int lfoot, int rfoot)
{
    // dp
    if (cidx == inst.size())
        return 0;
    int &ret = dp[cidx][lfoot][rfoot];
    if (ret != -1)
        return ret;

    int lcost = cost[lfoot][inst[cidx]], rcost = cost[rfoot][inst[cidx]];
    int lans = INF, rans = INF;
    if (rfoot != inst[cidx])
        lans = solve(cidx + 1, inst[cidx], rfoot) + lcost;
    if (lfoot != inst[cidx])
        rans = solve(cidx + 1, lfoot, inst[cidx]) + rcost;
    return ret = min(lans, rans);
}

void init()
{
    for (int i = 0; i < 100000; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                dp[i][j][k] = -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int n;
    cin >> n;
    while (n)
    {
        inst.push_back(n);
        cin >> n;
    }
    cout << solve(0, 0, 0);
}