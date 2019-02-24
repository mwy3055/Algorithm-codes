#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char str[256];
	cin.getline(str, 256);

	int i = 0;
	if (strlen(str) < 3)
	{
		cout << "none";
		return 0;
	}

	int happy = 0, sad = 0;
	while (str[i + 2])
	{
		if (str[i] == ':'&&str[i + 1] == '-')
		{
			if (str[i + 2] == ')')
				happy++;
			else if (str[i + 2] == '(')
				sad++;
		}
		i++;
	}
	if (happy == 0 && sad == 0)
		cout << "none";
	else if (happy == sad)
		cout << "unsure";
	else if (happy > sad)
		cout << "happy";
	else
		cout << "sad";
}