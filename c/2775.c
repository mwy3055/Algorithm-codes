#include <stdio.h>

int apart(); //k층 n호
//int sum(int*, int);

void main() {
	int t;
	scanf("%d", &t);
	while(t--) 
		printf("%d\n", apart());
}

int apart() {
	int k, n, i, j, apart[15][14];
	scanf("%d %d", &k, &n);
	for (i = 0; i < n; i++) apart[0][i] = i + 1;
	for (i = 1; i <= k; i++) {
		apart[i][0] = 1;
		for (j = 1; j < n; j++) 
			apart[i][j] = apart[i][j - 1] + apart[i - 1][j]; //sum(apart[i],j);
	}
	/*for (i = 0; i <= 14; i++) {
		for (j = 0; j < 14; j++) printf("%d ", apart[i][j]);
		printf("\n");
	}*/
	return apart[k][n - 1];
}
//왼쪽 호에 (i-1)층의 1호~(j-1)호까지의 합이 저장되어있음. 따라서 (i-1)층 j호 인원만 더해주면 됨

/*int sum(int* apt, int n) {
	int result = 0, i;
	for (i = 0; i <= n; i++) result += apt[i];
	return result;
}*/