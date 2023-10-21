/*
#ifndef CALCULATOR
#define CALCULATOR

class Calculator {
	int op1, op2;
public:
	Calculator();
	Calculator(int a, int b);
	int run(int x, int y);
};
#endif // !CALCULATOR

*/

#ifndef CALCULATOR
#define CALCULATOR

class Calculator {
	int x, y;
	char op;
	int result;
public:
	void set(int a, int b, char o);
	int process();
};


#endif // !CALCULATOR
