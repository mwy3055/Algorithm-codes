#include <iostream>
#include <cstring>
using namespace std;

char s[90];

bool iskind(int len)
{
    if (len <= 1)
        return true;

    for (int i = 0; i < len; i++) //Ž�� ������
    {
        for (int j = 1; j < len; j++) //������ ����
        {
            if (len <= i + j * 2 - 1)
                break;
            int cnt = 0;
            for (int k = 0; k < j; k++) //������ �� �κм��� Ž��
            {
                if (s[i + k] == s[i + j + k])
                    cnt++;
            }
            if (cnt == j)
                return false;
        }
    }
    return true;
}

bool make(int &n, int len) //���� n�� ���� ������ ������ ��. ���� �ε��� len�� ���� ��
{
    if (len == n)
        return true;

    bool flag = false;
    for (int i = 1; i <= 3; i++)
    {
        s[len] = '0' + i;
        if (iskind(len + 1) && make(n, len + 1))
        {
            flag = true;
            break;
        }
        else
        {
            s[len] = 0;
            flag |= false;
        }
    }
    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    make(n, 0);
    cout << s;
}