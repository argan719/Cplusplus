//#include<iostream>
//int main(void)
//{
//	int num = 20;
//	std::cout << "Hello World!" << std::endl;
//	std::cout << "Hello " << "World!" << std::endl;
//	std::cout << num << ' ' << 'A';
//	std::cout << ' ' << 3.14 << std::endl;
//	return 0;
//}

/*
#include<iostream>
int main(void)
{
	int val1; 
	std::cout << "ù ��° �����Է�: ";
	std::cin >> val1;
	int val2;
	std::cout << "�� ���� �����Է�: ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "�������: " << result << std::endl;

	char str[100];
	std::cin >> str;
	std::cout << str << std::endl;
	return 0;
}

#include<iostream>
int main()
{
	char str[80];
	char ch;
	int i = 0;
	std::cout << " ������ �Է� �ϼ��� :";
	ch = std::cin.get(); //getchar()
	while (ch != '\n')
	{
		str[i] = ch;
		i++;
		ch = std::cin.get();
	}
	str[i] = '\0';
	std::cout << "�Էµ� ������ :" << str << std::endl;

	std::cout << "���ο� ������ �Է� �ϼ��� :";
	std::cin.getline(str, sizeof(str)); // ������ ������ ���ڿ� �Է� ���� gets()
	std::cout << "���� �Էµ� ������ :" << str << std::endl;
	return 0;
}

*/

/*
#include<iostream>
#include<cctype>
using namespace std;
int main()
{
	char ch;

	cout << "�ѹ��ڸ� �Է��Ͻʽÿ�. (�������� @)\n";
	cin.get(ch);
	while (ch != '@') {
		if (isalnum(ch))
		{
			if (isdigit(ch))
				;
			else if (islower(ch))
				cout.put(toupper(ch));
			else
				cout.put(tolower(ch));
		}
		else cout.put(ch); //�ѹ������ putchar()
		cin.get(ch);
	}
	return 0;
}
*/

/*
#include<iostream>
int main(void)
{
	using namespace std;
	int ch; 
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}
	cout << count << " ���ڸ� �о����ϴ�.\n";
	return 0;
}
*/

/*
#include<iostream>
using namespace std;

int main() {
	cout << "�ּҸ� �Է��ϼ���>>";

	char address[100];
	cin.getline(address, 100, '.'); //Ű����κ��� �ּ� �б�

	cout << "�ּҴ� " << address << "�Դϴ�\n"; //�ּ� ���
}
*/

/*
#include<iostream>
#include<string>
const int SIZE = 20;
int main()
{
	using namespace std;
	char firstName[SIZE];
	char lastName[SIZE];
	char fullName[2 * SIZE + 1];

	cout << "�۽�Ʈ ����(�̸�)�� �Է��Ͻÿ�: ";
	cin.getline(firstName, SIZE);
	cout << "��Ʈ ����(��)�� �Է��Ͻÿ�: ";
	cin.getline(lastName, SIZE);
	strncpy(fullName, lastName, SIZE);
	strcat(fullName, ", ");
	strncat(fullName, firstName, SIZE);
	fullName[2 * SIZE] = '\0';
	cout << "�ϳ��� ���ڿ��� �����: "
		<< fullName << endl;
	return 0;

}
*/



// 4������ 9��

 /* �ʱ� �س��� - Stirng ���� �������� ���� ���� �迭�� �����ؼ� ����� ���� ������ */
 //  string            char str[100]
 //���Ѵ����          ����������
 //s="akafkl"          strcpy(s, "afkalkf")
 //s+="111"             strcat(s,"111")
 //s.length              strlen(s)
//getline(cin, str);    cin.getline()

/*
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char charr[20];
	string str;

	cout << "�Է� ������ charr�� �ִ� ���ڿ��� ����: "
		<< strlen(charr) << endl;
	cout << "�Է� ������ str�� �ִ� ���ڿ��� ����: "
		<< str.size() << endl;

	cout << "�ؽ�Ʈ �� ���� �Է��Ͻÿ�:\n";
	cin.getline(charr, 20);
	cout << "�Է��� �ؽ�Ʈ: " << charr << endl;

	cout << "�� �ٸ� �ؽ�Ʈ �� ���� �Է��Ͻÿ�:\n";
	getline(cin, str);			// ���� cin�� ���� �����ڰ� �ƴ϶� �Ű�����
	cout << "�Է��� �ؽ�Ʈ: " << str << endl;
	cout << "�Է� ���Ŀ� charr�� �ִ� ���ڿ��� ����: "
		<< strlen(charr) << endl;
	cout << "�Է� ���Ŀ� str�� �ִ� ���ڿ��� ����: "
		<< str.size() << endl;

	return 0;
}

*/


/*
// 6������ 12��
#include<iostream>
using namespace std;
#include<iomanip>
#define LINE(n) {int i; for(i=0; i<n; i++) cout << '='; cout << endl;}
int main()
{
	char name[20];
	int kor, eng, mat, tot;
	double avg;

	cout << "�̸� �Է� : ";
	cin.getline(name, sizeof(name));
	cout << "�� ������ ���� �Է� : ";
	cin >> kor >> eng >> mat;
	tot = kor + eng + mat;
	avg = tot / 3.0;

	cout << setw(40) << "=====< ����ǥ >=====" << "\n\n";
	LINE(60);
	cout << setw(10) << "�̸�" << setw(10) << left << "����" << setw(10) << "����"
		<< setw(10) << "����" << setw(10) <<"����" << setw(10) << "���" << endl;
	LINE(60);
	cout << fixed;
	cout << setw(10) << name << setw(10) << kor << setw(10) << eng << setw(10)
		<< mat << setw(10) << tot << setw(10) << setprecision(4) << avg << endl;

	return 0;
}
*/


/*
// 7������ 13��
#include<iostream>
using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}
int main(void)
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	namespace ABC = AAA::BBB::CCC;

	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;

	using namespace ABC;
	cout << num1;
	return 0;
}
*/


/*
#include<iostream>
int main(void)
{
	int num = 20;
	std::cout << "Hello " << "World!" << std::endl;
	std::cout << num << ' ' << 'A';
	
}
*/

/*
// 4������ 8��
#include<iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ�:\n";
	cin.get(name, ArSize).get();
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin.get(dessert, ArSize).get();
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "��!\n";
	return 0;
}
*/


/*
#include<iostream>
#include<string>
using namespace std;

int main() {
	string song = "Falling in love with you";
	string elvis("Elvis Presley");
	string singer; //���ڿ� singer

	cout << song + "�� �θ� ������";
	cout << "(��Ʈ: ù ���ڴ� " << elvis[0] <<  ")?";

	getline(cin, singer);	//string Ÿ���� C++ ���ڿ��� �Է¹ޱ� ���� �����Լ�
	if (singer == elvis)
		cout << "�¾ҽ��ϴ�";
	else
		cout << "Ʋ�Ƚ��ϴ�" + elvis + "�Դϴ�" << endl;
}
*/

/*
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy(charr1, charr2);

	str1 += " paste";
	strcat(charr1, " juice");

	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << str1 << " ���ڿ����� " << len1 << "���� ���ڰ� ��� �ִ�.\n";
	cout << charr1 << " ���ڿ����� " << len2 << "���� ���ڰ� ��� �ִ�.\n";
}
*/







/*
// 8������ 1��
#include<iostream>
#include<iomanip>
int main()
{
	using namespace std;
	for (int i = 1; i <= 100; i++) {
		cout << left << setw(10) << i;
		if (i % 10 == 0) cout << endl;
	}
}
*/



/*
//2��
#include<iostream>
int main()
{
	using namespace std;
	float num;
	float max;
	cout << "5���� �Ǽ��� �Է� �ϼ��� : ";
	cin >> max;
	for (int index = 1; index < 5; index++) {
		cin >> num;
		if (max < num) max = num;
	}
	cout << endl;
	cout << "���� ū �� = " << max;
}
*/



/*
//3��
#include<iostream>
const int SIZE = 100;
int main()
{
	using namespace std;
	char str[SIZE];
	int index = 0;
	int sum = 0;
	cout << "100�� �̸��� ���ڵ��� �Է� �ϼ��� : ";
	cin.getline(str,SIZE);
	while (str[index] != '\0') {
		if (str[index] == 'x') sum++;
		index++;
	}
	cout << "x�� ������ " << sum << endl;
}
*/




/*
//4��
#include<iostream>
#include<string>
const int SIZE = 100;
int main()
{
	using namespace std;
	char ch1[SIZE];
	char ch2[SIZE];
	
	cout << "��ȣ�� �Է��ϼ��� : ";
	cin.getline(ch1, SIZE);
	cout << "��ȣ�� �ٽ� �ѹ� �Է��ϼ��� : ";
	cin.getline(ch2, SIZE);
	if (strcmp(ch1, ch2) == 0) cout << "��ȣ�� �¾ҽ��ϴ�." << endl;
	else cout << "��ȣ�� Ʋ�Ƚ��ϴ�." << endl;

}
*/



/*
// 5��
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string yes = "yes";
	string input;

	for (;;)
	{
		cout << "�����ϰ� ������ \'yes\'�� �Է��ϼ��� : ";
		getline(cin, input);
		if (yes == input) {
			cout << "�����մϴ�" << endl;
			break;
		}
	}
}
*/



/*
// 6��
#include<iostream>
#include<string>
const int SIZE = 100;
int main()
{
	using namespace std;
	char text[SIZE];  // �Է¹޴� ���ڿ�
	string person[5]; // ���� �̸� �����ϱ� ���� �迭
	int len[5];	// ���� �̸� ���� �����ϱ� ���� �迭
	cout << "5���� �̸��� ; ���� �����Ͽ� �Է��ϼ���" << endl;
	cin.getline(text, SIZE);
	string name;  // �̸� �����ؼ� �ӽ� �����ϱ� ���� string
	int num = 0; // �̸� ����
	for (int i = 0; i < strlen(text); i++)
	{
		// ; ������ ��� �����ֱ�
		if (text[i] == ';') {
			person[num] = name;
			len[num] = name.length();
			num++;
			cout << num << "  :  " << name << endl;
			name = ""; // ����� string �ʱ�ȭ
		}
		else {
			name += text[i];
		}
	}
	int max = 0;
	string long_name;
	for (int k = 0; k < 5; k++)
	{
		if (max < len[k]) {
			max = len[k];
			long_name = person[k];
		}
	}
	cout << "���� �� �̸��� " << long_name;

}
*/



/*
// 7��
#include<iostream>
int main()
{
	using namespace std;
	char str[100];
	cout << "���ڿ� �Է� : ";
	cin.getline(str, 100);
	int index = 0;
	while (str[index] != '\0') {
		for (int i = 0; i <= index; i++) {
			cout << str[i];
		}
		cout << endl;
		index++;
	}
}
*/





/*
// 8��  

#include<iostream>
#include<string>
int main()
{
	using namespace std;
	int num1, num2;
	char num[20];
	char first_num[10];
	int first_index = 0;
	char second_num[10];
	int second_index = 0;
	int flag = 1;
	int calculate;

	cout << "? ";
	cin.getline(num, 20);
	for (int i = 0; i < strlen(num); i++)
	{
		// ������ ���
		if (num[i] == 32) {
			flag++;
		}
		// �������� ���
		else if ((37 <= num[i] && num[i] <= 47) && flag==2)  {
			switch (num[i]) {
			case 43: calculate = 1; break;
			case 45: calculate = 2; break;
			case 42: calculate = 3; break;
			case 47: calculate = 4; break;
			case 37: calculate = 5; break;
			}
		}
		//�����ΰ��
		else {
			// ù��° �����ϰ��
			if (flag == 1) {
				first_num[first_index] = num[i];
				first_index++;
			}
			// �ι�° �����ϰ��
			else {
				second_num[second_index] = num[i];
				second_index++;
			}
		}
	}

	num1 = atoi(first_num);
	num2 = atoi(second_num);

	cout << num1 << " ";
	if (num2 < 0 && calculate == 2) { cout << " + " << -num2 << " = " << num1 + -num2; }
	else {
		switch (calculate) {
		case 1: cout << "+ " << num2 << " = " << num1 + num2; break;
		case 2: cout << " - " << num2 << " = " << num1 - num2; break;
		case 3: cout << " * " << num2 << " = " << num1 * num2; break;
		case 4: if (num2 != 0) { cout << " / " << num2 << " = " << num1 / num2; } break;
		case 5: cout << " % " << num2 << " = " << num1 % num2; break;
		}
	}
	cout << endl;
	
}
*/






/*
// 9��
#include<iostream>
#include<string>
#include<iomanip>
const int SIZE = 10000;
int main()
{
	using namespace std;
	char text[SIZE];
	int number[26] = { 0 };
	int index;
	int total = 0;
	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl << "�ؽ�Ʈ�� ���� ;�Դϴ�. 10000������ �����մϴ�." << endl;
	
	cin.getline(text, SIZE, ';');

	//cout << "�� ���ĺ� �� " << strlen(text) << endl;
	
	for (index = 0; index < strlen(text); index++)
	{
		// �빮�ڴ� �ҹ��ڷ� ��ȯ
		if (isupper(text[index])) {
			text[index] = tolower(text[index]);
		}
		// ���ĺ� ���� ����
		if (97 <= text[index] && text[index] <= 122) {
			total++;
			number[text[index] - 97]++;
		}
	}
	//������׷� ���
	cout << "\n\n�� ���ĺ� �� " << total << endl;
	for (int i = 0; i < 26; i++)
	{
		cout.put(97+i) << "(" << number[i] << ")"  <<setw(5)<<"  :  ";
		for (int k = 0; k < number[i]; k++) {
			cout << '*';
		}
		cout << endl;
	}
}
*/




#include<iostream>
using namespace std;

void swap(int& p1, int& p2) {
	cout << "p1 : " << p1 << endl;
	cout << "p2 : " << p2 << endl;
}

int main(void) {
	int a = 5;
	int b = 10;

	swap(a, b);

}