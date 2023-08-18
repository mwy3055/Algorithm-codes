#define _CRT_SECURE_NO_WARNINGS

#define wcheck(c) c=='W'?1:0
#define bcheck(c) c=='B'?1:0

#include <stdio.h>

int to_b(int x,int y); //�� ���� ���� B�� ���۵ǰ� ���� �� �ٲ�� �ϴ� Ÿ���� ��

char board[50][50];

void main() {
	int m, n, min=_CRT_INT_MAX, temp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);
	for (int y = 0; y <= n - 8; y++) {
		for (int x = 0; x <= m - 8; x++) {
			temp = to_b(x, y);
			if (64 - temp < temp) temp = 64 - temp; //64-temp�� to_w�� ���ϰ�
			if (min > temp) min = temp;
		}
	}
	printf("%d", min);
}

int to_b(int x, int y) { 
	int count = 0;
	for (int j = 0; j <= 7; j++) {
		for (int i = 0; i <= 7; i++) {
			switch (j % 2) {
			case 0: //B�� ����
				if ((i % 2 == 0) && wcheck(board[j + y][i + x])) count++;
				if ((i % 2 == 1) && bcheck(board[j + y][i + x])) count++;
				break;
			case 1: //W�� ����
				if ((i % 2 == 0) && bcheck(board[j + y][i + x])) count++;
				if ((i % 2 == 1) && wcheck(board[j + y][i + x])) count++;
				break;
			}
		}
	}
	return count;
}

//Ʋ�� ����: �� ���� ���� (B/W)��� �ص�, �� ���� ���� (W/B)�� �ٲٸ� �� ���� ���� ������ ��찡 �ֱ� ����.