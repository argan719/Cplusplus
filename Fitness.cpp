#include "Fitness.h"
#include<iostream>
using namespace std;

double Fitness::weigh() {
	return weight;
}
void Fitness::init(int n, char *ap, double w) {
	num = n;
	strcpy(name, ap);
	weight = w;
}

void Fitness::prn()
{
	cout << "ȸ����ȣ : " << num << endl;
	cout << "�̸�  : " << name << endl;
	cout << "ü��  : " << weight << endl;
}