#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

vector<vector<int>> connected;
void init()
{
    connected = vector<vector<int>>(10);
    connected[0] = {0, 1, 2};
    connected[1] = {3, 7, 9, 11};
    connected[2] = {4, 10, 14, 15};
    connected[3] = {0, 4, 5, 6, 7};
    connected[4] = {6, 7, 8, 10, 12};
    connected[5] = {0, 2, 14, 15};
    connected[6] = {3, 14, 15};
    connected[7] = {4, 5, 7, 14, 15};
    connected[8] = {1, 2, 3, 4, 5};
    connected[9] = {3, 4, 5, 9, 13};
}
void press_button(int *clock, int button)
{
    for (auto press : connected[button])
    {
        clock[press] = (clock[press] + 1) % 4; //&3;
    }
}
bool is_sorted(int *clock)
{
    for (int i = 0; i < 16; i++)
        if (clock[i] != 3)
            return false;
    return true;
}
int sumof(int *arr, int siz)
{
    int rtn = 0;
    for (int i = 0; i < siz; i++)
        rtn += arr[i];
    return rtn;
}
int solve(int *clock, int *count, int dep)
{
    if (dep == 10)
    {
        if (is_sorted(clock))
            return sumof(count, 10);
        else
            return INF;
    }

    int rtn = INF;
    for (int i = 0; i < 4; i++)
    {
        rtn = min(rtn, solve(clock, count, dep + 1));

        press_button(clock, dep);
        count[dep]++;
    }

    count[dep] = 0;
    return rtn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int c;
    cin >> c;
    while (c--)
    {
        int clock[16];
        for (int i = 0; i < 16; i++)
        {
            cin >> clock[i];
            clock[i] = (clock[i] / 3) - 1;
        }

        int count[10] = {0};
        int ans = solve(clock, count, 0);
        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}