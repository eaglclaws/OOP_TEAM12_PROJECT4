#include "mycalender.hpp"


mycalender::mycalender(int years, int months, int days) {
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->day = days;
	this->month = months; //오늘날짜로 초기화!
	this->year = years;
	this->state = 0;  //0 = 선택되지 않은 상태 , 1 = selected -> show
	this->getdayname();
	this->name = "calender";
};

int mycalender::size_x() {
	return this->my_size_x;
	//state에 따라 size가 달라질 수 있음
}

int mycalender::size_y() {
	return this->my_size_y;
	//state에 따라 size가 달라질 수 있음
}


std::string mycalender::name_str() {
	return "calender";
}

std::string mycalender::display_str() {
	std::string yearstring = to_string(this->year);
	std::string monthstring = to_string(this->month);
	std::string daystring = to_string(this->day);
	std::string output2 = "달력";
	if (this->state == 0) {
		return output2;
	}
	if (this->state == 1) {
		return yearstring + "." + monthstring + "." + daystring + "(" + this->dayname + ")";
	}
}

std::string mycalender::command_list() {
	std::string commands = "";
	commands.append("1. Select\n");
	commands.append("2. Update\n");
	commands.append("3. Exit");
	return commands;
}


int mycalender::get_state() {
	return this->state;
}

void mycalender::command(int n) {
	switch (n) {
	case 1:
		this->state = 1;
		this->my_size_x = 20;
		this->my_size_y = 20;
		break;
	case 2:
		this->day = this->day + 1;
		if (this->day > days[month - 1])
		{
			this->day = 1;
			if (this->month == 12) { this->month = 1; this->year = this->year + 1; this->isleapyear(); }
			else this->month = this->month + 1;
		}
		this->getdayname();
		break;
	case 3:
		this->state = 0;
		this->my_size_x = 10;
		this->my_size_y = 10;
	}

}


void mycalender::command_str(std::string s = "default") {

}


void mycalender::isleapyear() { //윤년 check이후 month_day 재설정
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
	int selected_day = (5 + total_day) % 7; //21년 1월 1일은 금요일
	this->dayname = day_of_week[selected_day];
}
