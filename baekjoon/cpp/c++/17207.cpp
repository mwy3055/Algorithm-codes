#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> score;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A[5][5], B[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> A[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> B[i][j];

    int C[5][5] = {0};
    for (int i = 0; i < 5; i++)
        for (int k = 0; k < 5; k++)
            for (int j = 0; j < 5; j++)
                C[i][j] += A[i][k] * B[k][j];

    string name[5] = {"Youngki", "Jinwoo", "Jungwoo", "Junsuk", "Inseo"};
    score s[5];
    for (int i = 0; i < 5; i++)
    {
        s[i].first = 0;
        s[i].second = 4 - i;
        for (int j = 0; j < 5; j++)
            s[i].first += C[i][j];
    }

    sort(s, s + 5);
    cout << name[s[0].second];
}