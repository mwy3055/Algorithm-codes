#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct member {
	int nth, age;
	string name;
} mem;

bool compare(const mem& a, const mem& b)
{
	if (a.age == b.age)
		return a.nth < b.nth;
	return a.age <= b.age;
}
ostream& operator<<(ostream& out, const mem& a)
{
	out << a.age << " " << a.name << '\n';
	return out;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	mem* arr = new mem[n];
	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;
		arr[i] = { i,age,name };
	}
	stable_sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)
		cout << arr[i];




	delete[] arr;
}