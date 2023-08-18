#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define num first
#define ch second
typedef pair<int, char> card;
card c[5];
int MAX;
bool first()
{
	for (int i = 0; i < 4; i++)
		if (!(c[i].num + 1 == c[i + 1].num&&c[i].ch == c[i + 1].ch))
			return false;
	return true;
}
bool second()
{
	return (c[0].num == c[1].num&&c[1].num == c[2].num&&c[2].num == c[3].num) || 
		(c[1].num == c[2].num&&c[2].num == c[3].num&&c[3].num == c[4].num);
}
bool third(int& a,int& b) //a가 2개, b가 3개
{
	if (c[0].num == c[1].num && (c[2].num == c[3].num&&c[3].num == c[4].num))
	{
		a = c[0].num;
		b = c[2].num;
		return true;
	}
	if ((c[0].num == c[1].num&&c[1].num == c[2].num) && c[3].num == c[4].num)
	{
		a = c[3].num;
		b = c[0].num;
		return true;
	}
	return false;
}
bool fourth()
{
	for (int i = 0; i < 4; i++)
		if (c[i].ch != c[i + 1].ch)
			return false;
	return true;
}
bool fifth()
{
	for (int i = 0; i < 4; i++)
		if (c[i].num + 1 != c[i + 1].num)
			return false;
	return true;
}
bool sixth(int& a)
{
	for (int i = 0; i < 2; i++)
	{
		if (c[i].num == c[i + 1].num&&c[i].num == c[i + 2].num)
		{
			a = c[i].num;
			return true;
		}
	}
	return false;
}
bool sevth(int& large, int& small)
{
	if (c[0].num==c[1].num&&c[2].num==c[3].num)
	{
		large = c[3].num;
		small = c[1].num;
		return true;
	}
	else if (c[0].num == c[1].num&&c[3].num == c[4].num)
	{
		large = c[3].num;
		small = c[1].num;
		return true;
	}
	else if (c[1].num == c[2].num&&c[3].num == c[4].num)
	{
		large = c[3].num;
		small = c[1].num;
	}
	return false;
}
bool eighth(int& a)
{
	for (int i = 0; i < 4; i++)
	{
		if (c[i].num == c[i + 1].num)
		{
			a = c[i].num;
			return true;
		}
	}
	return false;
}


int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> c[i].ch >> c[i].num;
		if (MAX < c[i].num)
			MAX = c[i].num;
	}
	sort(c, c + 5);

	vector<int> score;
	int a, b;
	if (first())
	{
		score.push_back(MAX + 900);
	}
	if (second())
	{
		score.push_back(c[2].num + 800);
	}
	if (third(a,b))
	{
		score.push_back(b * 10 + a + 700);
	}
	if (fourth())
	{
		score.push_back(MAX + 600);
	}
	if (fifth())
	{
		score.push_back(MAX + 500);
	}
	if (sixth(a))
	{
		score.push_back(a+ 400);
	}
	if (sevth(a, b))
	{
		score.push_back(a * 10 + b + 300);
	}
	if (eighth(a))
	{
		score.push_back(a + 200);
	}
	score.push_back(MAX + 100);



	sort(score.begin(), score.end());
	cout << score[score.size() - 1];
}