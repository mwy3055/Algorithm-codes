#include <iostream>
#include <cmath>

using namespace std;
int num;
int cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 255;

	while (tc--)
	{
		cnt = 0;
		cin >> num;
		if (num == 0)
			break;

		//c++에서 제곱수 만드는 법 
		int len = (int)sqrt(num);

		for (int i = 1; i <= len; i++)
		{
			if (i * i == num)
			{
				cnt++;
				break;
			}
			for (int j = i; j <= len; j++)
			{
				if (i * i + j * j == num)
				{
					cnt++;
					break;
				}
				else if (i * i + j * j > num)
					break;

				for (int k = j; k <= len; k++)
				{
					if (i * i + j * j + k * k == num)
					{
						cnt++;
						break;
					}
					else if (i * i + j * j + k * k > num)
						break;

					for (int l = k; l <= len; l++)
					{
						if (i * i + j * j + k * k + l * l == num)
						{
							cnt++;
							break;
						}
						else if (i * i + j * j + k * k + l * l > num)
							break;
					}
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}