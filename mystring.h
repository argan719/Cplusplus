#pragma once

// String클래스의 구현을 보고 물음에 대하여 답하여 봅시다.
// String 클래스

#include<iostream>
#include<cstring>
using namespace std;
enum BOOL { FALSE, TRUE };
// 클래스의선언
class String
{
	char *str;
	int len;
public:
	String();
	String(const String &s1);
	String(char ch, int repeat);
	String(char *s1);
	String(unsigned int to);
	~String();
	int GetLength()const;
	BOOL IsEmpty()const;
	void Empty();
	char GetAt(int index)const;
	char operator[ ](int index)const;
	void SetAt(const int index, char ch);
	const String& operator=(const String& s1);
	const String& operator=(char ch);
	const String& operator=(const char *s1);
	const String operator+(const String &s1);
	const String operator+(const char *s1);
	friend String operator+(const char *s1, const String &s2);
	const String& operator+=(const String &s1);
	const String& operator+=(const char *s1);
	BOOL operator==(const String &s1);
	BOOL operator==(const char *s1);
	friend BOOL operator==(const char *s1, const String &s2);
	BOOL operator!=(const String &s1);
	BOOL operator!=(const char *s1);
	friend BOOL operator!=(const char *s1, const String &s2);
	BOOL operator>(const String &s1);
	BOOL operator>(const char *s1);
	friend BOOL operator>(const char *s1, const String &s2);
	BOOL operator>=(const String &s1);
	BOOL operator>=(const char *s1);
	friend BOOL operator>=(const char *s1, const String &s2);
	BOOL operator<(const String &s1);
	BOOL operator<(const char *s1);
	friend BOOL operator<(const char *s1, const String &s2);
	BOOL operator<=(const String &s1);
	BOOL operator<=(const char *s1);
	friend BOOL operator<=(const char *s1, const String &s2);
	int Compare(const char *s1)const;
	int CompareNoCase(const char *s1)const;
	String Mid(int nFirst)const;
	String Mid(int nFirst, int nCount)const;
	String Left(int nCount)const;
	String Right(int nCount)const;
	void MakeUpper();
	void MakeLower();
	void MakeReverse();
	void TrimLeft();
	int Find(char ch)const;
	int Find(char *s1)const;
	int Replace(char *s1, char *s2);
	void Puts();
};

String::String()
{
	str = new char[3];
	strcpy(str, "no"); len = 0;
}
String::String(const String &s1)
{
	len = s1.len;
	str = new char[len + 1];
	strcpy(str, s1.str);
}
String::String(char ch, int repeat = 1)
{
	len = repeat;
	str = new char[len + 1];
	int a;
	for (a = 0; a < repeat; a++)str[a] = ch;
	str[a] = '\0';
}
String::String(char *s1)
{
	int len1 = 0;
	while (s1[len1] != '\0')len1++;
	len = len1;
	str = new char[len + 1];
	for (int a = 0; a <= len; a++)str[a] = s1[a];
}
String::String(unsigned int to)
{
	len = to;
	str = new char[to + 1];
}
String::~String()
{
	len = 0;
	delete[]str;
}
int String::GetLength()const
{
	return(len);
}
BOOL String::IsEmpty()const
{
	if (str[0] == '\0' || len == 0)return(TRUE);
	return(FALSE);
}
void String::Empty()
{
	len = 0;
	delete[]str;
}
char String::GetAt(int index)const
{
	if (index >= 0 && index <= len)return(str[index]);
	return(32);
}
char String::operator[ ](int index)const
{
	if (index >= 0 && index <= len)return(str[index]);
	return(32);
}

void String::SetAt(const int index, char ch)
{
	if (index >= 0 && index < len && ch != '\0')str[index] = ch;
}
const String& String::operator=(const String& s1)
{
	delete[] str;
	len = s1.len;
	str = new char[len + 1];
	for (int a = 0; a <= len; a++)str[a] = s1.str[a];
	return(*this);
}
const String& String::operator=(char ch)
{
	for (int a = 0; a < len; a++)str[a] = ch;
	return(*this);
}
const String& String::operator=(const char *s1)
{
	int len1 = 0;
	delete[] str;
	while (s1[len1] != '\0')len1++;
	len = len1;
	str = new char[len + 1];
	for (int a = 0; a <= len; a++) str[a] = s1[a];
	return(*this);
}
const String String::operator+(const String &s1)
{
	char *imsi;
	imsi = new char[len + s1.len + 1];
	strcpy(imsi, str); strcat(imsi, s1.str);
	String s2(imsi);
	delete[]imsi;
	return(s2);
}
const String String::operator+(const char *s1)
{
	char *imsi;
	imsi = new char[len + strlen(s1) + 1];
	strcpy(imsi, str); strcat(imsi, s1);
	String s2(imsi);
	delete[]imsi;
	return(s2);
}
String operator+(const char *s1, const String &s2)
{
	char *imsi;
	imsi = new char[strlen(s1) + s2.len + 1];
	strcpy(imsi, s1);
	strcat(imsi, s2.str);
	String s3(imsi);
	delete[]imsi;
	return(s3);
}
const String& String::operator+=(const String &s1)
{
	char *imsi;
	int size;
	size = len + s1.len;
	imsi = new char[size + 1];
	strcpy(imsi, str); strcat(imsi, s1.str);
	delete[]str;
	str = new char[size + 1];
	len = size;
	strcpy(str, imsi);
	delete[]imsi;
	return(*this);
}
const String& String::operator+=(const char *s1)
{
	char *imsi;
	int size;
	size = len + strlen(s1);
	imsi = new char[size + 1];
	strcpy(imsi, str); strcat(imsi, s1);
	delete[]str;
	str = new char[size + 1];
	len = size;
	strcpy(str, imsi);
	delete[]imsi;
	return(*this);
}
BOOL String::operator==(const String &s1)
{
	return(strcmp(str, s1.str) == 0 ? TRUE : FALSE);
}
BOOL String:: operator==(const char *s1)
{
	return(strcmp(str, s1) == 0 ? TRUE : FALSE);
}
BOOL operator==(const char *s1, const String &s2)
{
	return(strcmp(s1, s2.str) == 0 ? TRUE : FALSE);
}
BOOL String::operator!=(const String &s1)
{
	return(strcmp(str, s1.str) != 0 ? TRUE : FALSE);
}
BOOL String:: operator!=(const char *s1)
{
	return(strcmp(str, s1) != 0 ? TRUE : FALSE);
}
BOOL operator!=(const char *s1, const String &s2)
{
	return(strcmp(s1, s2.str) != 0 ? TRUE : FALSE);
}
BOOL String::operator>(const String &s1)
{
	return(strcmp(str, s1.str) > 0 ? TRUE : FALSE);
}
BOOL String:: operator>(const char *s1)
{
	return(strcmp(str, s1) > 0 ? TRUE : FALSE);
}
BOOL operator>(const char *s1, const String &s2)
{
	return(strcmp(s1, s2.str) > 0 ? TRUE : FALSE);
}
BOOL String::operator>=(const String &s1)
{
	return(strcmp(str, s1.str) >= 0 ? TRUE : FALSE);
}
BOOL String:: operator>=(const char *s1)
{
	return(strcmp(str, s1) >= 0 ? TRUE : FALSE);
}
BOOL operator>=(const char *s1, const String &s2)
{
	return(strcmp(s1, s2.str) >= 0 ? TRUE : FALSE);
}
BOOL String::operator<(const String &s1)
{
	return(strcmp(str, s1.str) < 0 ? TRUE : FALSE);
}
BOOL String:: operator<(const char *s1)
{
	return(strcmp(str, s1) < 0 ? TRUE : FALSE);
}
BOOL operator<(const char *s1, const String &s2)
{
	return(strcmp(s1, s2.str) < 0 ? TRUE : FALSE);
}
BOOL String::operator<=(const String &s1)
{
	return(strcmp(str, s1.str) <= 0 ? TRUE : FALSE);
}
BOOL String:: operator<=(const char *s1)
{
	return(strcmp(str, s1) <= 0 ? TRUE : FALSE);
}
BOOL operator<=(const char *s1, const String &s2)
{
	return(strcmp(s1, s2.str) <= 0 ? TRUE : FALSE);
}
int String::Compare(const char *s1)const
{
	return(strcmp(str, s1));
}
int String::CompareNoCase(const char *s1)const
{
	return(_stricmp(str, s1));
}
String String::Mid(int nFirst)const
{
	char *imsi; int a = 0;
	imsi = new char[len - nFirst + 1];
	while (str[a + nFirst] != '\0')imsi[a++] = str[a + nFirst];
	imsi[a] = '\0'; String s1(imsi); delete[]imsi; return(s1);
}
String String::Mid(int nFirst, int nCount)const
{
	char *imsi;
	int b = 0;
	imsi = new char[nCount + 1];
	for (int a = 0; a < nCount; a++, b++)
		imsi[b] = str[a + nFirst];
	imsi[b] = '\0'; String s1(imsi); delete[]imsi; return(s1);
}
String String::Left(int nCount)const
{
	char *imsi;
	int a;
	imsi = new char[nCount + 1];
	for (a = 0; a < nCount; a++)
		imsi[a] = str[a];
	imsi[a] = '\0'; String s1(imsi); delete[]imsi; return(s1);
}
String String::Right(int nCount)const
{
	char *imsi;
	int a;
	imsi = new char[nCount + 1];
	for (a = 0; a < nCount; a++)
		imsi[a] = str[len - nCount + a];
	imsi[a] = '\0'; String s1(imsi); delete[]imsi; return(s1);
}
void String::MakeUpper()
{
	for (int a = 0; a < len; a++)
		if (str[a] >= 97 && str[a] <= 122) str[a] -= 32;
}
void String::MakeLower()
{
	for (int a = 0; a < len; a++)
		if (str[a] >= 65 && str[a] <= 90) str[a] += 32;
}
void String::MakeReverse()
{
	char *imsi;
	int a;
	imsi = new char[len + 1];
	for (a = 0; a < len; a++)
		imsi[a] = str[len - a - 1];
	imsi[a] = '\0';
	for (a = 0; a < len; a++)
		str[a] = imsi[a];
	delete[] imsi;
}
void String::TrimLeft()
{
	char *imsi;
	int b = 0;
	imsi = new char[len + 1];
	for (int a = 0; a < len; a++)
		if (!(str[a] == '\n' || str[a] == 32 || str[a] == '\t')) imsi[b++] = str[a];
	imsi[b] = '\0';
	delete[]str;
	len = strlen(imsi); str = new char[len + 1];
	strcpy(str, imsi);
	delete[] imsi;
}
int String::Find(char ch)const
{
	for (int a = 0; a < len; a++)
		if (str[a] == ch) { return(a); }
	return(-1);
}
int String::Find(char *s1)const
{
	int jon = 0;
	for (int a = 0; a < len; a++)
		if (str[a] == s1[0])
		{
			int b = a; jon = 0;
			for (int c = 0; c < (int)strlen(s1); c++, b++)
			{
				if (str[b] != s1[c] || str[b] == '\0') { jon = 0; break; }
				else jon++;
			}
			if (jon == (int)strlen(s1))return(a);
		}
	return(-1);
}
int String::Replace(char *s1, char *s2)
{
	int a;
	int wechi = Find(s1);
	if (wechi == -1) return(-1);
	int size = len + strlen(s2) - strlen(s1);
	char *imsi = new char[size + 1];
	int b = 0;
	for (a = 0; a < wechi; a++) imsi[a] = str[a];
	for (a = wechi; a < wechi + (int)strlen(s2); a++) imsi[a] = s2[b++];
	for (b = wechi + strlen(s1); b <= len; b++) imsi[a++] = str[b];
	delete[]str;
	len = size;
	str = new char[len + 1];
	strcpy(str, imsi); delete[]imsi;
	return(0);
}
void String::Puts() { cout << str << endl; }