#include <bits/stdc++.h>

using ll = long long;
int n, k;
std::vector<int> numbers;

void getinput()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
}

ll solve()
{
    ll ans = 0;
    int half = (k + 1) / 2;

    if (k == 1)
    {
        for (auto &num : numbers)
            ans += num;
        return ans;
    }

    std::multiset<int, std::greater<int>> left;
    std::multiset<int> right;

    for (int i = 0; i < k - 1; i++)
    {
        left.insert(numbers[i]);
    }

    for (int i = k - 1; i < n; i++)
    {
        // add number[i]
        right.insert(numbers[i]);
        while (left.size() > half)
        {
            auto val = *(left.begin());
            right.insert(val);
            left.erase(left.begin());
        }
        while (right.size() > k - half)
        {
            auto val = *(right.begin());
            left.insert(val);
            right.erase(right.begin());
        }
        if (*(left.begin()) > *(right.begin()))
        {
            auto lval = *(left.begin());
            auto rval = *(right.begin());
            left.erase(left.begin());
            right.erase(right.begin());
            left.insert(rval);
            right.insert(lval);
        }
        // calculate median
        auto median = *(left.begin());
        ans += median;
        // erase number[i-k+1]
        auto erase = numbers[i - k + 1];
        auto it = left.find(erase);
        if (it != left.end())
        {
            left.erase(it);
        }
        else
        {
            auto it2 = right.find(erase);
            right.erase(it2);
        }
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