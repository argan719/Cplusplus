#ifndef FITNESS_H
#define FITNESS_H
class Fitness {
private:
	int num;		// ȸ����ȣ
	char name[20];  // �̸�
	double weight;  // ü��
public:
	void init(int n, char *ap, double w);  // �ʱ�ȭ �ɹ��Լ�
	double weigh();  // ü���� �����Ѵ�.
	void prn();  // ��ü�� ���� ���
};

#endif // !FITNESS_H
