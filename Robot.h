class Robot {
private:
	char *name;  // �̸� ����
	int energy;  // �������� ����
	void err_prn();  // �����޽��� ���

public:
	void init(char *np, int e);		// �ʱ�ȭ �Լ�
	void go();  // ���� �Լ�
	void back();  // ���� �Լ�
	void turn();  // ȸ�� �Լ�
	void jump();  // ���� �Լ�
	void charge(int c);  // ���� �Լ�
};