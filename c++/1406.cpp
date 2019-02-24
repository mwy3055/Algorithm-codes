#include <iostream>
#include <string>
using namespace std;

typedef struct lld {
	char c;
	struct lld *prev, *next;
} lld;
typedef struct cursor {
	lld *prev, *next;
} cursor;
lld* head;
void print()
{
	lld* temp = head;
	while(true)
	{
		cout << temp->c;
		if (temp->next == NULL)
			break;
		temp = temp->next;
		delete temp->prev;
	}
	delete temp;
}

void L(cursor& c)
{
	if (c.prev != NULL)
	{
		lld* temp = c.prev;
		c.prev = c.prev->prev;
		c.next = temp;
	}
}
void D(cursor& c)
{
	if (c.next != NULL)
	{
		lld* temp = c.next;
		c.next = c.next->next;
		c.prev = temp;
	}
}
void B(cursor& c)
{
	if (c.prev == NULL)
		return;

	lld* temp = c.prev->prev;
	if (temp != NULL)
		temp->next = c.next;
	else //커서가 맨 처음 문자 오른쪽에 있을 때
		head = head->next;

	if (c.next != NULL)
		c.next->prev = temp;
	delete c.prev;
	c.prev = temp;
}
void P(cursor& c)
{
	char add;
	cin >> add;
	lld* temp = new lld{ add, c.prev, c.next };
	if (c.prev != NULL)
		c.prev->next = temp;
	if (c.next != NULL)
		c.next->prev = temp;
	if (c.prev == NULL)
		head = temp;
	c.prev = temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int len = s.length();
	head = new lld{ s.at(0),NULL,NULL };
	lld* temp = head;
	for (int i = 1; i < len; i++)
	{
		temp->next = new lld{ s.at(i),temp,NULL };
		temp = temp->next;
	}

	cursor c = { temp,NULL }; //문장 맨 끝
	int inst_num;
	cin >> inst_num;
	while (inst_num--)
	{
		char inst;
		cin >> inst;
		switch (inst)
		{
		case 'L':
			L(c);
			break;
		case 'D':
			D(c);
			break;
		case 'B':
			B(c);
			break;
		case 'P':
			P(c);
			break;
		}
	}


	print();
}