
// 다형성
// 8페이지 9번
// === Line.h

#ifndef LINE
#define LINE
class Line : public Shape {
protected:
	virtual void draw();
};
#endif