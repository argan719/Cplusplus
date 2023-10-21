
// 다형성
// 8페이지 9번
// === Shape.h

#ifndef SHAPE
#define SHAPE
class Shape {
	Shape * next;
protected:
	virtual void draw();
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape *p);
	Shape* getNext() { return next; }
};
#endif