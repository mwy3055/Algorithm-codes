#include <bits/stdc++.h>
using namespace std;

int getkey(char *t)
{
    return t[0] ^ (int)'C';
}
void decode(char *t, int &key)
{
    int idx = 0;
    while (t[idx])
    {
        t[idx++] ^= key;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char t[101];
    cin >> t;

    int key = getkey(t);
    decode(t, key);
    cout << t;
}