#include <bits/stdc++.h>
using namespace std;

struct sawtooth
{
    int offset;
    sawtooth(int offset = 0) : offset(offset) {}
    char getchar(char c)
    {
        int nth = c - 'A';
        return 'A' + (offset + nth) % 26;
    }
    void roll()
    {
        offset++;
    }
};

string solve(string &crypto)
{
    sawtooth s[8];
    for (int i = 0; i < 8; i++)
        s[i].offset = "CHICKENS"[i] - 'A';

    string ans;
    for (auto &c : crypto)
    {
        char temp = s[0].getchar(c);
        for (int i = 1; i < 8; i++)
        {
            temp = s[i].getchar(temp);
        }
        ans.push_back(temp);
        s[0].roll();
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string crypto;
    cin >> crypto;
    cout << solve(crypto);
}