
#include<iostream>
#include "Robot.h"
using namespace std;

void Robot::err_prn()
{
	cout << "�������� �����մϴ�!" << endl;
	cout << "���� ������ : " << energy << endl;
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
		cout << "����" << endl;
	}
}

void Robot::back()
{
	if (energy < 10) err_prn();
	else {
		energy -= 10;
		cout << "����" << endl;
	}
}

void Robot::turn()
{
	if (energy < 30) err_prn();
	else {
		energy -= 30;
		cout << "ȸ��" << endl;
	}
}

void Robot::jump()
{
	if (energy < 50) err_prn();
	else {
		energy -= 50;
		cout << "����" << endl;
	}
}

void Robot::charge(int c)
{
	energy += c;
	cout << "�������� " << c << "��ŭ �����Ǿ����ϴ�.\n";
	cout << "���� �������� " << energy << "�Դϴ�." << endl;
}