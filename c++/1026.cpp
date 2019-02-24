#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, desc);

	int result = 0;
	for (int i = 0; i < n; i++)
		result += a[i] * b[i];
	cout << result;



	delete[] a;
	delete[] b;
}