#ifndef PRODUCT
#define PRODUCT

using namespace std;
#include<string>
class Product {
private:
	int id;
	string name;
	int price;
public:
	void input(int num, string n,int p);
	void print();
	bool isCheaper(Product other);
};

#endif // !PRODUCT

