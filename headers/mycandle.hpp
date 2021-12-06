#pragma once
#include "DeskComp.hpp"

class mycandle : public DeskComp
{
public:
	mycandle();
	int size_x();
	int size_y();
	std::string name_str();
	std::string display_str();
	std::string command_list();
	int get_state();
	void command(int);
	void command_str(std::string);
private:
	std::string liton;
	std::string litoff;
	std::string commands[1] = { "nop" }; //candle�� ���� �޾ƾ� �ϴ� �Ű������� �����
};
