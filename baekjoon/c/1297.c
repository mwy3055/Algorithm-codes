#include <stdio.h>
#include <math.h>

int main()
{
	double l, h, w, k;
	scanf_s("%lf %lf %lf", &l, &h, &w);
	k = l / sqrt(pow(h, 2) + pow(w, 2)); //ºñ·Ê»ó¼ö
	printf("%d %d", (int)(h*k), (int)(w*k));
}