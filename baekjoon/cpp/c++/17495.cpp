#include <bits/stdc++.h>

std::map<char, int> notemap = {{'C', 0}, {'D', 2}, {'E', 4}, {'F', 5}, {'G', 7}, {'A', 9}, {'B', 11}};

int getnum(char note, int octave, bool sharp)
{
    return octave * 12 + notemap[note] + sharp;
}

std::vector<int> notes;
int dp[1000][121][121];     // 0: left hand, 1: right hand
bool track[1000][121][121]; // true: left hand, false: right hand

int solve(int l, int r, int idx)
{
    if (idx == notes.size())
        return 0;
    int &ret = dp[idx][l][r];
    if (ret != -1)
        return ret;

    int n = notes[idx];
    int ans0 = std::abs(l - notes[idx]) + solve(notes[idx], r, idx + 1);
    int ans1 = std::abs(r - notes[idx]) + solve(l, notes[idx], idx + 1);

    track[idx][l][r] = ans0 < ans1;
    return ret = std::min(ans0, ans1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int l, r, n;
    std::string sl, sr;
    std::cin >> sl >> sr >> n;
    l = getnum(sl[0], sl[1] - '0', sl.back() == '#');
    r = getnum(sr[0], sr[1] - '0', sr.back() == '#');

    for (int i = 0; i < n; i++)
    {
        std::string note;
        std::cin >> note;
        notes.push_back(getnum(note[0], note[1] - '0', note.back() == '#'));
    }

    memset(dp, -1, sizeof(dp));
    std::cout << solve(l, r, 0) << '\n';
    int left = l, right = r;
    for (int i = 0; i < n; i++)
    {
        if (track[i][left][right])
        {
            std::cout << 1 << ' ';
            left = notes[i];
        }
        else
        {
            std::cout << 2 << ' ';
            right = notes[i];
        }
    }
}