#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        // 순서: left ~ right
        // 조건: left.size() = right.size() + 1
        std::priority_queue<int> left;
        std::priority_queue<int, std::vector<int>, std::greater<int>> right;
        std::vector<int> answers;
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            std::cin >> num;
            right.push(num);
            while (left.size() < right.size() + 1)
            {
                left.push(right.top());
                right.pop();
            }
            while (left.size() > right.size() + 1)
            {
                right.push(left.top());
                left.pop();
            }
            if (i % 2 == 0)
            {
                answers.push_back(left.top());
            }
        }
        int size = answers.size();
        std::cout << size << '\n';
        for (int i = 0; i < size; i++)
        {
            std::cout << answers[i] << ' ';
            if (i % 10 == 9)
                std::cout << '\n';
        }
        std::cout << '\n';
    }
}