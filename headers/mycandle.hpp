#pragma once
#include "DeskComp.hpp"

class mycandle : public DeskComp
{
public:
	mycandle();
	int state();
	void command_str(std::string);
	int size_x();
	int size_y();
	std::string display_str();
private:
	std::string liton;
	std::string litoff;
	std::string commands[1] = { "nop" }; //candle은 딱히 받아야 하는 매개변수는 없어요
};
