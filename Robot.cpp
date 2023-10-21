
#include<iostream>
#include "Robot.h"
using namespace std;

void Robot::err_prn()
{
	cout << "에너지가 부족합니다!" << endl;
	cout << "현재 에너지 : " << energy << endl;
}

void Robot::init(char *np, int e)
{
	name = np;
	energy = e;
}

void Robot::go()
{
	if (energy < 20) err_prn();
	else {
		energy -= 20;
		cout << "전진" << endl;
	}
}

void Robot::back()
{
	if (energy < 10) err_prn();
	else {
		energy -= 10;
		cout << "후진" << endl;
	}
}

void Robot::turn()
{
	if (energy < 30) err_prn();
	else {
		energy -= 30;
		cout << "회전" << endl;
	}
}

void Robot::jump()
{
	if (energy < 50) err_prn();
	else {
		energy -= 50;
		cout << "점프" << endl;
	}
}

void Robot::charge(int c)
{
	energy += c;
	cout << "에너지가 " << c << "만큼 충전되었습니다.\n";
	cout << "현재 에너지는 " << energy << "입니다." << endl;
}