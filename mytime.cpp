
// 연산자의오버로딩(1)
// 1번
// === mytime.cpp

#include<iostream>
#include "mytime.h"
using namespace std;
Time::Time() {
	hours = minutes = 0;
}
Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}
void Time::addMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::addHr(int h) {
	hours += h;
}
void Time::reset(int h, int m) {
	hours = h;
	minutes = m;
}
Time Time::operator+(const Time &t) const {
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
void Time::show() const {
	cout << hours << "시간, " << minutes << "분";
}