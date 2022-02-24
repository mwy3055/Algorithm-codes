#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

float scan(int n);
void mnfst(float max_, int n);

float scor[1000];

int main() {
	int n, i = 0;
	scanf("%d", &n);
	while (i < n) {
		scanf("%f", scor + i);
		i++;
	}
	float max = scan(n);
	mnfst(max, n);
	return 0;
}

float scan(int n) {
	float _max = scor[0];
	int i = 0;
	while (i < n) {
		if (_max < scor[i])
			_max = scor[i];
		i++;
	}
	return _max;
}

void mnfst(float max_, int n) {
	int i = 0;
	float sum = 0;
	while (i < n) {
		scor[i] = scor[i] * 100 / max_; //이 과정에서 scor가 int형일 경우 소수점 아래 값이 손실될 수 있다.
		sum += scor[i];                 //따라서 처음부터 scor의 선언을 float로 한다.
		i++;
	}
	printf("%.2f", sum / n);
}
