
// 23������ 21��
// �����̴� �׸����� ����� ���ô�.

// === Shapes.h

#pragma once
#include "Canvas.h"

class Point {
public:
	int x, y; // ���� ��ǥ
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
	void move(int dx, int dy) { x += dx; y += dy; }
};
class Shape {
protected:
	Point p;  // ������ ��ġ
public:
	Shape(int x = 0, int y = 0) : p(x, y) {}
	void draw(Canvas& canvas, string color = "��") {
		canvas.draw(p.x, p.y, color);
	}
	void move(int dx, int dy) { p.move(dx, dy); }
};
// ���а� ���õ� Ŭ������ -------------------------------------------------
inline int Abs(int x) { return x > 0 ? x : -x; }
inline int Max(int x, int y) { return x > y ? x : y; }
inline int Round(double x) { return (int)(x + 0.5); }
class Line : public Shape {
	Point q;		// ������ �ٸ� �� ���� (���� ������ p��)
public:
	Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0)
		: Shape(x1, y1), q(x2, y2) {}
	void draw(Canvas& canvas, string color = "��") {
		int len = Max(Abs(q.x - p.x), Abs(q.y - p.y));
		double x = p.x, y = p.y;
		double dx = (q.x - p.x) / (double)len, dy = (q.y - p.y) / (double)len;
		for (int i = 0; i <= len; i++) {
			canvas.draw(Round(x), Round(y), color);
			x += dx;
			y += dy;
		}
	}
	void move(int dx, int dy) { p.move(dx, dy); q.move(dx, dy); }
};

class HLine : public Line {
public:
	HLine(int x = 0, int y = 0, int len = 0) : Line(x, y, x + len, y) {}
};
class VLine : public Line {
public:
	VLine(int x = 0, int y = 0, int len = 0) : Line(x, y, x, y + len) {}
};


// �簢���� ���õ� Ŭ������ --------------------------------------------------
class Rect : public Shape {
	int w, h;		// �簢���� ���ο� ���� ���� (�������� p��)
public:
	Rect(int x = 0, int y = 0, int ww = 0, int hh = 0) : Shape(x, y), w(ww), h(hh) {}
	void draw(Canvas & canvas, string color = "��") {
		for (int i = p.x; i <= p.x + w; i++) {
			canvas.draw(i, p.y, color);		// �簢���� ����
			canvas.draw(i, p.y + h, color);  // �簢���� �Ʒ���
		}
		for (int i = p.y; i <= p.y; i++) {
			canvas.draw(p.x, i, color);   // �簢���� �º�
			canvas.draw(p.x + w, i, color);  // �簢���� �캯
		}
	}
};
class Square : public Rect {
public:
	Square(int x = 0, int y = 0, int w = 0) : Rect(x, y, w, w) {}
};

// �� Ŭ����
class Circle : public Shape {
	int r;   // ���� ������ (�߽��� p�� ���)
public:
	Circle(int x = 0, int y = 0, int rr = 0)
		: Shape(x, y), r(rr) {}
	void draw(Canvas &canvas, string color = "��") {
		Line(p.x, p.y, p.x, p.y + r).draw(canvas, color);
		Line(p.x, p.y, p.x, p.y - r).draw(canvas, color);
		Line(p.x, p.y, p.x + r, p.y).draw(canvas, color);
		Line(p.x, p.y, p.x - r, p.y).draw(canvas, color);
	}
};