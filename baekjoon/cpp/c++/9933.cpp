#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<string> vec;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		vec.push_back(s);
	}

	int size = vec.size();
	for (int i = 0; i < size; i++)
	{
		string now = vec.at(i);
		int nlen = now.length();
		for (int j = i; j < size; j++) //�ڱ� �ڽ��� �Ӹ������ ���� ����
		{
			string temp = vec.at(j);
			int tlen = temp.length(), k;
			if (nlen != tlen)
				continue;
			for (k = nlen / 2; k >= 0; k--)
			{
				if (now.at(k) != temp.at(nlen - 1 - k))
					break;
			}
			if (k == -1)
			{
				cout << nlen << " " << now.at(nlen / 2);
				return 0;
			}
		}
	}
}