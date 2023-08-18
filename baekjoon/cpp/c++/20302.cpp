#include <bits/stdc++.h>

std::vector<int> numbers, prime_factors(100001, 0);
std::vector<char> operators;

void getinput()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        if (i % 2 == 0)
        {
            int num;
            std::cin >> num;
            numbers.push_back(std::abs(num));
        }
        else
        {
            char op;
            std::cin >> op;
            operators.push_back(op);
        }
    }
}

void factorize(int num, bool plus)
{
    auto coef = 1;
    if (!plus)
        coef = -1;
    auto root = std::sqrt(num);
    for (int i = 2; i <= root; i++)
    {
        auto count = 0;
        while (num % i == 0)
        {
            count++;
            num /= i;
        }
        prime_factors[i] += coef * count;
    }
    if (num > 1)
    {
        prime_factors[num] += coef;
    }
}

bool solve()
{
    if (numbers[0] == 0)
        return true;
    factorize(numbers[0], true);
    for (int i = 1; i < numbers.size(); i++)
    {
        auto num = numbers[i];
        if (num == 0)
            return true;
        factorize(num, operators[i - 1] == '*');
    }

    for (auto &factor : prime_factors)
    {
        if (factor < 0)
            return false;
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    if (solve())
    {
        std::cout << "mint chocolate" << '\n';
    }
    else
    {
        std::cout << "toothpaste" << '\n';
    }
}