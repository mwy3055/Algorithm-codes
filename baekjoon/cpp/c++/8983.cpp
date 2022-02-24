#include <bits/stdc++.h>
using namespace std;

struct Animal
{
	int x, y;
	Animal(int x = 0, int y = 0) : x(x), y(y) {}
};

int dist(const Animal &a, int g)
{
	return (a.x - g > 0 ? (a.x - g) : (g - a.x)) + a.y;
}
//x 이하인 최초의 위치를 찾아야 함
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, l;
	cin >> m >> n >> l;
	vector<int> gun(m);
	vector<Animal> animal(n);
	for (int &g : gun)
		cin >> g;
	for (Animal &a : animal)
		cin >> a.x >> a.y;

	sort(gun.begin(), gun.end());

	int ans = 0;
	for (Animal &a : animal)
	{
		auto right = lower_bound(gun.begin(), gun.end(), a.x);
		auto left = right - 1;

		//이터레이터가 [begin, end) 범위를 벗어나지 않도록..
		if ((right != gun.begin() && dist(a, *left) <= l) ||
			(right != gun.end() && dist(a, *right) <= l))
		{
			ans++;
		}
		else
		{
			cout << *left << ' ' << *right << ' ' << "Animal " << a.x << ' ' << a.y << " can't be hunted\n";
		}
	}
	cout << ans;
}