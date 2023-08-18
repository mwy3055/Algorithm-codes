#include <iostream>
using namespace std;

bool isAir(char**&, int, int);

int main()
{
	//r:세로줄 s:가로줄
	//dfs?
	int r, s;
	cin >> r >> s;
	char** pic = new char*[r];
	for (int i = 0; i < r; i++)
	{
		pic[i] = new char[s];
		cin >> pic[i];
	}

	//what to do





	for (int i = 0; i < r; i++)
		delete[] pic[i];
	delete[] pic;
}

bool isAir(char**& pic, int r, int s)
{
	for (int i = r - 1; i >= 0; i--)
	{
		for (int j = 0; j < s; j++)
		{
			
		}
	}
}