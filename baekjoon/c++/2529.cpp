#include <bits/stdc++.h>

int big[11], small[11];

int getmax(bool *used, int kth)
{
    int cnt = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (!used[i])
        {
            if (kth == 0)
                return i;
            cnt++;
        }
        if (cnt == kth + 1)
            return i;
    }
    return 0;
}

int getmin(bool *used, int kth)
{
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (!used[i])
        {
            if (kth == 0)
                return i;
            cnt++;
        }
        if (cnt == kth + 1)
            return i;
    }
    return 9;
}

std::string maxv(int k)
{
    std::string s;
    bool used[10] = {false};
    for (int i = 0; i <= k; i++)
    {
        int digit = getmax(used, big[i]);
        s.push_back(digit + '0');
        used[digit] = true;
    }
    return s;
}

std::string minv(int k)
{
    std::string s;
    bool used[10] = {false};
    for (int i = 0; i <= k; i++)
    {
        int digit = getmin(used, small[i]);
        s.push_back(digit + '0');
        used[digit] = true;
    }
    return s;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int k;
    std::cin >> k;
    std::string ops;
    for (int i = 0; i < k; i++)
    {
        char c;
        std::cin >> c;
        ops.push_back(c);
    }

    for (int i = k - 1; i >= 0; i--)
    {
        if (ops[i] == '>')
            small[i] = small[i + 1] + 1;
        else if (ops[i] == '<')
            big[i] = big[i + 1] + 1;
    }

    std::cout << maxv(k) << '\n'
              << minv(k);
}