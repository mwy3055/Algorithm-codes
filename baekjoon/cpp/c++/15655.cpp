#include <iostream>
#include <algorithm>
using namespace std;

bool cont[8];
int num[8];

void dfs(int dep, int elm_num, int &n, int &m)
{
    if (elm_num == m)
    {
        for (int i = 0; i < n; i++)
            if (cont[i])
                cout << num[i] << " ";
        cout << '\n';
        return;
    }
    if (n - dep < m - elm_num) //가지치기
        return;

    cont[dep] = true;
    dfs(dep + 1, elm_num + 1, n, m);
    cont[dep] = false;
    dfs(dep + 1, elm_num, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    dfs(0, 0, n, m);
}