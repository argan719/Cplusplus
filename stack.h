

/*
// ���� Ŭ���� ����
// === stack.h
#ifndef STACK_H_
#define STACK_H_

#include<string>
using namespace std;

typedef int Item;

class Stack {
private:
	enum { MAX = 10 };	// Ŭ������ ���
	Item items[MAX];  // ���� �׸���� �����Ѵ�
	int top;         // ������ ����� �׸��� ��Ÿ����
public:
	Stack();
	bool isempty()const;
	bool isfull() const;
	// push()�� ������ ���� �� ������ false��, �ƴϸ� true�� �����Ѵ�
	bool push(const Item & item);   // ���ÿ� �׸��� �߰��Ѵ�
	// pop()�� ������ ��� ������ false��, �ƴϸ� true�� �����Ѵ�
	bool pop(Item &item);   // ����� �׸��� ���� item�� �ִ´�
	Item peek();
};
#endif // !STACK_H_

*/



// - ���ø� - 
// 5������ 9��
// Stack Ŭ������ '���ø�'���� �����Ͽ� ���ô�.
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
// - ���ø� - 
// 7������ 10��
// �����͵��� ���� �ۼ� 
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
	explicit Stack(int ss = SIZE);		// �Ͻ��� ��ȯ�� �� �� ����
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