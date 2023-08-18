#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000; //ㅇㅇ typedef보다 이거를 지향하라 하더라

int Jboard[MAX + 1][MAX + 1];
int Iboard[MAX + 1][MAX + 1];
int Oboard[MAX + 1][MAX + 1];
int J_acc_board[MAX + 1][MAX + 1];
int I_acc_board[MAX + 1][MAX + 1];
int O_acc_board[MAX + 1][MAX + 1];

int N, M, K;
string temp;
int Jcount, Icount, Ocount;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    cin >> K;

    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            if (temp[j] == 'J')
                Jboard[i][j] = 1;

            if (temp[j] == 'I')
                Iboard[i][j] = 1;

            if (temp[j] == 'O')
                Oboard[i][j] = 1;
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
        {
            //중복으로 뺀 acc_board[i][j]다시 더해줘야함
            J_acc_board[i + 1][j + 1] = J_acc_board[i + 1][j] + J_acc_board[i][j + 1] - J_acc_board[i][j] + Jboard[i][j];
            I_acc_board[i + 1][j + 1] = I_acc_board[i + 1][j] + I_acc_board[i][j + 1] - I_acc_board[i][j] + Iboard[i][j];
            O_acc_board[i + 1][j + 1] = O_acc_board[i + 1][j] + O_acc_board[i][j + 1] - O_acc_board[i][j] + Oboard[i][j];
        }
    }
        

    // acc_board[i + 1][j + 1] = acc_board[i + 1][j] + acc_board[i][j + 1] - acc_board[i][j] + num;

    for (int i = 0; i < K; i++)
    {
        int fy, fx, ly, lx;
        cin >> fy >> fx >> ly >> lx;
        cout << J_acc_board[ly][lx] - J_acc_board[fy - 1][lx] - J_acc_board[ly][fx - 1] + J_acc_board[fy - 1][fx - 1] << " ";
        cout << O_acc_board[ly][lx] - O_acc_board[fy - 1][lx] - O_acc_board[ly][fx - 1] + O_acc_board[fy - 1][fx - 1] << " ";
        cout << I_acc_board[ly][lx] - I_acc_board[fy - 1][lx] - I_acc_board[ly][fx - 1] + I_acc_board[fy - 1][fx - 1] << '\n';
        
    }

    return 0;
}
