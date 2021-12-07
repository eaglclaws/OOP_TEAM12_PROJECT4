#pragma once
#include "DeskComp.hpp"
#include <stack>

class mycalculator : public DeskComp
{
public:
	mycalculator();
	void command_str(std::string);
	std::string display_str();
	int state();
	int size_x();
	int size_y();
private:
	std::string postfix;
	double result;
	std::string commands[1] = { "terminate" }; //계산기는 식하고 terminate만 받으면 되요
};