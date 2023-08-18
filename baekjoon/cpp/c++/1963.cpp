#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

bool prime[10000];

void init(int n)
{
    fill(prime, prime + 10000, true);
    prime[1] = false;
    for (int i = 4; i <= n; i += 2)
        prime[i] = false;
    for (int i = 3; i <= (int)sqrt(n); i += 2)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
}

int convert(int &org, int &n, int &k) //org의 오른쪽으로부터 n(0123)번째 수를 k로 바꿈
{
    if (n == 0)
        return org / 10 * 10 + k;
    int target;
    if (n == 1)
        target = 10;
    else if (n == 2)
        target = 100;
    else if (n == 3)
        target = 1000;
    return (org / (target * 10) * (target * 10)) + k * target + (org % target);
}

bool bfs(int &a, int &b)
{
    bool visit[9000] = {false};
    queue<int> q;

    q.push(a);
    visit[a - 1000] = true;
    for (int t = 0; !q.empty(); t++)
    {
        int siz = q.size();
        for (int a = 0; a < siz; a++)
        {
            int &top = q.front();
            q.pop();
            if (top == b)
            {
                cout << t << '\n';
                return true;
            }
            //각 자릿수 바꿔가며 소수이면 큐에 넣어야
            for (int i = 0; i < 4; i++)
            {
                int j = (i == 3 ? 1 : 0);
                for (; j <= 9; j++)
                {
                    int val = convert(top, i, j);
                    if (prime[val] && !visit[val - 1000])
                    {
                        q.push(val);
                        visit[val - 1000] = true;
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init(9999);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (!bfs(a, b))
            cout << "Impossible\n";
    }
}