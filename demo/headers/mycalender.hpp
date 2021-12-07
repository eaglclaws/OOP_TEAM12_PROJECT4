#pragma once
#include "DeskComp.hpp"

class mycalender : public DeskComp
{
public:
	mycalender(int, int, int);
	void command_str(std::string);
	std::string display_str();
	int state();
	int size_x();
	int size_y();
private:
	int year;
	int month;
	int day;
	std::string dayname;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	std::string day_of_week[7] = { "sun","mon","tue","wed","thu","fri","sat" };
	void isleapyear();
	void getdayname();
	std::string commands[1] = { "update" }; //update = calender�� ��¥����
};