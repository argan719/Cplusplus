

/*
// 스택 클래스 구현
// === stack.h
#ifndef STACK_H_
#define STACK_H_

#include<string>
using namespace std;

typedef int Item;

class Stack {
private:
	enum { MAX = 10 };	// 클래스용 상수
	Item items[MAX];  // 스택 항목들을 저장한다
	int top;         // 스택의 꼭대기 항목을 나타낸다
public:
	Stack();
	bool isempty()const;
	bool isfull() const;
	// push()는 스택이 가득 차 있으면 false를, 아니면 true를 리던한다
	bool push(const Item & item);   // 스택에 항목을 추가한다
	// pop()는 스택이 비어 있으면 false를, 아니면 true를 리턴한다
	bool pop(Item &item);   // 꼭대기 항목을 꺼내 item에 넣는다
	Item peek();
};
#endif // !STACK_H_

*/



// - 템플릿 - 
// 5페이지 9번
// Stack 클래스를 '템플릿'으로 설계하여 봅시다.
#ifndef  STACK_A_
#define STACK_A_
const int MAX = 100;
template <class T>
class Stack {
private:
	T stack[MAX];
	int top;
public:
	Stack() { top = 0; }
	bool isfull();
	bool isempty();
	void push(T a);
	void pop(T& po);
};

template<class T> bool Stack<T>::isfull() {
	if (top == MAX) return true;
	else return false;
}
template<class T> bool Stack<T>::isempty() {
	if (top == 0) return true;
	else return false;
}
template<class T> void Stack<T>::push(T a) {
	stack[top++] = a;
}
template<class T> void Stack<T>::pop(T& po) {
	po = stack[--top];
}

#endif // ! STACK_A_




/*
// - 템플릿 - 
// 7페이지 10번
// 포인터들의 스택 작성 
// === stack.h
#ifndef STACKTP1_H_
#define STACKTP1_H_
template<class Type>
class Stack {
private:
	enum {SIZE = 10};
	int stacksize;
	Type * items;
	int top;
public:
	explicit Stack(int ss = SIZE);		// 암시적 변환을 할 수 없음
	Stack(const Stack &st);
	~Stack() { delete[] items; }
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const Type & item);
	bool pop(Type & item);
	Stack & operator=(const Stack & st);
};
template<class Type> 
Stack<Type>::Stack(int ss) : stacksize(ss), top(0) {
	items = new Type[stacksize];
}
template<class Type>
Stack<Type>::Stack(const Stack & st) {
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}
template<class Type>
bool Stack<Type>::push(const Type & item) {
	if (top < stacksize) {
		items[top++] = item;
		return true;
	}
	else
		return false;
}
template<class Type>
bool Stack<Type>::pop(Type & item) {
	if (top > 0) {
		item = items[--top];
		return true;
	}
	else
		return false;
}
template<class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st) {
	if (this == &st)
		return *this;
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

#endif
*/