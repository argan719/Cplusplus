/*
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getarea();
};

*/



/*
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getarea();
};

#endif

*/

 


// ������
// 8������ 9��
// === Circle.h

#ifndef CIRCLE
#define CIRCLE
class Circle : public Shape {
protected: 
	virtual void draw();
};
#endif