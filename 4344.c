#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void real(int nth);

int sco[1000];
float overavg[1000] = { 0 };

void main() {
	int roop, i = 1;
	scanf("%d", &roop);
	while (i <= roop) {
		real(i-1);
		i++;
	}
	i = 0;
	while (i < roop) {
		printf("%.3f%%\n", overavg[i]);
		i++;
	}
}

void real(int nth) {
	int n, j = 0;
	float sum = 0, over = 0;
	scanf("%d", &n);
	while (j < n) {
		scanf("%d", sco + j);
		sum += sco[j];
		j++;
	}
	float avg = sum / n;
	j = 0;
	while (j < n) {
		if (sco[j] > avg)
			over++;
		j++;
	}
	overavg[nth] = over / n * 100;
}