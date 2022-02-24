#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int h, w, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char board[103][103];
set<char> global_keys;

bool islower(char c)
{
    return 'a' <= c && c <= 'z';
}
bool isupper(char c)
{
    return 'A' <= c && c <= 'Z';
}
char tolower(char c)
{
    return c + ('a' - 'A');
}
bool isin(int y, int x)
{
    return 0 <= y && y <= h + 1 && 0 <= x && x <= w + 1;
}
bool haskey(set<char> &keys, char c)
{
    return keys.find(tolower(c)) != keys.end();
}

void init()
{
    for (int i = 0; i < 103; i++)
        for (int j = 0; j < 103; j++)
        {
            board[i][j] = '.';
        }
}
void getinput()
{
    global_keys.clear();
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> board[i][j];

    string s;
    cin >> s;
    if (s != "0")
        global_keys = set<char>(s.begin(), s.end());
}

int bfs(int sy, int sx, set<char> &keys)
{
    bool visit[103][103] = {false};
    queue<pii> q;

    q.push({sy, sx});
    visit[sy][sx] = true;

    int ans = 0;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        int &y = top.first, &x = top.second;
        char &b = board[y][x];
        if (b == '$')
            ans++;
        if (islower(b))
            keys.insert(b);

        for (int i = 0; i < 4; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            char &nb = board[ny][nx];
            if (!isin(ny, nx) || visit[ny][nx])
                continue;

            if (nb == '.' || nb == '$' || islower(nb) || (isupper(nb) && haskey(keys, nb)))
            {
                q.push({ny, nx});
                visit[ny][nx] = true;
            }
        }
    }
    return ans;
}
int solve()
{
    int ans = 0;
    set<char> keys = global_keys, backup;
    do
    {
        backup = keys;
        ans = max(ans, bfs(0, 0, keys));
    } while (backup != keys);

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        init();
        getinput();
        cout << solve() << '\n';
    }
}