/*
// 1��
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char name[10], dept[20];
	int sid;
	cout << "�̸�>>";
	cin >> name;
	cout << "�й�(���ڷ�)>>";
	cin >> sid;
	cout << "�а�>>";
	cin >> dept;
	ofstream fout("c:\\temp\\student.txt");
	if (!fout) {
		cout << "student.txt ������ �� �� ����.";
		return 0;
	}
	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;
	fout.close();
}
*/
/*
// 2��
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fin;
	fin.open("c:\\temp\\student.txt");
	if (!fin) {
		cout << "������ �� �� ����";
		return 0;
	}
	char name[10], dept[20];
	int sid;
	fin >> name;
	fin >> sid;
	fin >> dept;
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;
	fin.close();
}
*/


/*
// 3��
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char* file = "c:\\windows\\system.ini";
	ifstream fin(file);
	if (!fin) {
		cout << file << " ���� ����" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)c;
		count++;
	}

	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close();
}
*/


/*
// 4��
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char* firstFile = "c:\\temp\\student.txt";
	char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);	// ���� ���� ���� ����
	if (!fout) {
		cout << firstFile << " ���� ����";
		return 0;
	}
	fstream fin(secondFile, ios::in);  // �б� ���� ���� ����
	if (!fin) {
		cout << secondFile << " ���� ����";
		return 0;
	}
	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
	}
	fin.close();
	fout.close();
}
*/

/*
// 5��
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "c:\\windows\\system.ini ���� ����" << endl;
		return 0;
	}
	char buf[81];  // �� ������ �ִ� 80���� ���ڷ� �����ȴٰ� ����
	while (true) {
		fin.getline(buf, 81);  // �� ������ �ִ� 80���� ���ڷ� ����
		if (fin.eof()) break;
		cout << buf << endl;
	}
	fin.close();
}
*/

/*
// 6��
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void fileRead(vector<string> &v, ifstream &fin) {
	string line;
	while (true) {
		getline(fin, line);
		if (fin.eof()) break;
		v.push_back(line);
	}
}
void search(vector<string> & v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);
		if (index != -1)
			cout << v[i] << endl;
	}
}
int main()
{
	vector<string> wordVector;
	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "words.txt ������ �� �� �����ϴ�" << endl;
		return 0;
	}
	fileRead(wordVector, fin);
	fin.close();
	cout << "words.txt ������ �о����ϴ�." << endl;
	while (true) {
		cout << "�˻��� �ܾ �Է��ϼ��� >>";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "���α׷��� �����մϴ�." << endl;
}
*/

/*
// 7��
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char* srcFile = "c:\\temp\\apple.jpg";
	char* destFile = "c:\\temp\\copyapple.jpg";
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}
*/

/*
// 8��
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char *file = "c:\\temp\\words.txt";
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}
	int count = 0;
	char s[32];
	while (!fin.eof()) {
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;
	}
	cout << endl << "���� ����Ʈ ���� " << count << endl;
	fin.close();
}
*/

/*
// 9��
#include<iostream>
#include<fstream>
using namespace std;
int main() {
	char* srcFile = "c:\\data\\apple.jpg";
	char* destFile = "c:\\data\\apple2.jpg";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}
	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}
	char buf[1024];
	while (!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		fdest.write(buf, n);
	}
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}
*/


/*
// 10��
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char *file = "c:\\Temp\\data.dat";
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if (!fout) {
		cout << "���� ���� ����";
		return 0;
	}
	int n[] = { 0,1,2,3,4,5,6,7,8,9 };
	double d = 3.15;
	fout.write((char*)n, sizeof(n));
	fout.write((char*)(&d), sizeof(d));
	fout.close();
	ifstream fin(file, ios::in);
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}

	fin.read((char*)n, sizeof(n));
	fin.read((char*)(&d), sizeof(d));

	for (int i = 0; i < 10; i++)
		cout << n[i] << ' ';
	cout << endl << d << endl;
	fin.close();
}
*/

/*
// 11��
#include<iostream>
#include<fstream>
using namespace std;

void showStreamState(ios & stream) {
	cout << "eof() " << stream.eof() << endl;
	cout << "fail() " << stream.fail() << endl;
	cout << "bad() " << stream.bad() << endl;
	cout << "good() " << stream.good() << endl;
}

int main()
{
	char* noExistFile = "noexist.txt";  // �������� �ʴ� ���ϸ�
	char* existFile = "c:\\Temp\\student.txt";  // �����ϴ� ���ϸ�

	ifstream fin(noExistFile);  // �������� �ʴ� ���� ����
	if (!fin) {  // ���� ���� �˻�
		cout << noExistFile << " ���� ����" << endl;
		showStreamState(fin);  // ��Ʈ�� ���� ���
		cout << existFile << " ���� ����" << endl;
		fin.open(existFile);
		showStreamState(fin);  // ��Ʈ�� ���� ���
		cout << endl;
	}

	// ��Ʈ���� ������ �а� ȭ�鿡 ���
	int c;
	while ((c = fin.get()) != EOF)
		cout.put((char)c);

	cout << endl << endl;
	showStreamState(fin);  // ��Ʈ�� ���

	fin.close();
}
*/




/*
// 12�� 
#include<iostream>
#include<fstream>
using namespace std;

const int SIZE = 1000;
void init_table(int table[], int size);

int main()
{
	int table[SIZE];
	int data;
	long pos;

	init_table(table, SIZE);

	// ���� ������ ���� ���� ����.
	ofstream os;
	os.open("c:\\Temp\\test.dat", ofstream::binary);
	if (os.fail()) {
		cout << "test.dat ������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	os.write((char*)table, sizeof(table));
	os.close();

	ifstream is;
	is.open("c:\\Temp\\test.dat", ofstream::binary);
	if (is.fail()) {
		cout << "test.dat ������ �� �� �����ϴ�." << endl;
		exit(1);
	}

	while (1) {
		cout << "���Ͽ����� ��ġ�� �Է��Ͻʽÿ� (0���� 999, ����-1): ";
		cin >> pos;
		if (pos = -1) break;
		is.seekg(ios::beg + pos * sizeof(int));
		is.read((char *)&data, sizeof(int));
		cout << pos << " ��ġ�� ����" << data << " �Դϴ�." << endl;
	}
	is.close();
	return 0;
}
// �迭�� �ε����� �������� ä���
void init_table(int table[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		table[i] = i * i;
}

*/


/*
// 13�� - ����-��ȣ

#include<iostream>
#include<fstream>
using namespace std;		 // ���� �̸� �ΰ� ��ɾ� �������� �Է¹���
int main(int argc, char *argv[])   // Ex) C > Cipher input.txt  output.txt
{
	if (argc != 3)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		exit(1);
	}
	ifstream is;
	is.open(argv[1]);
	ofstream os;
	os.open(argv[2]);
	char c;
	char tmp;
	while (!is.eof())
	{
		is.get(c);
		if (c != ' ')
			tmp = c - 29;
		else
			tmp = c;
		os << tmp;
	}
	cout << "���� ��ȣ�� ��ȣȭ�Ͽ����ϴ�." << endl;
	is.close();		os.close();
	return 0;
}
*/





/*
// ����Ǯ�� 12������
// 1��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "������ �� �� ����" << endl;
		return 0;
	}
	string s1, s2;
	getline(fin, s1);
	getline(fin, s2);
	
	cout << s1 << endl << s2 << endl;
	
	fin.close();
}
*/

/*
// 2��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "������ �� �� ����" << endl;
		return 0;
	}
	string s1;
	getline(fin, s1);
	for (int i = 0; i < s1.length(); i++)
		s1[i] = toupper(s1[i]);
	cout << s1 << endl;
}
*/

/*
// 3��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int SIZE = 100;

int main()
{
	int arr[SIZE];
	string a;
	int i, tmp;
	int size = 0;

	ifstream fin;
	fin.open("c:\\Temp\\test.txt");
	if (!fin) {
		cout << "������ �� �� ����" << endl;
		return 0;
	}
	for (i = 0; ; i++)
	{
		if (fin.eof()) break;
		fin >> arr[i];
		size++;
	}

	for (i = 0; i < size-1; i++) {
		for(int k=i;k<size; k++)
			if (arr[i] > arr[k]) {
				tmp = arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
	}
	ofstream fout("c:\\Temp\\test.txt");

	for (int i = 0; i < size; i++)
	{
		fout << arr[i] << endl;
	}

	fin.close();
	fout.close();

}
*/




/*
// 5��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;

typedef struct A {
	int n;
	string name;
	string tell;
	string mail;
}Person;

int main()
{
	int a, i;
	char c;
	Person person[MAX];
	Person tmp;
	char *filename = "c:\\Temp\\person.txt";

	ifstream fin;
	fstream fout(filename, ios::out | ios::app);	// ���� ���� ���� ����
	if (!fout) {
		cout << filename << " ���� ����";
		return 0;
	}

	for (i=0;;) {
		cout << "��ȣ�� �Է��ϼ��� : ";
		cin >> tmp.n;
		cout << "�̸��� �Է��ϼ��� : ";
		cin >> tmp.name;
		cout << "��ȭ��ȣ�� �Է��ϼ��� : ";
		cin >> tmp.tell;
		cout << "�����ּҸ� �Է��ϼ��� : ";
		cin >> tmp.mail;

		fout << tmp.n << " " << tmp.name << " " << tmp.tell << " " << tmp.mail << endl;
		 
		i++;
		cout << "��� (y/n) : ";
		cin >> c;
		if (c == 'y') continue;
		else break;
	}

	cout << endl << "�˻���ȣ : ";
	cin >> a;
	
	fin.open(filename);
	for (int k=0;k<i;k++) {
		if (fin.eof()) break;
		fin >> person[k].n;
		fin >> person[k].name;
		fin >> person[k].tell;
		fin >> person[k].mail;
	}
	
	for (int k = 0; k < i; k++) {
		if (person[k].n == a) cout << person[k].n << "  " << person[k].name << "  " << person[k].tell << "  " << person[k].mail << endl;
	}
}
*/


/*
// 6��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX = 100;

int main()
{
	string fruit[MAX];
	string find;
	ifstream fin;
	fin.open("c:\\Temp\\input.txt");
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}

	cout << "ã�� ���� �̸��� �Է��ϼ��� : ";
	cin >> find;

	for (int i=0;;i++) {
		if (fin.eof()) {
			cout << "�ش� ������ ã�� �� �����ϴ�.\n"; break;
		}
		getline(fin, fruit[i]);
		if (fruit[i] == find) {
			cout << "input.txt : " << (i + 1) << " " << fruit[i] << endl;
			break;
		}
	}
}
*/

/*
// 7��
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
const int MAX = 100;

int main()
{
	string fruit[MAX];
	ifstream fin;
	fin.open("c:\\Temp\\input.txt");
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}

	for (int i = 0;; i++) {
		if (fin.eof()) break;
		getline(fin, fruit[i]);
		cout << setw(6) << right << (i + 1) << ": " << fruit[i] << endl;
	}
	fin.close();
}
*/


/*
// 8��   
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	int charnum = 0, wordnum = 0, linenum;
	string word;
	ifstream fin;
	fin.open("c:\\Temp\\text.txt");
	if (!fin) {
		cout << "������ �� �� ����.";
		return 0;
	}
	 
	// getline���� �ѹ��徿 �޾Ƽ� - ������ ���� ū �����ϱ�
	// �ѹ����� �����ؼ� ����, �ܾ�� count
	for (linenum=0;;linenum++) {
		getline(fin, word);
		for (int i = 0; i < word.length(); i++) {
			if (word[i] == 32) wordnum++;
			charnum++;
		}
		wordnum++;
		if (fin.eof()) break;
	}

	wordnum = wordnum - (linenum - 1);
	
	cout << "���ڼ� : " << charnum << endl;
	cout << "�ܾ�� : " << wordnum << endl;
	cout << "����� : " << linenum << endl;

	fin.close();
}
*/





/*
// ��ɾ� ���� ���� ��� - �߿� notion�� �ʱ�
#include<iostream>
#include<fstream>
using namespace std;

int main(int n, char *arr[])
{
	cout << "�Է��ڷ� ";

	cout <<"���� :"<< n<<"  "<< arr[0]<<"  "<< arr[1];
	cin.get();
	cin.get();
}
*/



/*
// 9��  
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int n, char *argv[])
{

	char *filename1 = argv[1];
	char *filename2 = argv[2];
	char *newfile = argv[3];

	char w;

	ifstream fin(filename1);
	ofstream fout(newfile, ios::out | ios::app);
	for (;;) {
		if (fin.eof()) break;
		fin.get(w);
		fout << w;
	}
	fin.close();
	 
	
	fin.open(filename2);
	for (;;) {
		if (fin.eof()) break;
		fin.get(w);
		fout << w;
	}
	fin.close();
	
}
*/


/*
// 10�� 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int n, char *argv[]) {
	char *filename1 = argv[1];
	char *filename2 = argv[2];

	ifstream fin1(filename1);
	ifstream fin2(filename2);
	for (;;) {
		if (fin1.eof()) break;
		else if (fin2.eof()) break;
		if (fin1.get() != fin2.get()) {
			cout << "�ΰ��� ������ �ٸ��ϴ�.\n"; exit(1);
		}
	}
	cout << "�ΰ��� ������ ��ġ�մϴ�.\n";

	fin1.close();
	fin2.close();
}
*/




/*
// 11��
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char* filename1 = "c:\\Temp\\Red_Apple1.jpg";
	char* filename2 = "c:\\Temp\\Red_Apple2.jpg";
	fstream image1(filename1, ios::in | ios::binary);
	fstream image2(filename2, ios::in | ios::binary);

	for (;;) {
		if (image1.eof()) break;
		else if (image2.eof()) break;

		if (image1.get() != image2.get()) {
			cout << "�� �̹��� ������ �ٸ��ϴ�." << endl;
			return 0;
		}
	}
	cout << "�� �̹��� ������ �����ϴ�." << endl;

	image1.close();
	image2.close();
}
*/









/*
// 12�� 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> word;
	ifstream fin("c:\\Temp\\word.txt");
	if (!fin) { cout << "���� �� �� ����.\n"; return 0; }

	string search;
	string line;      
	while (1) {
		fin >> line;
		word.push_back(line);
		if (fin.eof()) break;               
	}
	fin.close();
	cout << "words.txt ���� �ε� �Ϸ�" << endl;
	cout << "�˻��� �����մϴ�. �ܾ �Է����ּ���." << endl;
	cout << "�ܾ� : ";
	cin >> search;

	
	int flag;
	for (int i = 0; i < word.size(); i++) {
		// �� ���ڸ� �ٸ� �ܾ� ã�� 
		flag = 0;
		if (search == word[i]) {}
		else {
			for (int k = 0; k < search.length(); k++) {
				if (search[k] != word[i][k]) flag++;
				if (flag > 1) break;
			}
			if (flag == 1) cout << word[i] << endl;
		}
	}
	
}
*/

/*
// 13��
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

typedef struct Person {
	string name;
	string tell;
}p;

int main()
{
	int num, i;
	p tmp;
	vector<p> person;
	ifstream fin("c:\\Temp\\person.txt");
	while (1) {
		fin >> tmp.name;
		fin >> tmp.tell;
		person.push_back(tmp);
		if (fin.eof()) break;
	}
	fin.close();
	cout << "person.txt ���� �ε� �Ϸ�" << endl;

	for (;;) {
		cout << "=== �޴�\n";
		cout << "1. ����ó �߰�\n";
		cout << "2. ����ó Ž��\n";
		cout << "3. ����ó ����\n";
		cout << "4. ����ó ����\n";
		cout << "5. ����\n";
		cout << "��ȣ�� �����ϼ���: ";
		cin >> num;
		if (num == 5) break;
		switch (num) {
		case 1: {
			cout << "�̸��� �Է��ϼ��� : ";
			cin >> tmp.name;
			cout << "��ȣ�� �Է��ϼ��� : ";
			cin >> tmp.tell;
			person.push_back(tmp);
		} break;
		case 2: {
			cout << "�˻��� ȸ���� �̸��� �Է��ϼ��� : ";
			cin >> tmp.name;
			for (i = 0; i < person.size(); i++) {
				if (tmp.name == person[i].name) {
					cout << "��ȣ�� " << person[i].tell << "�Դϴ�.\n"; break;
				}
			}
			if (i == person.size()) cout << "�ش� ȸ���� ã�� �� �����ϴ�.\n";
		} break;
		case 3: {
			cout << "����ó�� ������ ȸ���� �̸��� �Է��ϼ��� : ";
			cin >> tmp.name;
			for (i = 0; i < person.size(); i++) {
				if (tmp.name == person[i].name) {
					cout << "���� ������ ����ó�� �Է��ϼ��� : ";
					cin >> tmp.tell;
					person[i].tell = tmp.tell;
					cout << "����Ǿ����ϴ�.\n";
				}
			}
		} break;
		case 4: {
			cout << "������ ȸ���� �̸��� �Է��ϼ��� : ";
			cin >> tmp.name;
			for (i = 0; i < person.size(); i++) {
				if (tmp.name == person[i].name) {
					person.erase(person.begin() + i);
					cout << "�����Ǿ����ϴ�.\n";
				}
			}
		} break;
		default: break;
		}
	}

	ofstream fout("c:\\Temp\\person.txt");
	for (int k = 0; k < person.size(); k++) {
		fout << person[k].name << " " << person[k].tell << endl;
	}

	fout.close();
}
*/


/*
// 14�� 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	char w;
	string line;
	ifstream fin("c:\\Temp\\test.txt");
	for (;;) {
		if (fin.eof()) break;
		getline(fin, line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] != '"' && line[i + 1] == '/' && line[i + 2] == '/') break;
			else cout << line[i];
		}
		cout << endl;
	}
}
*/




/*
// 15�� 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ifstream fin("c:\\windows\\system.ini");
	string line;
	char c;
	int words = 0;  // �� ���ڼ�
	// �� ���ڼ� count
	for (;;) {
		if (fin.eof()) break;   // eof��°� ���� �� ���� Ŀ���� �� �ִ°� �ƴ϶� null������ �ƿ� ���� ������ ��������
		getline(fin, line);          // �ѹ� eof�� �������� seekg�� Ŀ���� �̵� ����Ű�� ����. �̹� ���� ������ ������ ������
		words += line.length() - 1;     // �̷� ���� �׳� ���� close�ߴٰ� �ٽ� open �ؼ� �ϸ� �� 
	}
	fin.close();

	fin.open("c:\\windows\\system.ini");

	int percent = 0;
	int tenpercent = words * 0.1;
	ofstream fout("c:\\Temp\\system.txt");
	for (int i = 0;;) {
		if (fin.eof()) break;
		fin.get(c);
		fout.put(c);
		i++;
		if (i % tenpercent == 0) {
			percent++;
			cout << "." << tenpercent << "B " << percent * 10 << "%\n";
		}
	}
	cout << words << "B ���� �Ϸ�\n";
	
	fin.close();
	fout.close();
}
*/




/*
// 16��               // �޸��� utf���� ( input.txt ���� utf-16���� �Ǿ� �ִ°� utf-8�� �ٲ�� ��)
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	char str[] = "Blessed is he who has found his work;let him ask no other blessedness";
	
	ofstream fout("c:\\Temp\\input.txt"); 
	for (int i = (sizeof(str) / sizeof(str[0]))-1; 0 <= i; i--) {
		fout << str[i];
	}
	fout.close();

	string reverse;
	ifstream fin("c:\\Temp\\input.txt");
	getline(fin, reverse);
	cout << reverse;
	fin.close();
}
*/




/*
// 17��
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) { return 0; }
	string line;

	for (int i = 1;; i++) {
		if (fin.eof()) break;
		getline(fin, line);
		cout << i << " : " << line << endl;
	}

	fin.close();
}
*/

/*
// 18��
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("c:\\windows\\system.ini");
	if (!fin) { return 0; }
	string line[100];
	string tmp;
	int n;

	for(int i = 0;; i++) {
		if (fin.eof()) break;
		getline(fin, tmp);
		line[i] = tmp;
	}
	fin.close();

	cout << "c:\\windows\\system.ini ���� �б� �Ϸ�\n";
	cout << "���� ��ȣ�� �Է��ϼ���. 1���� ���� ���� �Է��ϸ� ����\n";
	for (;;) {
		cout << ": ";
		cin >> n;
		if (n < 1) { cout << "�����մϴ�.\n"; break; }
		cout << line[n - 1] << endl;
	}
}
*/


/*
// 19�� - ��� ����
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<vector>
using namespace std;

int main()
{
	vector<string> v;
	ifstream fin("c:\\Temp\\words.txt");
	string line, answer;
	string next = "";
	char a;
	int cnt = 0;
	int r;
	while (!fin.eof()) {
		getline(fin, line);
		v.push_back(line);
		cnt++;
	}
	cout << "vector�� �ε� �Ϸ�..";
	fin.close();

	srand(time(NULL));

	cout << "��� ������ �����մϴ�.. (��Ʈ:����)\n";
	r = rand() % cnt;
	answer = v[r];
	for (int i = 0; i < answer.length(); i++) {
		next += "_";
	}
	for (int k = 0; k < next.length(); k++) {
		cout << next[k] << " ";
	}
	cout << endl;
	for (;;) {
		cout << "\n���ĺ��� �Է��ϼ��� : ";
		cin >> a;
		for (int i = 0; i < answer.length(); i++) {
			if (answer[i] == a) { next[i] = answer[i]; }
		}
		for (int k = 0; k < next.length(); k++) {
			cout << next[k] << " ";
		}
		if (next == answer) {
			cout << "������ ������ϴ�! ��������\n"; break;
		}
	}

}
*/




/*
// 20��
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> v;
	string word;
	ifstream fin("c:\\Temp\\words.txt");
	if (!fin) { return 0; }

	for (;;) {
		if (fin.eof()) break;
		fin >> word;
		v.push_back(word);
	}
	cout << "... words.txt ���� �ε� �Ϸ�\n";
	cout << "�˻��� �����մϴ�. �ܾ �Է����ּ���.\n";

	int i, k;
	for (;;) {
		cout << "�ܾ�>> ";
		cin >> word;
		if (word == "exit") { cout << "����Ǿ����ϴ�.\n"; break; }
		for (i = 0; i < v.size(); i++) {
			for (k = 0; k < word.length(); k++)
			{
				if (word[k] != v[i][k]) break;
			}
			if (k == word.length()) cout << v[i] << endl;
		}
	}

}
*/

/*
// 21��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	char s[30];
	int byte = 0;
	ifstream fin("c:\\windows\\system.ini");
	while (!fin.eof()) {
		fin.read(s, 30);
		byte += fin.gcount();
		cout << fin.gcount() << endl;
	}

	cout << "c:\\windows\\system.ini ������ ũ��� " << byte << "����Ʈ\n";
}
*/




/*
// 22��
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
typedef struct p {
	int num;
	int size;
}Table;
int main()
{
	ifstream fin("c:\\Temp\\student.txt");
	ofstream fout("c:\\Temp\\student.txt", ios::app);

	string tmp;
	int num; string name;
	int kor, eng, math;
	int n;
	int cnt = 0;

	int move;

	Table table[100];
	int i;
	for (i=0;;i++) {
		if (fin.eof()) break;
		getline(fin, tmp);
		table[i].num = i + 1;
		table[i].size = tmp.length() + 2;
		cnt++;
	}
	for (int k = 0; k < i; k++)
		cout << table[k].size << endl;



	for (;;) {
		cout << "=== �޴�\n";
		cout << "1. �����Է�\n";
		cout << "2. ��ȣ�˻�\n";
		cout << "3. ����ǥ ���\n";
		cout << "4. ����\n";
		cout << "==> ";
		cin >> n;
		if (n == 4) { cout << "����Ǿ����ϴ�.\n"; break; }
		else if (n == 1) {
			cout << "��ȣ : ";
			cin >> num;
			cout << "�̸� : ";
			cin >> name;
			cout << "���� ���� ���� : ";
			cin >> kor >> eng >> math;
			fout << num << " " << name << " " << kor << " " << eng << " " << math << endl;
		}
		else if (n == 2) {
			//fin.seekg(ios::beg + 0);
			cout << "�˻��� ��ȣ�� �Է��ϼ��� : ";
			cin >> num;
			if (num > cnt) cout << "out of range\n";
			else {
				move = 0;
				for (int k = 1; k < num; k++) {
					move += table[k - 1].size;
				}
				fin.seekg(ios::beg + move);
				getline(fin, tmp);
				cout << tmp << endl;
			}
		}
		else break;
	}
}
*/

