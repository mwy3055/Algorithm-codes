#include <bits/stdc++.h>
using namespace std;

int ans, horse[4];
vector<int> dice(10);
map<int, vector<int>> togo; // togo[k][d] : at position k and dice number d+1
map<int, int> score;        // score[k]: score of position k
void init()
{
    togo[0] = {1, 2, 3, 4, 5};
    togo[1] = {2, 3, 4, 5, 6};
    togo[2] = {3, 4, 5, 6, 7};
    togo[3] = {4, 5, 6, 7, 8};
    togo[4] = {5, 6, 7, 8, 9};
    togo[5] = {21, 22, 23, 24, 25};
    togo[6] = {7, 8, 9, 10, 11};
    togo[7] = {8, 9, 10, 11, 12};
    togo[8] = {9, 10, 11, 12, 13};
    togo[9] = {10, 11, 12, 13, 14};
    togo[10] = {27, 28, 24, 25, 26};
    togo[11] = {12, 13, 14, 15, 16};
    togo[12] = {13, 14, 15, 16, 17};
    togo[13] = {14, 15, 16, 17, 18};
    togo[14] = {15, 16, 17, 18, 19};
    togo[15] = {29, 30, 31, 24, 25};
    togo[16] = {17, 18, 19, 20, 32};
    togo[17] = {18, 19, 20, 32, 32};
    togo[18] = {19, 20, 32, 32, 32};
    togo[19] = {20, 32, 32, 32, 32};
    togo[20] = {32, 32, 32, 32, 32};
    togo[21] = {22, 23, 24, 25, 26};
    togo[22] = {23, 24, 25, 26, 20};
    togo[23] = {24, 25, 26, 20, 32};
    togo[24] = {25, 26, 20, 32, 32};
    togo[25] = {26, 20, 32, 32, 32};
    togo[26] = {20, 32, 32, 32, 32};
    togo[27] = {28, 24, 25, 26, 20};
    togo[28] = {24, 25, 26, 20, 32};
    togo[29] = {30, 31, 24, 25, 26};
    togo[30] = {31, 24, 25, 26, 20};
    togo[31] = {24, 25, 26, 20, 32};
    togo[32] = {32, 32, 32, 32, 32};

    for (int i = 0; i <= 20; i++)
        score[i] = i * 2;
    score[21] = 13;
    score[22] = 16;
    score[23] = 19;
    score[24] = 25;
    score[25] = 30;
    score[26] = 35;
    score[27] = 22;
    score[28] = 24;
    score[29] = 28;
    score[30] = 27;
    score[31] = 26;
    score[32] = 0;
}
bool check(int &i, int &next)
{
    if (next == 32)
        return true;
    for (int j = 0; j < 4; j++)
    {
        if (j == i)
            continue;
        if (horse[j] == next)
            return false;
    }
    return true;
}
void solve(int dep, int sum)
{
    if (dep == 10)
    {
        ans = max(ans, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int next = togo[horse[i]][dice[dep]];
        if (horse[i] != 32 && check(i, next))
        {
            int backup = horse[i];
            horse[i] = next;
            solve(dep + 1, sum + score[next]);
            horse[i] = backup;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    for (auto &d : dice)
    {
        cin >> d;
        d--;
    }

    solve(0, 0);
    cout << ans;
}