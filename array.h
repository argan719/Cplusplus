
// - 템플릿 - 
// 10페이지 11번
// === array.h
#ifndef  ARRAYTP_H_
#define ARRAYTP_H_
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T, int n>    // const가 됨.
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
		cerr << "배열의 경계를 벗어나는 에러: " << i << "--> 잘못된 인덱스입니다.\n";
		exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif // ! ARRAYTP_H_
