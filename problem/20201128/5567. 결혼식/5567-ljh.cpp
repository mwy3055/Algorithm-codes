#include <bits/stdc++.h>

using namespace std;

const int MAX = 500;
int N, M, cnt;
bool check[MAX + 1];
int dist[MAX + 1];
vector<int> board[MAX + 1];
queue<int> q;

void bfs()
//이상함
{
    while (!q.empty())
    {
        int cn = q.front(); //current number
        q.pop();

        for (int i = 0; i < board[cn].size(); i++)
        {
            int nn = board[cn][i];
            if (!check[nn])
            {
                check[nn] = true;
                dist[nn] = dist[cn] + 1;
                q.push(nn);
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x].push_back(y);
        board[y].push_back(x);
    }

    check[1] = true;
    q.push(1);

    bfs();

    for (int i = 0; i < MAX+1; i++)
    {
        if (dist[i] == 1 || dist[i] == 2)
            cnt++;
    }

    cout << cnt << '\n';

    return 0;
}

//뎁스로 풀고 싶엇는데..
