#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int memoi[10][4096];
int n, k, l, m;
vector<int> preSubject, openSubject;

int bitCount(int num)
{
    int bits = 0;
    for (int i = 0; i < 32; i++)
        if (num & (1 << i))
            bits++;
    return bits;
}

int solve(int semester, int taken)
{
    if (k <= bitCount(taken))
        return 0;
    if (semester == m)
        return INF;

    int &ret = memoi[semester][taken];
    if (ret != -1)
        return ret;

    int classes = (openSubject[semester] & ~taken); //열린 과목 중 아직 듣지 않은 과목
    for (int c = 0; c < n; c++)
    {
        if ((classes & (1 << c)) && ((taken & preSubject[c]) != preSubject[c])) //열리지만 수강할 수 없는 과목(선수과목 제한)
            classes &= ~(1 << c);
    }

    ret = INF;
    for (int subset = classes; subset; subset = ((subset - 1) & classes))
    {
        if (l < bitCount(subset))
            continue; //한 학기당 최대 l개의 과목만 수강 가능
        ret = min(ret, 1 + solve(semester + 1, taken | subset));
    }
    ret = min(ret, solve(semester + 1, taken));

    return ret;
}

void init()
{
    for (int i = 0; i < 10; i++)
        memset(memoi[i], -1, sizeof(int) * 4096);
    preSubject.clear();
    openSubject.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        init();

        cin >> n >> k >> m >> l;
        preSubject = vector<int>(n, 0);
        openSubject = vector<int>(m, 0);

        for (int i = 0; i < n; i++)
        {
            int r;
            cin >> r;
            while (r--)
            {
                int ri;
                cin >> ri;
                preSubject[i] |= (1 << ri);
            }
        }

        for (int i = 0; i < m; i++)
        {
            int c;
            cin >> c;
            while (c--)
            {
                int ci;
                cin >> ci;
                openSubject[i] |= (1 << ci);
            }
        }

        int ans = solve(0, 0);
        if (ans == INF)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << ans << '\n';
    }
}