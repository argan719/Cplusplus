/*
#include<iostream>
using namespace std;
#include "Circle.h"
Circle::Circle() {
	radius = 1;
	cout << "������" << radius;
	cout << "������ " << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "������ " << radius;
	cout << "������ " << endl;
}
double Circle::getarea() {
	return 3.14 * radius * radius;
}
*/



// ������
// 8������ 9��
// === Circle.cpp
#include<iostream>
#include "Shape.h"
#include "Circle.h"
using namespace std;
void Circle::draw() {
	cout << "Circle" << endl;
}