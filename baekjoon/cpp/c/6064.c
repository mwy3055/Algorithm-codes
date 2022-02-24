#include <stdio.h>
#define swap(a,b,i) {i=a;a=b;b=i;}

int cain();
int GCD(int,int); //������ �⵵�� ���ϱ� ���� �ּҰ���� �ʿ�

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		cain();
	}
}

int cain() {
	int M, N, x, y;
	int l, i = 0, j = 0;
	scanf("%d %d %d %d", &M, &N, &x, &y);
	l = M * N / GCD(M, N); //l=�ּҰ����
	while (i <= l / M && j <= l / N) {
		int a = i * M + x, b = j * N + y;
		if (a==b) {
			printf("%d\n", a);
			return 0;
		}
		else if (a < b) i++;
		else if (a > b) j++;
	}
	printf("-1\n");
	return 0;
}

int GCD(int x,int y) {
	int temp;
	while (x) { //��Ŭ���� ȣ����
		if (x < y) swap(x, y, temp);
		x = x % y;
	}
	return y; //�ִ�����
}

//�ð����⵵�� ���̴� �� ����.. �پ��� ����� �����غ���.