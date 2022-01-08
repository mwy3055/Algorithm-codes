#include <bits/stdc++.h>

using namespace std;
 
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };
 
//����,����
int w, h; 
int n, m;
 
int board[102][102];

//�κ����� ����(��,��,����)
int robotInfo[101][3];
 
bool crash = false;
 
bool simulation(int id, char cmd, int cmdCnt) {
 
    //��ɳ��� �κ� ��ġ,���� ����
    int tmpi = robotInfo[id][0];
    int tmpj = robotInfo[id][1];
    int tmpDir = robotInfo[id][2];
 
    board[tmpi][tmpj] = 0;
 
    //��� �ݺ� Ƚ����ŭ �ݺ�
    while (cmdCnt--) {
        if (cmd == 'L') {
            if (tmpDir == 0) {
                tmpDir = 3;
            }
            else {
                tmpDir--;
            }
        }
        else if (cmd == 'R') {
            if (tmpDir == 3) {
                tmpDir = 0;
            }
            else {
                tmpDir++;
            }
        }
        else {
            tmpi += di[tmpDir];
            tmpj += dj[tmpDir];
 
            //���� �浹�� ���
            if (tmpi <= 0 || tmpj <= 0 || tmpi > w || tmpj > h) {
                cout << "Robot " << id << " crashes into the wall" << "\n";
                return true;
            }
 
            //�ٸ� �κ��� �浹�� ���
            if (board[tmpi][tmpj] != 0) {
                cout << "Robot " << id << " crashes into robot " << board[tmpi][tmpj] << "\n";

                return true;
            }
        }
    }
 
    //�浹�� �߻����� �ʾ��� ���, �κ���ġ ����
    board[tmpi][tmpj] = id;
 
    robotInfo[id][0] = tmpi;
    robotInfo[id][1] = tmpj;
    robotInfo[id][2] = tmpDir;
 
    return false;
}
 
int main() {
 
    cin >> h >> w >> n >> m;
    for (int i = 1; i <= n; i++) {
        int tmpi, tmpj, tmpDir;
        
        char tmp;
 
        cin >> tmpj >> tmpi >> tmp;
 
        if (tmp == 'N') {
            tmpDir = 0;
        }
        else if (tmp == 'E') {
            tmpDir = 1;
        }
        else if (tmp == 'S') {
            tmpDir = 2;
        }
        else {
            tmpDir = 3;
        }
 
        //�迭index ����
        robotInfo[i][0] = (w + 1) - tmpi;
        robotInfo[i][1] = tmpj;
        robotInfo[i][2] = tmpDir;
 
        board[robotInfo[i][0]][robotInfo[i][1]] = i;
    }
    
    for (int i = 1; i <= m; i++) {
        int id, cmdCnt;
        char cmd;

        cin >> id >> cmd >> cmdCnt;
 
        if (!crash) {
            crash = simulation(id, cmd, cmdCnt);
        }
    }
 
    if (!crash) {
        cout << "OK" << "\n";
    }
 
    return 0;
}