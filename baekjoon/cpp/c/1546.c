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
		scor[i] = scor[i] * 100 / max_; //�� �������� scor�� int���� ��� �Ҽ��� �Ʒ� ���� �սǵ� �� �ִ�.
		sum += scor[i];                 //���� ó������ scor�� ������ float�� �Ѵ�.
		i++;
	}
	printf("%.2f", sum / n);
}
