
// -�������� �����ε�(1)-
// 10��
// === stringbad.h

#include<iostream>
using namespace std;
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad {
private:
	char *str;
	int len;
	static int num_strings;
public:
	StringBad(const char *s);
	StringBad();
	~StringBad();

	friend ostream & operator << (ostream & os, const StringBad & st);
};
#endif