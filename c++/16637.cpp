#include <bits/stdc++.h>

using ll = long long;

int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        exit(1);
    }
}

ll calculate_exp(std::string &exp, int selected)
{
    int operator_count = exp.length() / 2;
    ll ans = 0;
    char last_op = '+';
    for (int i = 0; i < operator_count; i++)
    {
        auto operator_index = i * 2 + 1;
        int a = exp[operator_index - 1] - '0', b = exp[operator_index + 1] - '0';
        char op = exp[operator_index];
        if (selected & (1 << i))
        {
            auto temp_result = calculate(a, b, op);
            ans = calculate(ans, temp_result, last_op);
        }
        else
        {
            if ((selected & (1 << (i + 1))) == 0)
            {
                ans = calculate(i == 0 ? a : ans, b, op);
            }
            else if (i == 0)
            {
                ans = a;
            }
            last_op = op;
        }
    }
    return ans;
}

void search(ll &ans, std::string &exp, int dep, int selected)
{
    auto operator_count = exp.length() / 2;
    if (dep >= operator_count)
    {
        auto result = calculate_exp(exp, selected);
        ans = std::max(ans, result);
        return;
    }

    // dep번째 연산자를 괄호로 감싼다
    search(ans, exp, dep + 2, selected | (1 << dep));
    // dep번째 연산자를 괄호로 감싸지 않는다
    search(ans, exp, dep + 1, selected);
}

int solve(int n, std::string &exp)
{
    if (n == 1)
        return exp[0] - '0';
    ll ans = -(1LL << 31);
    search(ans, exp, 0, 0);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::string exp;
    std::cin >> n >> exp;
    std::cout << solve(n, exp) << '\n';
}