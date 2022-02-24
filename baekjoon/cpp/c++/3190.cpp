#include <iostream>
#include <queue>
using namespace std;

struct coord
{
    int y, x;
    void operator+=(coord &c)
    {
        this->y += c.y;
        this->x += c.x;
    }
    coord operator+(coord &c)
    {
        return {this->y + c.y, this->x + c.x};
    }
};
typedef pair<int, char> Rotate;

bool isapple[100][100], issnake[100][100];
int dir[100][100];
coord Move[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<Rotate> q;

void getinput(int &n, int &k, int &l)
{
    cin >> n >> k;
    for (int a = 0; a < k; a++)
    {
        int i, j;
        cin >> i >> j;
        isapple[i - 1][j - 1] = true;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        q.push({x, c});
    }
}
bool isin(coord &c, int &n)
{
    return 0 <= c.y && c.y < n && 0 <= c.x && c.x < n;
}
void L(int &didx)
{
    didx = didx ? didx - 1 : 3;
}
void D(int &didx)
{
    didx = (didx + 1) % 4;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, l;
    getinput(n, k, l);

    int didx = 0, time = 0;
    coord head = {0, 0}, tail = {0, 0};
    while (true)
    {
        time++;
        coord th = head + Move[didx];
        if (!isin(th, n) || issnake[th.y][th.x])
            break;
        dir[head.y][head.x] = didx;
        head = th;
        issnake[head.y][head.x] = true;

        if (isapple[head.y][head.x])
            isapple[head.y][head.x] = false;
        else
        {
            issnake[tail.y][tail.x] = false;
            tail += Move[dir[tail.y][tail.x]];
        }
        
        if (q.front().first == time)
        {
            char c = q.front().second;
            q.pop();
            c == 'L' ? L(didx) : D(didx);
        }
    }

    cout << time;
}