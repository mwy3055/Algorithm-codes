#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int ans = 5000, len = s.length();
    for (int i = len / 2; i < len; i++)
    {
        bool promising = true;
        for (int j = 0; j < len - i; j++)
        {
            if (s[i + j] != s[i - j - 1])
            {
                promising = false;
                break;
            }
        }
        if (promising)
            ans = min(ans, len - (len - i) * 2);
        promising = true;
        for (int j = 0; j < len - i; j++)
        {
            if (s[i + j] != s[i - j])
            {
                promising = false;
                break;
            }
        }
        if (promising)
            ans = min(ans, len - ((len - i) * 2 - 1));
    }
    cout << ans + len;
}