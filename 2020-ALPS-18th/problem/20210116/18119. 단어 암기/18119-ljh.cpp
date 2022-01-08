
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

    //������ ���� ����
    for (auto &w : words)
    {
        cin >> s;

        for (auto &c : s)
        {
            w |= 1 << (c - 'a');
        }
    }

    //������ ǥ���Ѵٰ� pow(2, 23) -1 �̶� ���ָ� ���̻��� ��Ʈ�� �߸� ���εȴ�. 
    int bitmask = pow(2, 27) - 1;

    int flag;
    char ch;

    for (int i = 0; i < m; i++)
    {
        cin >> flag >> ch;

        if (flag == 1)
        {
            //forget
            //���� ����
            bitmask &= ~(1 << (ch - 'a'));
        }

        else
        {
            //remember
            //���� �߰�
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
