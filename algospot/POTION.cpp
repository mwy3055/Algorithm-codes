#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    //constraint: a <= b
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}
int ceil(int a, int b) // a/b보다 크거나 같은 가장 작은 정수 반환
{
    return (a + b - 1) / b;
}

vector<int> solve(int n, vector<int> &recipe, vector<int> &put)
{
    int b = recipe[0];
    for (int i = 1; i < n; i++)
        b = GCD(b, recipe[i]);

    int a = b;
    for (int i = 0; i < n; i++)
        a = max(a, ceil(put[i] * b, recipe[i]));

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = recipe[i] * a / b - put[i];
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        vector<int> recipe(n), put(n);
        for (auto &r : recipe)
            cin >> r;
        for (auto &p : put)
            cin >> p;

        for (auto &s : solve(n, recipe, put))
            cout << s << ' ';
        cout << '\n';
    }
}