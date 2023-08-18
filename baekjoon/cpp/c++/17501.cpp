#include <bits/stdc++.h>

int n, a[100001];
char op[200001];
std::vector<int> graph[200001];

int plus, minus;

void getinput()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = n + 1; i < 2 * n; i++)
    {
        char opr;
        int c1, c2;
        std::cin >> opr >> c1 >> c2;
        op[i] = opr;
        graph[i].push_back(c1);
        graph[i].push_back(c2);
    }
}

bool is_operator(int i)
{
    return i > n;
}

// +이면 true, -이면 false
void search(int cur, bool is_plus)
{
    if (is_operator(cur))
    {
        bool next_op = (is_plus == (op[cur] == '+')); // boolean xor
        search(graph[cur][0], is_plus);
        search(graph[cur][1], next_op);
    }
    else
    {
        if (is_plus)
            plus++;
        else
            minus++;
    }
}

int solve()
{
    search(2 * n - 1, true);
    std::sort(a + 1, a + n + 1, std::greater<int>());

    int ans = 0;
    for (int i = 1; i <= plus; i++)
    {
        ans += a[i];
    }
    for (int i = plus + 1; i <= n; i++)
    {
        ans -= a[i];
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