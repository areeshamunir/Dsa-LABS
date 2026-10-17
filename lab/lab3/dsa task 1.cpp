#include<iostream>
using namespace std;
class course {
public:
	virtual void duration() = 0;
};

class onlinecourse : public course {
	int weeks, hoursperweek;
public:
	onlinecourse(int w, int h) {
		weeks = w;
		hoursperweek = h;
	}

	void duration() override {
		cout << "online class duration:" << weeks + hoursperweek << "hours" << endl;
	}
};

class  offlinecourse : public course {
	int months, hoursperday;
public:
	offlinecourse(int m, int h) {
		months = m;
		hoursperday = h;
	}

	void duration() override {
		cout << "offline class duration:" << months * 30 * hoursperday << "hours" << endl;
	}
};
  int main() {
	  onlinecourse online(6, 4);
	  offlinecourse offline(2, 1);

	  online.duration();
	  offline.duration();

	  return 0;


};
