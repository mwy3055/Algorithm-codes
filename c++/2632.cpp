#include <bits/stdc++.h>
using namespace std;

//0: A, 1: B
int psize[2], piece[2][1001], subsum[2][1001], rsubsum[2][1001][1001];
vector<int> allsubsum[2];

int getsubsum(int pizza, int s, int e) //[s, e] 구간의 합 반환
{
    if (rsubsum[pizza][s][e])
        return rsubsum[pizza][s][e];

    int rtn;
    if (e <= psize[pizza])
        rtn = subsum[pizza][e] - subsum[pizza][s - 1];
    else
        rtn = getsubsum(pizza, s, psize[pizza]) + getsubsum(pizza, 1, e - psize[pizza]);

    rsubsum[pizza][s][e] = rtn;
    allsubsum[pizza].push_back(rtn);
    return rtn;
}

//피자에서 크기 n을 만들 수 있는 모든 경우의 수를 반환하는 함수 필요
int solve(int pizza, int siz)
{
    int &maxsiz = psize[pizza];
    int tans = 0;
    for (int len = 1; len < maxsiz; len++)
    {
        for (int s = 1; s <= maxsiz; s++)
        {
            if (getsubsum(pizza, s, s + len - 1) == siz)
                tans++;
        }
    }

    if (getsubsum(pizza, 1, maxsiz) == siz)
        tans++;

    return tans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool flag = true;

    int order;
    cin >> order;
    cin >> psize[0] >> psize[1];
    for (int i = 1; i <= psize[0]; i++)
    {
        cin >> piece[0][i];
        if (piece[0][i] != 1)
            flag = false;
        subsum[0][i] = subsum[0][i - 1] + piece[0][i];
    }
    for (int i = 1; i <= psize[1]; i++)
    {
        cin >> piece[1][i];
        if (piece[1][i] != 1)
            flag = false;
        subsum[1][i] = subsum[1][i - 1] + piece[1][i];
    }

    if (flag && psize[0] == psize[1] && psize[0] == order)
    {
        cout << 2 + (order * order * (order - 1));
        return 0;
    }

    int ans = 0;
    //A에서만
    ans += solve(0, order);

    //B에서만
    ans += solve(1, order);

    //A, B 혼합
    sort(allsubsum[0].begin(), allsubsum[0].end());
    sort(allsubsum[1].begin(), allsubsum[1].end());
    for (auto a : allsubsum[0])
    {
        if (order <= a)
            break;
        auto it = equal_range(allsubsum[1].begin(), allsubsum[1].end(), order - a);
        ans += it.second - it.first;
    }

    cout << ans;
}