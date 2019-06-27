#include <cstdio>
#include <cstring>
using namespace std;

char star[6561][6562];

void makestar(int y, int x, int len)
{
    static int sy[] = {0, 0, 0, 1, 1, 2, 2, 2}, sx[] = {0, 1, 2, 0, 2, 0, 1, 2};
    if (len == 3)
    {
        for (int i = 0; i < 8; i++)
            star[y + sy[i]][x + sx[i]] = '*';
        return;
    }

    int nlen = len / 3;
    for (int i = 0; i < 8; i++)
    {
        makestar(y + sy[i] * nlen, x + sx[i] * nlen, nlen);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        memset(star[i], ' ', n);

    makestar(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", star[i]);
    }
}