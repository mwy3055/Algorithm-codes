#include <iostream>
#include <cstring>
using namespace std;

char s[90];

bool iskind(int len)
{
    if (len <= 1)
        return true;

    for (int i = 0; i < len; i++) //탐색 시작점
    {
        for (int j = 1; j < len; j++) //임의의 길이
        {
            if (len <= i + j * 2 - 1)
                break;
            int cnt = 0;
            for (int k = 0; k < j; k++) //인접한 두 부분수열 탐색
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

bool make(int &n, int len) //길이 n의 좋은 수열을 만들어야 함. 현재 인덱스 len번 보는 중
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