
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<int> words(n);
    // vector<int> cons(m);

    string s;

    //벡터의 원소 접근
    for (auto &w : words)
    {
        cin >> s;

        for (auto &c : s)
        {
            w |= 1 << (c - 'a');
        }
    }

    //자음만 표현한다고 pow(2, 23) -1 이라 해주면 사이사이 비트가 잘못 매핑된다. 
    int bitmask = pow(2, 27) - 1;

    int flag;
    char ch;

    for (int i = 0; i < m; i++)
    {
        cin >> flag >> ch;

        if (flag == 1)
        {
            //forget
            //원소 삭제
            bitmask &= ~(1 << (ch - 'a'));
        }

        else
        {
            //remember
            //원소 추가
            bitmask |= (1 << (ch-'a'));
        }

        int read_cnt = 0;

        for (auto &w : words)
        {
            if ((bitmask & w) == w)
                read_cnt++;
        }

        cout << read_cnt << '\n';
    }

    return 0;
}
