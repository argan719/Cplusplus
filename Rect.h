
// 다형성
// 8페이지 9번
// === Rect.h

#ifndef RECT
#define RECT
class Rect : public Shape {
protected:
	virtual void draw();
};
#endif