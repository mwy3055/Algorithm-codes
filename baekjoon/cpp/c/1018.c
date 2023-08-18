#define _CRT_SECURE_NO_WARNINGS

#define wcheck(c) c=='W'?1:0
#define bcheck(c) c=='B'?1:0

#include <stdio.h>

int to_b(int x,int y); //맨 왼쪽 위가 B로 시작되게 만들 때 바꿔야 하는 타일의 수

char board[50][50];

void main() {
	int m, n, min=_CRT_INT_MAX, temp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", board[i]);
	for (int y = 0; y <= n - 8; y++) {
		for (int x = 0; x <= m - 8; x++) {
			temp = to_b(x, y);
			if (64 - temp < temp) temp = 64 - temp; //64-temp는 to_w의 리턴값
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
			case 0: //B로 시작
				if ((i % 2 == 0) && wcheck(board[j + y][i + x])) count++;
				if ((i % 2 == 1) && bcheck(board[j + y][i + x])) count++;
				break;
			case 1: //W로 시작
				if ((i % 2 == 0) && bcheck(board[j + y][i + x])) count++;
				if ((i % 2 == 1) && wcheck(board[j + y][i + x])) count++;
				break;
			}
		}
	}
	return count;
}

//틀린 이유: 맨 왼쪽 위가 (B/W)라고 해도, 맨 왼쪽 위를 (W/B)로 바꾸면 더 작은 값이 나오는 경우가 있기 때문.