
#include <bits/stdc++.h>

using namespace std;

int board[9][9];
string tmp;

void sdoku(){

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 9; i++){
        cin >> tmp;
        for(int j = 0; j < 9; j++){
            board[i][j] = tmp[j] - '0';
        }
    }

    sdoku();


    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}
