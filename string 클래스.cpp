
/*
// 1��
// ��Ʈ�� Ŭ������ �����ڸ� ���� ���ô�.
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string one("Lottery Winner!");		// ctor #1
	cout << one << endl;              // �����ε� <<
	string two(20, '$');				// ctor #2
	cout << two << endl;
	string three(one);					// ctor #3
	cout << three << endl;
	one += "Oops!";					 // �����ε� +=
	cout << one << endl;
	two = "Sorry! That was ";
	three[0] = 'P';
	string four;						// ctor #4
	four = two + three;              // �����ε� +, =
	cout << four << endl;

	char alls[] = "All's well that ends well";
	string five(alls, 20);				// ctor #5
	cout << five << "!\n";
	string six(alls + 6, alls + 10);    // ctor #6
	cout << six << ", ";
	string seven(&five[6], &five[10]);  // ctor #6 again
	cout << seven << "...\n";
	string eight(four, 7, 16);           // ctor #7
	cout << eight << " in motion!" << endl;
	return 0;
}
*/

/*
// 2��
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
int main()
{
	using namespace std;
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false) {
		cerr << "������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, '\n');
	while (fin) {
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, '\n');
	}
	cout << "���α׷��� �����մϴ�.\n";
	fin.close();
	return 0;
}
*/

/*
// 3��
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	string address("������ �д籸 ���̵�");
	string copyAddress(address);

	char text[] = { 'L','o','v','e',' ', 'C','+','+','\0' };
	string title(text);

	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
}
*/
/*
// 4��
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string names[5];

	for (int i = 0; i < 5; i++) {
		cout << "�̸�>> ";
		getline(cin, names[i], '\n');
	}
	string latter = names[0];
	for (int i = 1; i < 5; i++) {
		if (latter < names[i]) {
			latter = names[i];
		}
	}
	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << latter << endl;
}
*/

/*
// 5��
// 1)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "java", b = "C++";
	cout << a << endl;
	a = b;
	cout << a << endl;
}
*/
/*
// 6��
// 2)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string name = "kitae";
	string alias = "kito";
	int res = name.compare(alias);
	if (res == 0) cout << "�ι��ڿ��� ����" << endl;
	else if (res < 0) cout << name << "<" << alias << endl;
	else cout << alias << "<" << name << endl;
}
*/
/*
// 3)
#include<iostream>
#include<string>
using namespace std;
int main() {
	string a("I");
	a.append(" love");
	cout << a << endl;
}
*/
/*
// 4)
#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string a("I love C++");
	a.insert(2, "really ");
	cout << a << endl;
	a.insert(2, "really", 3);
	cout << a << endl;
}
*/
/*
// 5)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("I love C++");
	a.replace(2, 11, "study");
	cout << a << endl;
}
*/
/*
// 6)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("I study C++");
	int length = a.length();
	int size = a.size();
	int capacity = a.capacity();
	cout << length << "  " << size << "  " << capacity << endl;
}
*/
/*
// 7) 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("I study C++");
	a.erase(0, 7);
	cout << a << endl;
	a.clear();
	cout << a << endl;
}
*/
/*
// 8)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("I study C++");
	string c = a.substr(2, 4);
	string d = a.substr(2);
	cout << c << "  " << d << endl;
}
*/
/*
// 9)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("I love love C++");
	int index = a.find("love");
	cout << index << endl;
	index = a.find("love", index + 1);
	cout << index << endl;
	index = a.find("C#");
	cout << index << endl;
	index = a.find("v", 7);
	cout << index << endl;
}
*/
/*
// 10)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("I love love C++");
	char ch1 = a.at(8);
	char ch2 = a[8];
	cout << ch1 << "  " << ch2 << endl;
}
*/
/*
// 11)
#include<iostream>
//#include<string>
#include<cstring>
using namespace std;
int main()
{
	char *year = "2014";
	//int n = stoi(year);
	int n = atoi(year);
	cout << n + 1 << endl;
}
*/
/*
// 12) 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "hello";
	for (int i = 0; i < a.length(); i++)
		a[i] = toupper(a[i]);
	cout << a << endl;
	if (isdigit(a[0])) cout << "����" << endl;
	else if (isalpha(a.at(0))) cout << "����" << endl;
}
*/
/*
// 13)
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "I love";
	a.append(" jane").append(" and ").append("  helen ");
	cout << a << endl;
}
*/
/*
// 14)
#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string str1 = "I like ";
	string str2 = "string class";
	string str3 = str1 + str2;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	str1 += str2;
	if (str1 == str3)
		cout << "���Ϲ��ڿ�" << endl;
	else
		cout << "�������� ���� ���ڿ�" << endl;
	string str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;
	return 0;
}
*/


/*
// 6�� - StringŬ����
#include<iostream>
#include<cstring>
using namespace std;

class String {
private:
	int len;
	char *str;
public:
	String();
	String(const char * s);
	String(const String& s);
	~String();
	String& operator= (const String& s);
	String& operator+= (const String& s);
	bool operator==(const String& s);
	String operator+ (const String& s);

	friend ostream& operator<< (ostream &os, const String& s);
	friend istream& operator>> (istream& is, String & s);
};

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char *s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)
		delete[] str;
}

String& String::operator=(const String& s)
{
	if (str != NULL)
		delete[]str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+= (const String& s)
{
	len += (s.len - 1);
	char * tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if (str != NULL)
		delete[]str;
	str = tempstr;
	return *this;
}

bool String::operator== (const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s)
{
	char* tempstr = new char[len + s.len - 1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr);
	delete[] tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)
{
	os << s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "���Ϲ��ڿ�" << endl;
	else
		cout << "���������������ڿ�" << endl;

	String str4;
	cout << "���ڿ��Է�";
	cin >> str4;
	cout << "�Է��ѹ��ڿ�" << str4 << endl;
	return 0;
}
*/



/*
// ����Ǯ�� ���� - 12������
// 1��
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a("Hello C++");
	// string a = "Hello C++";
	cout << a.length() << endl;
	cout << a << endl;
	cout << a.at(6) << endl;
	cout << a.find("C") << endl;
	int n = a.find("+++");
	cout << n << endl;
	a.erase(1, 3);
	cout << a << endl;
}
*/

/*
// 2��
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string rotate;
	cout << "���ڿ� �Է� : ";
	getline(cin, rotate);
	int p = 0;
	for (int k = 0; k < rotate.length()+1; k++) {
		for (int i = p; i < rotate.length(); i++) {
			cout << rotate[i];
		}
		for (int i = 0; i < p; i++)
			cout << rotate[i];
		p++;
		cout << endl;
	}
}
*/
/*
// 3��
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	string text;
	cout << "�� ���� ���ڿ��� �Է��ϼ���" << endl;
	getline(cin, text);
	int r = rand() % text.length();
	text.at(r) = 'H';
	cout << "�����ϰ� ������ ��� : " << text << endl;
}
*/


/*
// 4�� 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string text;
	string reverse = "";
	cout << "���ڿ��� �Է��ϼ��� : ";
	getline(cin, text);
	int k = 0;
	for (int i = text.length()-1; 0 <= i; i--,k++) {
		reverse += text[i];
	}
	cout << reverse << endl;
}
*/



/*
// 5��
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string number;
	cout << "����� �Է� : ";
	getline(cin, number);

	int start=0, find, len;
	int num;
	int sum = 0;
	string n2;

	while (1) {
		find = number.find('+', start);
		if (find == -1) {
			n2 = number.substr(start);
			num = stoi(n2);
			cout << num << endl;
			sum += num;
			break;
		}
		len = find - start;
		n2 = number.substr(start, len);
		num = stoi(n2);
		cout << num << endl;
		
		sum += num;
		start = find + 1;
	}
	
	cout << "���ڵ��� ���� " << sum << endl;
}
*/




/*
// 6��  // �°� �Ѱ��� ����
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string text;
	string find_string, replace_string;
	cout << "�������� ���ڿ��� �Է��ϼ���. ���ڿ��� ���� &�Դϴ� => " << endl;
	getline(cin, text, '&');
	getchar();

	cout << "\nfind => ";
	getline(cin, find_string);
	cout << "replace => ";
	getline(cin, replace_string);

	int start = 0;
	while (1) {
		int find = text.find(find_string, start);
		if (find == -1) break;
		if (find_string.length() > replace_string.length()) {  // ã�� ���ڿ�(�������ڿ�)�� �ٲ� ���ڿ����� �� �� ���
			text.replace(find, find_string.length(), replace_string);
		}  // �� �κ� �°� �Ѱ��� ����
		else if (find_string.length() < replace_string.length()) { // �ٲ� ���ڿ��� ���� ���ڿ����� �� �� ���
			string front = text.substr(0, find);
			front += replace_string;
			string behind = text.substr(find + find_string.length());
			text = front + behind;
		} 
		else {    // �Ȱ��� ���
			text.replace(find, replace_string.length(), replace_string);
		}
		start = find + 1;
	}
	cout << endl << text << endl;
}

*/


/*
// 6��  
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string text;
	string find_string, replace_string;
	cout << "�������� ���ڿ��� �Է��ϼ���. ���ڿ��� ���� &�Դϴ� => " << endl;
	getline(cin, text, '&');
	getchar();

	cout << "\nfind => ";
	getline(cin, find_string);
	cout << "replace => ";
	getline(cin, replace_string);

	int start = 0;
	while (1) {
		int find = text.find(find_string, start);
		if (find == -1) break;

		string front = text.substr(0, find);
		front += replace_string;
		string behind = text.substr(find + find_string.length());
		text = front + behind;

		start = find + 1;
	}
	cout << endl << text << endl;
}
*/

/*
// 7��
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string text;
	string cnt[26] = { "" };
	int arr_num[26] = { 0 };
	int num = 0;
	cout << "���ڿ� �Է� = >\n";
	getline(cin, text);

	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i])) { 
			if (isupper(text[i])) text[i] = tolower(text[i]);
			cnt[text[i] - 97] += '*'; 
			arr_num[text[i] - 97]++;
			num++;
		}
	}
	cout << "\n�� ���ĺ� ��  " << num << endl;
	cout << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(97 + i) << "[" << arr_num[i] << "]  :  " << cnt[i] << endl;
	}
}
*/




/*
// 8�� - �����ձ� ���� - ���� - �ѱ��� �ѱ��ڰ� ������ 2byte! �ΰ� �о�� �� ���� - �ذ��
#include<iostream>
#include<string>
using namespace std;
const int MAX = 100;

int main()
{
	// string�̱� ������ .at �� �Ἥ �ؾ���
	//string s = "������";
	//char str[3];
	//str[0] = s.at(0);
	//str[1] = s.at(1);
	//str[2] = NULL;
	//puts(str);  // ��°�� '��' ����


	int n;  // �����ο�
	cout << "== �����ձ� ���ӽ��� ==\n";
	cout << "���ӿ� �����ϴ� �ο� : ";
	cin >> n;
	string word[MAX];  // �Է¹޴� �����ձ� �ܾ�
	string *name = new string[n];  // �����ο� �̸����
	for (int i = 0; i < n; i++) {
		cout << "�������� �̸��� �Է��ϼ��� : ";
		cin >> name[i];
	}

	char front_tmp[3];
	char tmp[3];
	//word[0] = "computer";
	word[0] = "��ǻ��";
	cout << "\n�����ϴ� �ܾ�� " << word[0] << "�Դϴ�.\n\n";
	for (int i=1;;i++) {
		cout << name[(i-1)%n] << " : ";
		cin >> word[i];

		front_tmp[0] = word[i - 1].at(word[i - 1].length() - 2);
		front_tmp[1] = word[i - 1].at(word[i - 1].length() - 1);
		front_tmp[2] = NULL;
		tmp[0] = word[i].at(0);
		tmp[1] = word[i].at(1);
		tmp[2] = NULL;

		if (strcmp(front_tmp, tmp)!=0) {
			cout << endl << name[(i-1)%n] << "�� �����ϴ�.�Ф�\n";
			break;
		}

	}
}
*/


 


// StringŬ������ ������ ���� ������ ���Ͽ� ���Ͽ� ���ô�.
// String Ŭ����

/*
#include<iostream>
#include<cstring>
using namespace std;
enum BOOL { FALSE, TRUE };
// Ŭ�����Ǽ���
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
*/



/*
// 26������ 
// 1��
#include"mystring.h"
void main()
{
	String K;
	String M("MBC");
	if (K.IsEmpty()) cout << "������Դϴ�.";
	else cout << "�������Դϴ�.";
	cout << (char)M.GetAt(0) << endl;
	M.SetAt(1, 'S');
	cout << (char)M[1] << endl;
}
*/

/*
// 2��
#include "mystring.h"
void main()
{
	String K;
	String M("MBC");

	K = M;  K.Puts();
	K = "KOREA";  K.Puts();
	K = 'T';
	cout << (char)K[0] << (char)K[1] << (char)K[2] << endl;

	String J;
	J = M + K;		J.Puts();
	J = M + "TBC";  J.Puts();
	J = "SBS" + M;  J.Puts();

	J = "KBS"; K = "KOREA";  J += "MBC";  J.Puts();
	J = "KBS"; K = "KOREA";  J += K;  J.Puts();
}
*/

/*
// 3��
#include "mystring.h"
void main()
{
	String K;
	String M;
	K = "KBS";  M = "KBS";
	if (K == M) cout << "����\n";
	if (K == "KBS") cout << "����\n";
	if ("KBS" == M) cout << "����\n";
	K = "KOREA";
	if (K != M) cout << "�����ʴ�\n";
	if (K != "KOREA") cout << "�����ʴ�\n";
	if ("KOREA" != M) cout << "�����ʴ�\n";
}
*/

/*
// 4��
#include "mystring.h"
void main()
{
	String K, M;
	K = "MBC";  M = "KBS";
	if (K > M) cout << "ũ��\n";
	if (K > "KOREA") cout << "ũ��\n";
	if ("Pae" > K) cout << "ũ��\n";
	if (K >= M) cout << "ũ�ų�����\n";
	if (K >= "MBC") cout << "ũ�ų�����\n";
	if ("MBC" >= K) cout << "ũ�ų�����\n";
}
*/

/*
// 5��
#include "mystring.h"
void main()
{
	String K, M;
	K = "MBC";  M = "KBS";
	if (M < K) cout << "�۴�\n";
	if (M < "KOREA") cout << "�۴�\n";
	if ("Bae" < K) cout << "�۴�\n";
	if (M <= K) cout << "�۰ų�����\n";
	if (K <= "MBC") cout << "�۰ų�����\n";
	if ("MBC" <= K) cout << "�۰ų�����\n";
}
*/

/*
// 6��
#include "mystring.h"
void main()
{
	String K, M;
	K = "MBC";
	cout << (int)K.Compare("mBC") << endl;
	cout << (int)K.CompareNoCase("mbc") << endl;
	K = "KOREA";
	M = K.Mid(2);   M.Puts();
	M = K.Mid(0, 3);  M.Puts();
	M = K.Left(4);  M.Puts();
	M = K.Right(3);  M.Puts();
}
*/

/*
// 7��
#include "mystring.h"
void main()
{
	String K, M;
	K = "koreA";   M = "koreA";
	K.MakeUpper();   K.Puts();
	M.MakeLower();   M.Puts();
	K.MakeReverse();  K.Puts();
}
*/

/*
// 8��
#include "mystring.h"
void main()
{
	String K, M;
	K = "AB CD       E";
	M = "ABCDE";
	K.TrimLeft();   K.Puts();
	cout << (int)K.Find('B') << endl;
	M = "Korea";
	cout << (int)M.Find("rea") << endl;
	K = "se Korea";   K.Puts();
	K.Replace("se", "Seoul of");   K.Puts();
}
*/


