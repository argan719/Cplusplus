#include<cstring>
#include "stringbad.h"
using namespace std;

int StringBad::num_strings = 0;  // 클래스 안에서 초기화할 수 없다.

StringBad::StringBad(const char * s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 객체 생성\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 디폴트 객체 생성\n";
	cout << "현재 객체수 => " << StringBad::num_strings;
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" 객체 파괴, ";
	--num_strings;
	cout << "남은 객체 수: " << num_strings << "\n";
	delete[] str;
}

ostream&operator<<(ostream & os, const StringBad & st)
{
	os << st.str;
	return os;
}