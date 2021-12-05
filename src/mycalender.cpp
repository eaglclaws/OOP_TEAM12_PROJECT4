#include "mycalender.hpp"


mycalender::mycalender(int years, int months, int days) {
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->day = days;
	this->month = months; //���ó�¥�� �ʱ�ȭ!
	this->year = years;
	this->mystate = 0;  //0 = ���õ��� ���� ���� , 1 = selected -> show
	this->getdayname();
};

void mycalender::command_str(std::string s = "default") {
	//state = 0 -> non selected, 1 = selected
	if (this->mystate == 0) {
		if (s == "update") { //state �� 0�̰� argument�� i[date�϶� ��¥����
			this->day = this->day + 1;
			if (this->day > days[month + 1])
			{
				this->day = 1;
				if (this->month == 12) { this->month = 1; this->year = this->year + 1; this->isleapyear(); }
				else this->month = this->month + 1;
			}
			this->getdayname();
		}
		else this->mystate = 1;
		this->my_size_x = 20;
		this->my_size_y = 20;
	}
	else if (this->mystate == 1) {
		this->my_size_x = 10;
		this->my_size_y = 10;
		this->mystate = 0;
	}
}

int mycalender::size_x() {
	return this->my_size_x;
	//state�� ���� size�� �޶��� �� ����
}

int mycalender::size_y() {
	return this->my_size_y;
	//state�� ���� size�� �޶��� �� ����
}

std::string mycalender::display_str() {
	std::string yearstring = to_string(this->year);
	std::string monthstring = to_string(this->month);
	std::string daystring = to_string(this->day);
	std::string output2 = "�޷�";
	if (this->mystate == 0) {
		return output2;
	}
	if (this->mystate == 1) {
		return yearstring + "." + monthstring + "." + daystring + "(" + this->dayname + ")";
	}
}

int mycalender::state() {
	return this->mystate;
}



void mycalender::isleapyear() { //���� check���� month_day �缳��
	int yearcheck = this->year;
	if ((yearcheck % 4 == 0 && yearcheck % 100 != 0) || (yearcheck % 400 == 0))
		this->days[1] = 29;
	else this->days[1] = 28;
}

void mycalender::getdayname() {
	int total_day = 0;
	for (int i = 0; i < this->month; i++) {
		total_day = total_day + days[i - 1];
	}
	total_day = total_day + this->day - 1;
	int selected_day = (5 + total_day) % 7; //21�� 1�� 1���� �ݿ���
	this->dayname = day_of_week[selected_day];
}
