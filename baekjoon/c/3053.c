#include <stdio.h>

const double pi = 3.1415926535897932384;
//6번째 자리까지 출력: "%6f"->반올림

int main()
{
	double r;
	scanf_s("%lf", &r);
	printf("%6f\n%6f", pi*r*r, 2*r*r); 
}