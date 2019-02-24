#include <iostream>
#include <string>
using namespace std;
typedef struct coord {
	int y, x;
} coord;

enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

char map[25][25];
int r, c, _left;
direction dir;
coord m, z, to_fill;

inline bool isin(int i, int j)
{
	return (0 <= i && i < r) && (0 <= j && j < c);
}

void getInput()
{
	string rmv = ".MZ";
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = temp.at(j);
			if (rmv.find(map[i][j]) == rmv.npos)
				_left++;
			if (map[i][j] == 'M')
				m = { i,j };
			else if (map[i][j] == 'Z')
				z = { i,j };
		}
	}
}

bool is_correct(coord now)
{
	int left = _left;










	return ((left == 0) ? (true) : (false));
}
bool start()
{
	if (isin(m.y + 1, m.x) && map[m.y + 1][m.x] == '|')
		dir = UP;
	else if (isin(m.y - 1, m.x) && map[m.y - 1][m.x] == '|')
		dir = DOWN;
	else if (isin(m.y, m.x + 1) && map[m.y][m.x + 1] == '-')
		dir = RIGHT;
	else if (isin(m.y, m.x - 1) && map[m.y][m.x - 1] == '-')
		dir = LEFT;
	else
		return false;
	return true;
}
void search()
{
	int src[4][2] = { {1,0},{-1,0},{-1,0},{1,0} };
	coord now = m;
	
	if (!start())
	{
		//주변 4칸에 블럭을 넣고 테스트해봐야함
		for (int i = 0; i < 4; i++)
		{
			int sy = m.y + src[i][0], sx = m.x + src[i][1];
			if (isin(sy, sx))
			{
				
			}
		}
	}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	getInput();
	search();

	cout << to_fill.y << " " << to_fill.x << " " << dir;
}