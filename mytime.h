// 연산자의오버로딩(1)
// 1번
// === mytime.h

#ifndef MYTIME_H_
#define MYTIME_H_
class Time {
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	Time operator+(const Time &t) const;
	void show() const;
};
#endif