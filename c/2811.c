#include <stdio.h>
#include <stdlib.h>

typedef struct period
{
    int s, len;
} period;

int n, maxl, pidx;
char mood[100000], gf[100000];
period p[50000];

int max(int a, int b)
{
    return a < b ? b : a;
}

void getinput()
{
    int s = -1, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%hhd", mood + i);
        if (mood[i] < 0)
        {
            if (s == -1)
                p[pidx].s = s = i;
            t++;
        }
        if (mood[i] >= 0 || i == n - 1)
        {
            if (s != -1)
            {
                p[pidx++].len = t;
                if (maxl < t)
                    maxl = t;
                s = -1, t = 0;
            }
        }
    }
}

int solve()
{
    //�ϴ� 2T�� ����.
    for (int i = 0; i < pidx; i++)
    {
        for (int j = 1; j <= 2 * p[i].len && p[i].s - j >= 0; j++)
        {
            gf[p[i].s - j] = 1;
        }
    }
    int rtn = 0;
    for (int i = 0; i < n; i++)
    {
        if (gf[i])
            rtn++;
    }

    //3T?
    int maxadd = 0;
    for (int i = 0; i < pidx; i++)
    {
        if (p[i].len == maxl)
        {
            int cnt = 0;
            for (int j = p[i].s - 2 * p[i].len - 1; 0 <= j && cnt < p[i].len; j--)
            {
                if (!gf[j])
                    cnt++;
            }
            maxadd = max(maxadd, cnt);
        }
    }
    return rtn + maxadd;
}

int main()
{
    getinput();
    printf("%d", solve());
}