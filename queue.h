
// - 동적메모리와 클래스 - 
// 9페이지 12번 
// ATM기계 시뮬레이션

// === queue.h
#ifndef QUEUE_H_
#define QUEUE_H_
class Customer
{
private:
	long arrive;	// 고객이 큐에 도착한 시간
	int processtime;	// 고객의 거래를 처리하는 시간
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
typedef Customer Item;
class Queue
{
private:
	struct Node {
		Item item;
		struct Node *next;
	};
	enum { Q_SIZE = 10 };
	Node *front;
	Node *rear;
	int items;
	const int qsize;
	Queue(const Queue & q) : qsize(0) {}
	Queue & operator = (const Queue & q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item &item);
	bool dequeue(Item &item);
};
#endif