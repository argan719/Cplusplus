/*
// 3페이지 1번
#include<iostream>
void sub(int x);
using namespace std;
int main()
{
	int Brown = 31;
	int Sally = 17;
	cout << "main()에서, Brown = " << Brown << ", &Brown = " << &Brown << endl;
	cout << "main()에서, Sally = " << Sally << ", &Sally = " << &Sally << endl << endl;

	sub(Brown);
	cout << "main()에서, Brown = " << Brown << ", &Brown = " << &Brown << endl;
	cout << "\nmain()에서, Sally = " << Sally << ", &Sally = ";
	cout << &Sally << endl;
	return 0;
}

void sub(int x)
{
	int Brown = 5;
	cout << "oil()에서, Brown = " << Brown << ", &Brown = " << &Brown << endl;
	cout << "oil()에서, x = " << x << ", &x = " << &x << endl;
	{
		int Brown = 113;
		cout << "\n블록에서, Brown = " << Brown << ", &Brown = " << &Brown << endl;
		cout << "블록에서, x = " << x << ", &x = " << &x << endl;
	}
	cout << "\n블록을 통과한 후, Brown = " << Brown;
	cout << ", &Brown = " << &Brown << endl;

}
*/


/*
// 2번
// === main.cpp
#include<iostream>
using namespace std;
double warming = 0.3;
void update(double dt);
void local();

int main()
{
	cout << "전역 warming은 " << warming << "도입니다. \n";
	update(0.1);
	cout << "전역 warming은 " << warming << " 도입니다. \n";
	local();
	cout << "전역 warming은 " << warming << " 도입니다. \n";
	return 0;
}
*/


/*
// 3번
// === main.cpp
#include<iostream>
int tom = 3;
int dick = 30;
static int harry = 300;
void remote_access();
int main()
{
	using namespace std;
	cout << "main()에서 값 \n";
	cout << &tom << " = &tom " << &dick << " = &dick " << &harry << " = &harry\n";
	cout << "tom=" << tom << " dick= " << dick << " harry= " << harry << "\n\n";

	remote_access();
	cout << "함수 호출 후 main()에서 값 \n";
	cout << "tom=" << tom << " dick=" << dick << " harry=" << harry << "\n\n";
	return 0;
}
*/


/*
// 4번
#include<iostream>
const int ArSize = 10;
void strcount(const char *str);
using namespace std;

int main()
{
	char input[ArSize];
	char next;

	cout << "영문으로 한 행을 입력하십시오:\n";
	cin.get(input, ArSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(input);
		cout << "다음 행을 입력하십시오(끝내려면 빈 행을 입력):\n";
		cin.get(input, ArSize);
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

void strcount(const char * str)
{
	using namespace std;
	static int total = 0;		// 정적 지역 변수
	int count = 0;				// 자동 지역 변수

	cout << "\"" << str << "\"에는 ";
	while (*str++)
		count++;
	total += count;
	cout << count << "개의 문자가 있습니다.\n";
	cout << "지금까지 총 " << total << "개의 문자를 입력하셨습니다.\n";
}
*/




// 5번 - 지뢰찾기 게임



/*
// 13페이지 - 문제풀이
// 1번
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
// 2번 
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
		cout << "이름 : ";
		cin.getline(p.fullname, Len);
		cout << "핸디캡 : ";
		cin >> p.handicap;
		setgolf(g[i], p.fullname, p.handicap);
		cout << endl << endl;
		cin.get();

	}
	strcpy(g[0].fullname, "aaa");
	g[0].handicap = 99;
	
	cout << "이름    핸디캡\n";
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
// 3번
#include<iostream>
#include<string>
using namespace std;
void strcount(string s);
void main()
{
	string str;
	cout << "영문으로 한 행을 입력 : ";
	getline(cin, str);
	while (str[0]!=NULL)
	{
		strcount(str);
		cout << "다음행 입력(끝내려면 빈행 입력) : ";
		getline(cin, str);
	}
}

void strcount(string s)
{
	static int total = 0;	
	int count = 0;		

	cout << "\"" << s << "\"에는 ";
	count = s.length(); 
	total += count;
	cout << count << "개의 문자가 있습니다.\n";
	cout << "지금까지 총 " << total << "개의 문자입력~~.\n\n";
}
*/





/*
// 4번
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
	cout << "판매사원 A의 이름을 입력하세요 : ";
	cin.getline(A.name, 20);
	cout << "판매사원 " << A.name << "님의 분기별 판매액을 입력하세요" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i+1 << "분기 : ";
		cin >> money;
		if (i == 0) A.min = money;
		sum(A, money);
	}
	A.aver = A.sum / 4;
	print(A);

	cout << endl;
	cin.get();
	cout << "\n판매사원 B의 이름을 입력하세요 : ";
	cin.getline(B.name, 20);
	cout << "판매사원 " << B.name << "님의 분기별 판매액을 입력하세요" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "분기 : ";
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
	cout << "\n==> 결과" << endl;
	cout << "평균값 : ";
	cout << S.aver;
	cout << "\n최대값 : ";
	cout << S.max;
	cout << "\n최소값 : ";
	cout << S.min;
}

void best(sell S)
{
	cout << "\n\n최고의 매출액을 올린 사원은 " << S.name << " 사원 (" << S.aver << ") 입니다." << endl;
}

*/


