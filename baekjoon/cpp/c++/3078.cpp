#include <bits/stdc++.h>

int n, k, lens[300030];
int count[21];

void getinput()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name;
        lens[i] = name.length();
    }
}

long long solve()
{
    long long ans = 0;
    for (int i = 1; i <= k; i++)
        count[lens[i]]++;

    // [cur+1, right] 구간을 탐색
    int cur = 0, right = k;
    while (cur < n)
    {
        // calculate
        ans += count[lens[cur]];
        // slide
        if (++right < n)
        {
            count[lens[right]]++;
        }
        count[lens[++cur]]--;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}