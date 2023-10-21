
// - ���ø� - 
// 10������ 11��
// === array.h
#ifndef  ARRAYTP_H_
#define ARRAYTP_H_
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T, int n>    // const�� ��.
class ArrayTP {
private:
	T ar[n];
public:
	ArrayTP() { };
	ArrayTP(const T & v);
	T & operator[](int i);      
};
template<class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v) {
	for (int i = 0; i < n; i++)
		ar[i] = v;
}
template <class T, int n>
T & ArrayTP<T, n>::operator[](int i) {
	if (i < 0 || i >= n)
	{
		cerr << "�迭�� ��踦 ����� ����: " << i << "--> �߸��� �ε����Դϴ�.\n";
		exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif // ! ARRAYTP_H_
