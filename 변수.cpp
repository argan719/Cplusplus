/*
// 3������ 1��
#include<iostream>
void sub(int x);
using namespace std;
int main()
{
	int Brown = 31;
	int Sally = 17;
	cout << "main()����, Brown = " << Brown << ", &Brown = " << &Brown << endl;
	cout << "main()����, Sally = " << Sally << ", &Sally = " << &Sally << endl << endl;

	sub(Brown);
	cout << "main()����, Brown = " << Brown << ", &Brown = " << &Brown << endl;
	cout << "\nmain()����, Sally = " << Sally << ", &Sally = ";
	cout << &Sally << endl;
	return 0;
}

void sub(int x)
{
	int Brown = 5;
	cout << "oil()����, Brown = " << Brown << ", &Brown = " << &Brown << endl;
	cout << "oil()����, x = " << x << ", &x = " << &x << endl;
	{
		int Brown = 113;
		cout << "\n��Ͽ���, Brown = " << Brown << ", &Brown = " << &Brown << endl;
		cout << "��Ͽ���, x = " << x << ", &x = " << &x << endl;
	}
	cout << "\n����� ����� ��, Brown = " << Brown;
	cout << ", &Brown = " << &Brown << endl;

}
*/


/*
// 2��
// === main.cpp
#include<iostream>
using namespace std;
double warming = 0.3;
void update(double dt);
void local();

int main()
{
	cout << "���� warming�� " << warming << "���Դϴ�. \n";
	update(0.1);
	cout << "���� warming�� " << warming << " ���Դϴ�. \n";
	local();
	cout << "���� warming�� " << warming << " ���Դϴ�. \n";
	return 0;
}
*/


/*
// 3��
// === main.cpp
#include<iostream>
int tom = 3;
int dick = 30;
static int harry = 300;
void remote_access();
int main()
{
	using namespace std;
	cout << "main()���� �� \n";
	cout << &tom << " = &tom " << &dick << " = &dick " << &harry << " = &harry\n";
	cout << "tom=" << tom << " dick= " << dick << " harry= " << harry << "\n\n";

	remote_access();
	cout << "�Լ� ȣ�� �� main()���� �� \n";
	cout << "tom=" << tom << " dick=" << dick << " harry=" << harry << "\n\n";
	return 0;
}
*/


/*
// 4��
#include<iostream>
const int ArSize = 10;
void strcount(const char *str);
using namespace std;

int main()
{
	char input[ArSize];
	char next;

	cout << "�������� �� ���� �Է��Ͻʽÿ�:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(input);
		cout << "���� ���� �Է��Ͻʽÿ�(�������� �� ���� �Է�):\n";
		cin.get(input, ArSize);
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

void strcount(const char * str)
{
	using namespace std;
	static int total = 0;		// ���� ���� ����
	int count = 0;				// �ڵ� ���� ����

	cout << "\"" << str << "\"���� ";
	while (*str++)
		count++;
	total += count;
	cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
	cout << "���ݱ��� �� " << total << "���� ���ڸ� �Է��ϼ̽��ϴ�.\n";
}
*/




// 5�� - ����ã�� ����



/*
// 13������ - ����Ǯ��
// 1��
// === main.cpp
#include<iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;
int main()
{
	cout << x << endl;
	{
		int x = 4;
		cout << x << endl;
		cout << y << endl;
	}
	other();
	another();
	return 0;
}

void other()
{
	int y = 1;
	cout << "other():" << x << " " << y << endl;
}
*/





/*
// 2�� 
#include<iostream>
#include<cstring>
#include "golf.h"
//golf g[5];	
using namespace std;
void main()
{
	golf g[5];
	golf p;
	for (int i = 0; i < 5; i++)
	{
		cout << "�̸� : ";
		cin.getline(p.fullname, Len);
		cout << "�ڵ�ĸ : ";
		cin >> p.handicap;
		setgolf(g[i], p.fullname, p.handicap);
		cout << endl << endl;
		cin.get();

	}
	strcpy(g[0].fullname, "aaa");
	g[0].handicap = 99;
	
	cout << "�̸�    �ڵ�ĸ\n";
	for (int i = 0; i < 5; i++)
		showgolf(g[i]);


}

void setgolf(golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

void showgolf(const golf &g)
{
	cout << g.fullname << "   " << g.handicap << endl;
}
*/





/*
// 3��
#include<iostream>
#include<string>
using namespace std;
void strcount(string s);
void main()
{
	string str;
	cout << "�������� �� ���� �Է� : ";
	getline(cin, str);
	while (str[0]!=NULL)
	{
		strcount(str);
		cout << "������ �Է�(�������� ���� �Է�) : ";
		getline(cin, str);
	}
}

void strcount(string s)
{
	static int total = 0;	
	int count = 0;		

	cout << "\"" << s << "\"���� ";
	count = s.length(); 
	total += count;
	cout << count << "���� ���ڰ� �ֽ��ϴ�.\n";
	cout << "���ݱ��� �� " << total << "���� �����Է�~~.\n\n";
}
*/





/*
// 4��
#include<iostream>
#include<string>
using namespace std;

struct sell {
	char name[20];
	double sum = 0;
	double aver;
	double max = 0;
	double min;
};

void sum(sell & S, double money);
void print(sell S);
void best(sell S);

void main()
{
	sell A, B;
	double money;
	cout << "�ǸŻ�� A�� �̸��� �Է��ϼ��� : ";
	cin.getline(A.name, 20);
	cout << "�ǸŻ�� " << A.name << "���� �б⺰ �Ǹž��� �Է��ϼ���" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i+1 << "�б� : ";
		cin >> money;
		if (i == 0) A.min = money;
		sum(A, money);
	}
	A.aver = A.sum / 4;
	print(A);

	cout << endl;
	cin.get();
	cout << "\n�ǸŻ�� B�� �̸��� �Է��ϼ��� : ";
	cin.getline(B.name, 20);
	cout << "�ǸŻ�� " << B.name << "���� �б⺰ �Ǹž��� �Է��ϼ���" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "�б� : ";
		cin >> money;
		if (i == 0) B.min = money;
		sum(B, money);
	}
	B.aver = B.sum / 4;
	print(B);

	A.aver < B.aver ? best(B) : best(A);

}

void sum(sell & S, double money)
{
	S.sum += money;
	if (S.max < money) S.max = money;
	else if (money < S.min) S.min = money;
}

void print(sell S)
{
	cout << "\n==> ���" << endl;
	cout << "��հ� : ";
	cout << S.aver;
	cout << "\n�ִ밪 : ";
	cout << S.max;
	cout << "\n�ּҰ� : ";
	cout << S.min;
}

void best(sell S)
{
	cout << "\n\n�ְ��� ������� �ø� ����� " << S.name << " ��� (" << S.aver << ") �Դϴ�." << endl;
}

*/


