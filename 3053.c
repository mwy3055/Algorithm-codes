#include <stdio.h>

const double pi = 3.1415926535897932384;
//6��° �ڸ����� ���: "%6f"->�ݿø�

int main()
{
	double r;
	scanf_s("%lf", &r);
	printf("%6f\n%6f", pi*r*r, 2*r*r); 
}