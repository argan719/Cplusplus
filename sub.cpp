// - 변수 -
/*
// 2번
// === sub.cpp

#include<iostream>
extern double warming;

void update(double dt);
void local();
using namespace std;

void update(double dt)
{
	warming += dt;
	cout << "전역 warming이 " << warming << "도로 갱신되었습니다. \n";
}

void local()
{
	double warming = 0.8;

	cout << "지역 warming은 " << warming << "도입니다. \n";
	cout << "그러나, 전역 warming은 " << ::warming;
	cout << "도입니다. \n";
}
*/

/*
// 3번
#include<iostream> 
extern int tom;
static int dick = 10;
int harry = 200;
using namespace std;
void remote_access()
{
	tom++;
	cout << "sub에서의 값 \n";
	harry++;
	cout << "tom=" << tom << " dick=" << dick << " harry=" << harry << "\n\n";
}
*/


/*
// 13페이지 1번
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