
// - ������ - 
// 5������ 7��
// === Tv.h

#ifndef TV_H_
#define TV_H_

class Tv {
public:
	friend class Remote;  // Remote�� Tv�� private �κп� ������ �� �ִ�
	enum { Off, On };
	enum{MinVal,MaxVal = 20};
	enum{Antenna, Cable};
	enum{TV,DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;  // ��� ���������� ����Ѵ�
private:
	int state;		// on �Ǵ� off
	int volume;			// ������ �����̶�� �����Ѵ�
	int maxchannel;		// �ִ� ä�� ��
	int channel;		// ���� ������ ä��
	int mode;		// ������ ��� �Ǵ� ���̺� ���
	int input;		// TV�Է� �Ǵ� DVD �Է�
};

class Remote {
private:
	int mode;  // TV������ �Ǵ� DVD ������
public:
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv &t) { return t.volup(); }
	bool voldown(Tv &t) { return t.voldown(); }
	void onoff(Tv &t) { t.onoff(); }
	void chanup(Tv &t) { t.chanup(); }
	void chandown(Tv &t) { t.chandown(); }
	void set_chan(Tv &t, int c) { t.channel = c; }
	void set_mode(Tv &t) { t.set_mode(); }
	void set_input(Tv &t) { t.set_input(); }
};

#endif