
// - 프렌드 - 
// 5페이지 7번
// === Tv.h

#ifndef TV_H_
#define TV_H_

class Tv {
public:
	friend class Remote;  // Remote는 Tv의 private 부분에 접근할 수 있다
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
	void settings() const;  // 모든 설정값들을 출력한다
private:
	int state;		// on 또는 off
	int volume;			// 디지털 볼륨이라고 가정한다
	int maxchannel;		// 최대 채널 수
	int channel;		// 현재 설정된 채널
	int mode;		// 지상파 방송 또는 케이블 방송
	int input;		// TV입력 또는 DVD 입력
};

class Remote {
private:
	int mode;  // TV조정기 또는 DVD 조정기
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