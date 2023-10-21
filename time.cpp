#include<iostream>
#include "time.h"

Time::Time() {}
Time::Time(int h, int m) {
	Time::hours = h;
	Time::minutes = m;
}
std::ostream & operator<<(std::ostream & os, const Time & t) {
	os << t.hours << "½Ã°£ " << t.minutes << "ºÐ";
	return os;
}
Time Time::operator+(const Time &t) const {
	Time tmp;
	tmp.hours = this->hours + t.hours;
	tmp.minutes = this->minutes + t.minutes;
	if (tmp.minutes > 60) {
		int i;
		for (i = 0;; i++) {
			if (tmp.minutes < 60) break;
			tmp.minutes = tmp.minutes - 60;
		}
		tmp.hours += i;
	}
	return tmp;
}
Time Time::operator*(double n) const {
	double time = this->hours * 60;
	time += this->minutes;
	time *= n;
	Time temp;
	temp.hours = time / 60;
	temp.minutes = (int)time % 60;
	return temp;
}
