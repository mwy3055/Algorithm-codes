#include <iostream>
#include <vector>
using namespace std;
inline int min(int a, int b) { return a < b ? a : b; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, S;
    cin >> n >> S;
    vector<int> num(n);
    for (int &i : num)
        cin >> i;

    int s = 0, e = 0, sum = num[0], mlen = 0x7fffffff;
    while (s < n)
    {
        if (S <= sum)
        {
            mlen = min(mlen, e - s + 1);
            sum -= num[s++];
        }
        else
        {
            if (e < n - 1)
                sum += num[++e];
            else
                break;
        }
    }
    cout << (mlen == 0x7fffffff ? 0 : mlen);
}