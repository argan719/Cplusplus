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
	cout << "회원번호 : " << num << endl;
	cout << "이름  : " << name << endl;
	cout << "체중  : " << weight << endl;
}