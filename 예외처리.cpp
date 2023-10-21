/*
// 1번
#include<iostream>
using namespace std;
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;

	cout << "피자 조각수를 입력하시오: ";
	cin >> pizza_slices;
	cout << "사람수를 입력하시오: ";
	cin >> persons;

	if (persons == 0) {
		cout << "사람이 0명 입니다. " << endl;
	}
	else {
		slices_per_person = pizza_slices / persons;
		cout << "한사람당 피자는 " << slices_per_person << "입니다." << endl;
	}
	return 0;
}
*/

/*
// 2번
#include<iostream>
using namespace std;
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;
	try {
		cout << "피자 조각수를 입력하시오: ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시오: ";
		cin >> persons;

		if (persons == 0)
			throw persons;
		slices_per_person = pizza_slices / persons;
		cout << "한사람당 피자는 " << slices_per_person << "입니다." << endl;
	}
	catch (int e) {
		cout << "error ~~ 사람이 " << e << "명 입니다. " << endl;
	}
	return 0;
}
*/
/*
// 3번
#include<iostream>>
using namespace std;
int dividePizza(int pizza_slices, int persons);
int main()
{
	int pizza_slices = 0;
	int persons = 0;
	int slices_per_person = 0;
	try {
		cout << "피자 조각수를 입력하시오: ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시오: ";
		cin >> persons;
		slices_per_person = dividePizza(pizza_slices, persons);
		cout << "한사람당 피자는 " << slices_per_person << "입니다. " << endl;
	}
	catch (int e) {
		cout << "error~~~ 사람이 " << e << " 명 입니다. " << endl;
	}
	return 0;
}
int dividePizza(int pizza_slices, int persons) {
	if (persons == 0)
		throw persons;
	return pizza_slices / persons;
}
*/

/*
// 4번
#include<iostream>
using namespace std;
int main()
{
	int pizza_slices = 12;
	int persons = 0;
	int slices_per_person = 0;

	try {
		cout << "피자 조각수를 입력하시오: ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시오: ";
		cin >> persons;

		if (persons < 0) throw "negative";		// 예외 발생!
		if (persons == 0) throw persons;		// 예외 발생!
		slices_per_person = pizza_slices / persons;
		cout << "한사람당 피자는 " << slices_per_person << "입니다" << endl;
	}
	catch (const char *e) {
		cout << "오류: 사람수가 " << e << "입니다" << endl;
	}
	catch (int e) {
		cout << "오류: 사람이 " << e << "명입니다" << endl;
	}
	return 0;
}
*/

/*
 // 5번
#include<iostream>
using namespace std;
class NoPersonException {
public:
	NoPersonException();
	NoPersonException(int p) { persons = p; }
	int get_persons() { return persons; }
private:
	int persons;
};
int main()
{
	int pizza_slices = 12;
	int persons = -1;
	int slices_per_person = 0;

	try {
		cout << "피자 조각수를 입력하시오: ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시오: ";
		cin >> persons;
		if (persons <= 0) throw NoPersonException(persons);		// 예외발생!
		slices_per_person = pizza_slices / persons;
		cout << "한사람당 피자는 " << slices_per_person << "입니다." << endl;
	}
	catch (NoPersonException e) {
		cout << "오류: 사람이 " << e.get_persons() << "명 입니다" << endl;
	}
	return 0;
}
*/

/*
// 6번
#include<iostream>
using namespace std;
class ParentException {
public:
	void display() { cout << "ParentException" << endl; }
};
class ChildException : public ParentException {
public:
	void display() { cout << "ChildException" << endl; }
};
int main()
{
	try {
		throw ChildException();
	}
	catch (ChildException& e)
	{
		e.display();
	}
	catch (ParentException& e)
	{
		e.display();
	}
	
	return 0;
}
*/




/*
// 5페이지 문제풀이
// 1번 
#include<iostream>
using namespace std;
class IndexException {
public:
	void prn_error() {
		cout << "IndexException" << endl;
	}
};
template<class T>
class SafeArray {
private:
	T *arr;
	int size;
public:
	SafeArray() {}
	SafeArray(int n) : size(n) {
		arr = new T[size];
	}
	T& operator[](int);
};
template<class T>
T& SafeArray<T>::operator[](int idx) {

	try {
		if (idx < 0 || size <= idx) throw IndexException();
		else return arr[idx];
	}
	catch (IndexException e) {
		e.prn_error();
	}
}

int main()
{
	int idx, n;
	cout << "원하는 배열 크기를 입력하시오: ";
	cin >> n;
	SafeArray <int> arr(n);
	cout << "작성할 배열의 인덱스를 입력하시오: ";
	cin >> idx;
	arr[idx] = 5;
	cout << arr[idx] << endl;
}
*/



/*
// 2번
#include<iostream>
#include<string>
using namespace std;
class BankAccount {
	int balance;
public:
	BankAccount() { balance = 0; }
	BankAccount(int b) { balance = b; }
	int getBalance() { return balance; }
	void setBalance(int b) { balance = b; }
	void deposit(int amount) { balance += amount; }
	void withdraw(int m);
};

//void BankAccount::withdraw(int m) {
//	try {
//		if (balance < m) throw "잔액을 초과하였습니다~~";
//		else {
//			balance -= m;
//			cout << m << "원을 인출하였습니다~~" << endl;
//		}
//	}
//	catch (char* e) {
//		cout << e << endl;
//	}
//}


void BankAccount::withdraw(int m) {
	try {
		if (balance < m) throw true;
		else {
			balance -= m;
			cout << m << "원을 인출하였습니다~~" << endl;
		}
	}
	catch (bool e) {
		if(e==true) cout << "잔액을 초과하였습니다~~" << endl;
	}
}
int main()
{
	int m;
	BankAccount acc;
	cout << "계좌가 생성되었습니다.\n";
	cout << "계좌에 얼마를 넣으시겠습니까 ? ";
	cin >> m;
	acc.setBalance(m);
	cout << "현재잔액 : " << acc.getBalance() << endl;
	cout << "얼마를 인출하시겠습니까 ? ";
	cin >> m;
	acc.withdraw(m);
}
*/

/*
// 3번
#include<iostream>
#include<string>
#include<cctype>
#include "stack.h"
using namespace std;
class StackError {
public:
	bool flow;
	StackError(bool f) : flow(f) {}
	void prn_under() {
		cout << "Stack Underflow !!\n";
	}
	void prn_over() {
		cout << "Stack Overflow !!\n";
	}
};
int main()
{
	Stack<string> st;
	char ch;
	string po;
	cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P,\n" << "종료하려면 Q를 입력하십시오.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		try {
			switch (ch) {
			case 'A':
			case 'a': {cout << "추가할 주문서의 번호를 입력하십시오: ";   cin >> po;
				if (st.isfull()) throw StackError(true);
				else st.push(po); }
					  break;
			case 'P':
			case 'p': { if (st.isempty()) throw StackError(false);
					  else { st.pop(po);   cout << "#" << po << " 주문서를 처리했습니다.\n"; }}
					  break;

			}
			cout << "주문서를 추가하려면 A, 주문서를 처리하려면 P, \n 종료하려면 Q를 입력하십시오.\n";
		}
		catch(StackError e){
			if (e.flow) e.prn_over();
			else e.prn_under();
		}

	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/

/*
// 4번
#include<iostream>
using namespace std;
class ProcessScore {
public:
	ProcessScore(int a[], int size) {
		try {
			if(size<=0) throw "lllegalScore ";
			int sum = 0;
			for (int i = 0; i < size; i++) {
				if (a[i] < 0) throw "lllegalScore ";
				else sum += a[i];
			}
			cout << "평균은 " << (sum / size) << "입니다.";
		}
		catch (char *e) {
			cout << e << endl;
		}
	}
};
int main()
{
	cout << "== 예외가 아닌 경우\n";
	int score1[] = { 10,20,30,40,50,60,70,80 };
	ProcessScore s1(score1, sizeof(score1)/sizeof(score1[0]));
	cout << "\n\n== 예외인 경우 (성적에 음수가 들어있는 경우)\n";
	int score2[] = { 10,20,30,40,50,60,-70,80 };
	ProcessScore s2(score2, sizeof(score2) / sizeof(score2[0]));
}
*/

/*
// 5번
#include<iostream>
using namespace std;
class SearchArray {
	int *arr;
	int size;
public:
	SearchArray() {}
	void prn(int a[], int s) {
		this->arr = a;
		this->size = s;
		cout << "배열에 저장된 값은 ...\n";
		for (int i = 0; i < size; i++)
			cout << '[' << arr[i] << ']' << " ";
		cout << endl;
	}
	void found(int val) {
		try {
			int i;
			for (i = 0; i < size; i++) {
				if (arr[i] == val) { cout << val << " 값을 찾았습니다!\n"; break; }
			}
			if (i == size) throw "NotFound !";
		}
		catch (char *e) {
			cout << e << endl;
		}
	}
};
int main() {
	int arr[] = { 11,22,33,44,55,66,77,88,99,111 };
	int val;
	SearchArray search;
	search.prn(arr, sizeof(arr) / sizeof(arr[0]));
	cout << "찾을값을 입력하세요 : ";
	cin >> val;
	search.found(val);
}
*/

/*
// 6번
#include<iostream>
using namespace std;
const int SIZE = 10;
class ArrayError {
	char *text;
public:
	ArrayError(char *t) : text(t) {	}
	void prn() {
		cout << text << endl;
	}
};
void handling(double arr[], int size) {
	double sum = 0;
	double aver;
	try {
		if (size < 0) throw ArrayError("배열의 크기가 음수입니다 !");
		if (size > SIZE) throw ArrayError("배열인덱스가 범위 초과입니다 !");
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		if (size == 0) throw ArrayError("분모가 0입니다 !");
		else {
			aver = sum / size; cout << "평균값은 " << aver << "입니다 !\n";
		}
	}
	catch (ArrayError e) {
		e.prn();
	}
}

int main()
{
	double arr[SIZE];
	double val;
	cout << "값을 입력하시오 (10번)\n";
	for (int i = 0; i < SIZE; i++) {
		cout << "값: ";
		cin >> val;
		arr[i] = val;
	}
	//handling(arr, sizeof(arr)/sizeof(arr[0]));
	//handling(arr, -4);
	//handling(arr, 0);
	handling(arr, 11);
}
*/
