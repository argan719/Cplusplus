/*
#include<iostream>
#include<climits>
using namespace std;
int main()
{
	int n_int = INT_MAX;	// n_int�� int ���� �ִ밪���� �ʱ�ȭ
	short n_short = SHRT_MAX;	// limits.h ���Ͽ� ���ǵ� ��ȣ ���
	long n_long = LONG_MAX;

	cout << "int�� " << sizeof(int) << " ����Ʈ�̴�." << endl;
	cout << "short�� " << sizeof n_short << " ����Ʈ�̴�." << endl;
	cout << endl;

	cout << "�ִ밪: " << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl << endl;
	cout << "long long: " << n_long << endl << endl;
	cout << "int�� �ּҰ� = " << INT_MIN << endl;
	cout << "char�� ��Ʈ �� = " << CHAR_BIT << endl;
	return 0;
}
*/


/*
#include<iostream>
#define ZERO 0
#include<climits>
int main()
{
	using namespace std;
	short Dohee = SHRT_MAX;
	unsigned short Insuk = Dohee;

	cout << "������ ���¿��� " << Dohee << " ���� ��� �ְ�.";
	cout << "�μ����� ���¿��� " << Insuk << " ���� ��� �ִ�." << endl;
	cout << "������ ���¿� 1���� �Ա��Ѵ�." << endl << "���� ";
	Dohee = Dohee + 1;		Insuk = Insuk + 1;
	cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << Insuk << "���� �Ǿ���." << endl;
	cout << "�̷�����! ���� �� ���� ������ �߳�?" << endl;
	Dohee = ZERO;		Insuk = ZERO;
	cout << "������ ���¿��� " << Dohee << "���� ��� �ְ�, ";
	cout << "�μ����� ���¿��� " << Insuk << "���� ��� �ִ�. " << endl;
	cout << "������ ���¿��� 1���� �����Ѵ�." << endl << "���� ";
	Dohee = Dohee - 1;
	Insuk = Insuk - 1;
	cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << Insuk << "���� �Ǿ���." << endl;
	cout << "�̷�����! �μ��̰� ���ǿ� ��÷�Ǿ���?" << endl;
	return 0;
}
*/


/*
//4�� 
#include<iostream>
using namespace std;
int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "�մ� ���Ŵ� �Ѹ���� ���� �ݴϴ�!" << endl;
	cout << "�����ѷ� " << chest << " (10����)" << endl;
	cout << hex;
	cout << "�㸮�ѷ� " << waist << " (16����)" << endl;
	cout << oct;
	cout << "�νɱ��� " << inseam << " (8����)" << endl;
	return 0;
}
*/


/*
// 5��
#include<iostream>
int main()
{
	using namespace std;
	char ch = 'M';

	int i = ch;
	cout << ch << " �� ASCII �ڵ�� " << i << "�Դϴ�." << endl;

	cout << "�� ���� �ڵ忡 1�� ���� ���ڽ��ϴ�." << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << "�Դϴ�." << endl;

	cout << "cout.put(ch)�� ����Ͽ� char�� ���� ch�� ȭ�鿡 ���: ";
	cout.put(ch);

	cout.put('!');

	cout << endl << "����" << endl;
	return 0;

}
*/


/*
// 6��
#include<iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;		//int���� float������ ��ȯ
	int guess(3.9832);	//float���� int������ ��ȯ
	int debt = 7.2E12;	// ���� ��� ��
	
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
	return 0;
	
}
*/


/*
// 7��
#include<iostream>
int main()
{
	using namespace std;
	int auks, bats, coots;

	// ���� ������ �� ���� double������ ���� �Ŀ�
	// �� ���� int������ ��ȯ�Ͽ� �����Ѵ�
	auks = 19.99 + 11.99;

	// ���� �� ������ �� ���� int������ ��ȯ�� �Ŀ� ���Ѵ�
	bats = (int)19.99 + (int) 11.99;	// ���� C ��Ÿ��
	coots = int(19.99) + int(11.99);	// �Ž� C++ ��Ÿ��
	
	cout << "�ٴٿ��� = " << auks << ", ���� = " << bats;
	cout << ", �˵տ��� = " << coots << endl;

	char ch = 'Z';
	cout << "�ڵ� " << ch << " �� ���� ";  // char������ ���
	cout << int(ch) << endl;		// int������ ���
	cout << "�ڵ� Z�� ���� ";
	cout << static_cast<int>(ch) << endl;	// int������ ���
	return 0;
}
*/


/*
// 8��
#include<iostream>
#include<string>	// strlen() �Լ��� ����ϱ� ����
int main()
{
	using namespace std;
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";
	cout << "�ȳ��ϼ���! ���� " << name2;
	cout << "�Դϴ�! �Ƿ������� ������?\n";
	cin >> name1;
	cout << "��, " << name1 << " ��! ����� �̸��� ";
	cout << strlen(name1) << "���Դϴٸ� \n";
	cout << sizeof(name1) << "����Ʈ ũ���� �迭�� ����Ǿ����ϴ�. \n";
	cout << "�̸��� " << name1[0] << "�ڷ� �����ϴ±���.\n";
	name2[3] = '\0';
	cout << "�� �̸��� ó�� �� ���ڴ� ������ �����ϴ�: ";
	cout << name2 << endl;
	return 0;
}
*/

/*
// 9��
#include<iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	inflatable guest ={ "Glorious Gloria", 1.88, 29.99 };
	inflatable pal = { "Audacious Arthur", 3.12, 32.99 };

	cout << "���� �Ǹ��ϰ� �ִ� ����ǳ����\n" << guest.name;
	cout << "�� " << pal.name << "�Դϴ�.\n";
	cout << "�� ��ǰ�� $";
	cout << guest.price + pal.price << "�� �帮�ڽ��ϴ�!\n";
	return 0;
}
*/




/*
// 10��
#include<iostream>
enum Dates{SUN=100, MON, TUE=3, WED, THU, FRI, SAT};
using namespace std;

int main() {
	cout << SUN;
	cout << THU;
	cout << "���� ������ �Է��ϼ���. " << endl;
	cout<< "SUN 0, MON 1, TUE 2, WED 3, THU 4, FRI 5, SAT 6" << endl;
	int today = 0;
	cin >> today;
	cout << "���� ���� ������ ���Ͻʴϱ� �Է��ϼ���. " << endl;
	int input = 0;
	cin >> input;
	cout << input << "�� ���Ĵ�  ";

	switch (((input + today) % 7)) {
		case SUN: cout << "SUNDAY" << endl; break;
		case MON: cout << "MONDAY" << endl; break;
		case TUE: cout << "TUESDAY" << endl; break;
		case WED: cout << "WENDS" << endl; break;
		case THU: cout << "THURSDAY" << endl; break;
		case FRI: cout << "FRIDAY" << endl; break;
		case SAT: cout << "SATURDAY" << endl; break;
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}
*/




// 8������~ ���� Ǯ�� ����


/*
// 8������ 1�� 
#include<iostream>
#include<iomanip>
int main()
{
	using namespace std;
	float num1, num2;
	cout << "�Ǽ� 2�� �Է� : ";
	cin >> num1 >> num2;
	cout << endl;
	cout << fixed;
	
	cout << setprecision(2);
	cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
	cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
	cout << num1 << " * " << num2 << " = " << (num1*num2) << endl;
	cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;

}
*/



/*
// 8������ 2��
#include<iostream>
#include<ctime>
#include<iomanip>
#include<climits>
int main()
{
	using namespace std;
	int numlist[101] = { 0 };
	int num;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		if (i % 20 == 0) cout << endl;
		num = rand() % 101 + 0;
		cout <<left<< setw(5) << num;
		numlist[num]++;
	}
	int max = INT_MIN;
	int max_num;
	for (int k = 0; k < 101; k++)
	{
		if (max < numlist[k]) {
			max = numlist[k];
			max_num = k;
		}
	}
	cout << endl << endl << "==> ���� ���� ������ �� : " << max_num << endl;

}
*/





/*
// 8������ 3��   -> ����. �ٽ��ϱ� (tic-tac-toe ����)
#include<iostream>
#include<time.h>
typedef struct A{
	int a;
	int b;
}block;

typedef struct B {
	block three_block[3];
}line;


int main()
{
	using namespace std;
	int ground[3][3] = { 0 };

	int row, col;
	int i = 0;
	int user_num = -1;
	int computer_num = -1;

	block user[9];
	block computer[9];

	line bingo[8] = {
		{0,0,1,0,2,0},
		{0,1,1,1,2,1},
		{0,2,1,2,2,2},
		{0,0,0,1,0,2},
		{1,0,1,1,1,2},
		{2,0,2,1,2,2},
		{0,0,1,1,2,2},
		{0,2,1,1,2,0}
	};

	while (i < 10)
	{
		cout << "����� : 'O'�� �� ���� �Է��ϼ��� (0 ~ 2 ���� 2�� �Է�)  ";
		cin >> row;
		cin >> col;
		if (row < 0 || 2 < row || col < 0 || 2 < col) {
			cout << "�߸� �Է��ϼ̽��ϴ�. 0,1,2 �� �ϳ��� �Է��ϼ���" << endl;
			i--;
		}
		else {
			if (ground[row][col] != 0) {
				cout << "�̹� ���� �ִ� �ڸ��Դϴ�. �ٸ� ���� �Է��ϼ���" << endl;
				i--;
			}
			else {
				ground[row][col] = 1;
				i++;
				user_num++;
				cout << "��ǻ�Ͱ� �Է� ���Դϴ�.." << endl;
				// ��ǻ�Ͱ� ó������ ���� �� ���
				if (i == 1) {
					if (0 < row) row -= 1;
					else if (0 < col) col -= 1;
					else row += 1, col += 1;

					ground[row][col] = 2;
					i++;
					computer_num++;
				}
				// ��ǻ�Ͱ� 2��° �̻� ���� �� ���
				else {
					for (int a = 0; a < 3; a++)
					{
						for (int b = 0; b < 3; b++)
						{
							// ����ڰ� �� ���� ��ġ ����
							if (ground[a][b] == 1) {
								user[user_num] = { a, b };
								break;
							}
						}
					}
					int flag;
					for (int j = 0; j <= user_num; j++)
					{
						for (int k = 0; k < 8; k++)
						{
							flag = 0;
							for (int l = 0; l < 3; l++) {
								if (bingo[k].three_block[l].a == user[j].a  && bingo[k].three_block[l].b == user[j].b) flag++;
							}
							if (flag == 2) {
								int p;
								for (p = 0; p < 3; p++)
								{
									if (ground[bingo[k].three_block[p].a][bingo[k].three_block[p].b] == 0) {
										row = bingo[k].three_block[p].a;
										col = bingo[k].three_block[p].b;
										break;
									}
								}
								if (p == 3) {
									for (int a = 0; a < 3; a++)
									{
										for (int b = 0; b < 3; b++)
										{
											// ��ǻ�Ͱ�  �� ���� ��ġ ����
											if (ground[a][b] == 1) {
												computer[computer_num] = { a, b };
												break;
											}
										}
									}
									int flag;
									for (int j = 0; j <= user_num; j++)
									{
										for (int k = 0; k < 8; k++)
										{
											flag = 0;
											for (int l = 0; l < 3; l++) {
												if (bingo[k].three_block[l].a == computer[j].a  && bingo[k].three_block[l].b == computer[j].b) flag++;
											}
											if (flag == 2) {
												int p;
												for (p = 0; p < 3; p++)
												{
													if (ground[bingo[k].three_block[p].a][bingo[k].three_block[p].b] == 0) {
														row = bingo[k].three_block[p].a;
														col = bingo[k].three_block[p].b;
														ground[row][col] = 2;
														i++;
														computer_num++;
														break;
													}
												}
											}
										}
									}

								}

							}

						}
					

					}
				}

			}
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << "  ";
					if (ground[a][a] == 0) cout << " -  ";
					else if (ground[a][b] == 1) cout << "O  ";
					else if (ground[a][b] == 2) cout << "X  ";
				}
				cout << endl;
			}
		}
	}

}
*/


// 8������ 3�� �ٽ�







// 9������ 4��
#include<iostream>
#include<string>
#include<iomanip>
#include<climits>


// �л� �Ѹ�� ���� �����ϱ� ���� ����ü 
typedef struct person {
	int num;
	int score[3]; // 3�� ���� ����
	int sum = 0;
	int max_score = INT_MIN; // �ְ�����
	int min_score = INT_MAX; // ��������
	float aver_score; // �������
	int grade = 1; // ��� - > ����� ���� �ű��
}student;



// ���� �ϳ��� ���� �����ϱ� ���� ����ü
typedef struct three_test {
	int sum = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	float aver;
}grade;


int main()
{
	using namespace std;
	student st[10];
	student *p = st;

	cout << st[0].sum;
	cout << p->sum;

	grade g[3];   // ����3��
	// �й�, �������� �ʱⰪ ����
	st[0] = { 1,{30,10,11} };
	st[1] = { 2,{40,90,32} };
	st[2] = { 3,{70,65,56} };
	st[3] = { 4,{70,43,32} };
	st[4] = { 5,{80,10,89} };

	// ���� 3�� ��� ó�� 
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 5; i++)
		{
			g[k].sum += st[i].score[k];
			if (g[k].max < st[i].score[k]) g[k].max = st[i].score[k];
			if (st[i].score[k] < g[k].min) g[k].min = st[i].score[k];
		}
		g[k].aver = g[k].sum / 5.0;
	}
	

	// �л� 5�� ��� ó�� (max,min,aver)
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			st[i].sum += st[i].score[k];
			if (st[i].max_score < st[i].score[k]) st[i].max_score = st[i].score[k];
			if (st[i].score[k] < st[i].min_score) st[i].min_score = st[i].score[k];
		}
		st[i].aver_score = (st[i].sum / 3.0);
	}


	// �л� ��� ó��
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (st[i].aver_score < st[k].aver_score) st[i].grade++;
		}
	}
	cout << fixed;
	// ����ϱ�
	cout << "    �й�  " << " ���� #1  " << "  ���� #2  " << "  ���� #3  " << "  �ְ�����  " << "  ��������  " << "  ���  " << "  ���  " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << left << setw(5);
		cout << "  " << st[i].num;
		for (int k = 0; k < 3; k++)
			cout <<setw(8)<<"    " << st[i].score[k];
		cout <<setw(11)<< "    " << st[i].max_score << setw(10)<<"    " << st[i].min_score << setw(6)<<
			setprecision(2)<<"    " << st[i].aver_score << setw(6)<< "    " << st[i].grade << "  "  << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int a = 0; a < 3; a++)
		{
			if (i == 0) {
				if (a == 0) { cout << "  �ְ�����  "; }
				cout << setw(2)<<"  " << g[a].max << "    ";
			}
			else if (i == 1) { 
				if (a == 0) { cout << "  ��������  "; }
				cout << setw(2)<<"  " << g[a].min << "    ";
			}
			else { 
				if(a==0){ cout << "  �������  "; }
				 cout <<"  " <<setprecision(2)<< g[a].aver<<" " ;
			}
		}
		cout << endl;
	}
}





/*
// 9������ 5��
#include<iostream>
#include<string>
int main()
{
	using namespace std;
	char text[100];
	int chart[26] = { 0 };
	cout << "���ڿ��� �Է��ϼ��� : ";
	cin.getline(text, 100);

	for (int k = 0; k < strlen(text); k++)
	{
		if (97 <= text[k] && text[k] <= 122 || 65 <= text[k] && text[k] <= 90) {
			if (isupper(text[k])) text[k] = tolower(text[k]);
			chart[text[k] - 97]++;
		}
	}
	for (int k = 0; k < 26; k++)
	{
		if (chart[k] != 0) cout << char(97+k) << " : " << chart[k] << endl;
	}
}
*/

