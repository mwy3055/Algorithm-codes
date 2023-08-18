#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000;

int n, m;
int arr[MAX + 1];

//부모 찾는 연산
int find_parent(int num)
{
    if (arr[num] < 0)
        return num;

    int parent = find_parent(arr[num]);
    arr[num] = parent;

    return parent;
}

void merge(int a_parent, int b_parent)
{
    //집합의 크기가 더 큰 쪽으로 합쳐진다
    if (abs(a_parent) >= abs(b_parent))
    {
        arr[a_parent] += arr[b_parent];
        arr[b_parent] = a_parent;
    }
    else
    {
        arr[b_parent] += arr[a_parent];
        arr[a_parent] = b_parent;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        arr[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int op, a, b;

        cin >> op >> a >> b;

        if (op == 0)
        {
            if (a == b)
                continue;

            int a_parent = find_parent(a);
            int b_parent = find_parent(b);

            if (a_parent == b_parent)
                continue;

            merge(a_parent, b_parent);
        }
        else
        {
            if (a == b)
            {
                cout << "YES\n";
                continue;
            }

            int a_parent = find_parent(a);
            int b_parent = find_parent(b);

            if (a_parent == b_parent)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }

    return 0;
}
