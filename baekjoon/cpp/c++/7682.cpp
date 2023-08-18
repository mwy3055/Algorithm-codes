#include <bits/stdc++.h>
using namespace std;

char board[3][3];
bool check()
{
    int countx = 0, counto = 0;
    int bingox = 0, bingoo = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O')
            bingoo++;
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'X')
            bingox++;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'X')
                countx++;
            else if (board[i][j] == 'O')
                counto++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'O')
            bingoo++;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'X')
            bingox++;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O')
        bingoo++;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X')
        bingox++;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'O')
        bingoo++;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'X')
        bingox++;

    if (countx == 5 && counto == 4 && bingoo == 0)
        return true;
    if (bingox == 1 && bingoo == 0 && countx == counto + 1)
        return true;
    if (bingox == 0 && bingoo == 1 && countx == counto)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        string input;
        cin >> input;
        if (input == "end")
            break;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = input[i * 3 + j];
        if (check())
            cout << "valid" << '\n';
        else
            cout << "invalid" << '\n';
    }
}