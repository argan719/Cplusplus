// - ���� -
/*
// 2��
// === sub.cpp

#include<iostream>
extern double warming;

void update(double dt);
void local();
using namespace std;

void update(double dt)
{
	warming += dt;
	cout << "���� warming�� " << warming << "���� ���ŵǾ����ϴ�. \n";
}

void local()
{
	double warming = 0.8;

	cout << "���� warming�� " << warming << "���Դϴ�. \n";
	cout << "�׷���, ���� warming�� " << ::warming;
	cout << "���Դϴ�. \n";
}
*/

/*
// 3��
#include<iostream> 
extern int tom;
static int dick = 10;
int harry = 200;
using namespace std;
void remote_access()
{
	tom++;
	cout << "sub������ �� \n";
	harry++;
	cout << "tom=" << tom << " dick=" << dick << " harry=" << harry << "\n\n";
}
*/


/*
// 13������ 1��
#include<iostream>
using namespace std;
extern int x;
namespace
{
	int y = -4;
}
void another()
{
	cout << "another():" << x << " " << y << endl;
}
*/