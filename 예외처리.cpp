/*
// 1��
#include<iostream>
using namespace std;
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;

	cout << "���� �������� �Է��Ͻÿ�: ";
	cin >> pizza_slices;
	cout << "������� �Է��Ͻÿ�: ";
	cin >> persons;

	if (persons == 0) {
		cout << "����� 0�� �Դϴ�. " << endl;
	}
	else {
		slices_per_person = pizza_slices / persons;
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
	}
	return 0;
}
*/

/*
// 2��
#include<iostream>
using namespace std;
int main()
{
	int pizza_slices = 0;
	int persons = -1;
	int slices_per_person = 0;
	try {
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;

		if (persons == 0)
			throw persons;
		slices_per_person = pizza_slices / persons;
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
	}
	catch (int e) {
		cout << "error ~~ ����� " << e << "�� �Դϴ�. " << endl;
	}
	return 0;
}
*/
/*
// 3��
#include<iostream>>
using namespace std;
int dividePizza(int pizza_slices, int persons);
int main()
{
	int pizza_slices = 0;
	int persons = 0;
	int slices_per_person = 0;
	try {
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;
		slices_per_person = dividePizza(pizza_slices, persons);
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�. " << endl;
	}
	catch (int e) {
		cout << "error~~~ ����� " << e << " �� �Դϴ�. " << endl;
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
// 4��
#include<iostream>
using namespace std;
int main()
{
	int pizza_slices = 12;
	int persons = 0;
	int slices_per_person = 0;

	try {
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;

		if (persons < 0) throw "negative";		// ���� �߻�!
		if (persons == 0) throw persons;		// ���� �߻�!
		slices_per_person = pizza_slices / persons;
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�" << endl;
	}
	catch (const char *e) {
		cout << "����: ������� " << e << "�Դϴ�" << endl;
	}
	catch (int e) {
		cout << "����: ����� " << e << "���Դϴ�" << endl;
	}
	return 0;
}
*/

/*
 // 5��
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
		cout << "���� �������� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> persons;
		if (persons <= 0) throw NoPersonException(persons);		// ���ܹ߻�!
		slices_per_person = pizza_slices / persons;
		cout << "�ѻ���� ���ڴ� " << slices_per_person << "�Դϴ�." << endl;
	}
	catch (NoPersonException e) {
		cout << "����: ����� " << e.get_persons() << "�� �Դϴ�" << endl;
	}
	return 0;
}
*/

/*
// 6��
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
// 5������ ����Ǯ��
// 1�� 
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
	cout << "���ϴ� �迭 ũ�⸦ �Է��Ͻÿ�: ";
	cin >> n;
	SafeArray <int> arr(n);
	cout << "�ۼ��� �迭�� �ε����� �Է��Ͻÿ�: ";
	cin >> idx;
	arr[idx] = 5;
	cout << arr[idx] << endl;
}
*/



/*
// 2��
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
//		if (balance < m) throw "�ܾ��� �ʰ��Ͽ����ϴ�~~";
//		else {
//			balance -= m;
//			cout << m << "���� �����Ͽ����ϴ�~~" << endl;
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
			cout << m << "���� �����Ͽ����ϴ�~~" << endl;
		}
	}
	catch (bool e) {
		if(e==true) cout << "�ܾ��� �ʰ��Ͽ����ϴ�~~" << endl;
	}
}
int main()
{
	int m;
	BankAccount acc;
	cout << "���°� �����Ǿ����ϴ�.\n";
	cout << "���¿� �󸶸� �����ðڽ��ϱ� ? ";
	cin >> m;
	acc.setBalance(m);
	cout << "�����ܾ� : " << acc.getBalance() << endl;
	cout << "�󸶸� �����Ͻðڽ��ϱ� ? ";
	cin >> m;
	acc.withdraw(m);
}
*/

/*
// 3��
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
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n" << "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
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
			case 'a': {cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";   cin >> po;
				if (st.isfull()) throw StackError(true);
				else st.push(po); }
					  break;
			case 'P':
			case 'p': { if (st.isempty()) throw StackError(false);
					  else { st.pop(po);   cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n"; }}
					  break;

			}
			cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P, \n �����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
		}
		catch(StackError e){
			if (e.flow) e.prn_over();
			else e.prn_under();
		}

	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}
*/

/*
// 4��
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
			cout << "����� " << (sum / size) << "�Դϴ�.";
		}
		catch (char *e) {
			cout << e << endl;
		}
	}
};
int main()
{
	cout << "== ���ܰ� �ƴ� ���\n";
	int score1[] = { 10,20,30,40,50,60,70,80 };
	ProcessScore s1(score1, sizeof(score1)/sizeof(score1[0]));
	cout << "\n\n== ������ ��� (������ ������ ����ִ� ���)\n";
	int score2[] = { 10,20,30,40,50,60,-70,80 };
	ProcessScore s2(score2, sizeof(score2) / sizeof(score2[0]));
}
*/

/*
// 5��
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
		cout << "�迭�� ����� ���� ...\n";
		for (int i = 0; i < size; i++)
			cout << '[' << arr[i] << ']' << " ";
		cout << endl;
	}
	void found(int val) {
		try {
			int i;
			for (i = 0; i < size; i++) {
				if (arr[i] == val) { cout << val << " ���� ã�ҽ��ϴ�!\n"; break; }
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
	cout << "ã������ �Է��ϼ��� : ";
	cin >> val;
	search.found(val);
}
*/

/*
// 6��
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
		if (size < 0) throw ArrayError("�迭�� ũ�Ⱑ �����Դϴ� !");
		if (size > SIZE) throw ArrayError("�迭�ε����� ���� �ʰ��Դϴ� !");
		for (int i = 0; i < size; i++) {
			sum += arr[i];
		}
		if (size == 0) throw ArrayError("�и� 0�Դϴ� !");
		else {
			aver = sum / size; cout << "��հ��� " << aver << "�Դϴ� !\n";
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
	cout << "���� �Է��Ͻÿ� (10��)\n";
	for (int i = 0; i < SIZE; i++) {
		cout << "��: ";
		cin >> val;
		arr[i] = val;
	}
	//handling(arr, sizeof(arr)/sizeof(arr[0]));
	//handling(arr, -4);
	//handling(arr, 0);
	handling(arr, 11);
}
*/
