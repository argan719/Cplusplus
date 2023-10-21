/*
#include<iostream>
using namespace std;
#include "Circle.h"
Circle::Circle() {
	radius = 1;
	cout << "반지름" << radius;
	cout << "원생성 " << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius;
	cout << "원생성 " << endl;
}
double Circle::getarea() {
	return 3.14 * radius * radius;
}
*/



// 다형성
// 8페이지 9번
// === Circle.cpp
#include<iostream>
#include "Shape.h"
#include "Circle.h"
using namespace std;
void Circle::draw() {
	cout << "Circle" << endl;
}