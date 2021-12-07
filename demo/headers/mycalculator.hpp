#pragma once
#include "DeskComp.hpp"
#include <stack>

class mycalculator : public DeskComp
{
public:
	mycalculator();
	int size_x();
	int size_y();
	std::string name_str();
	std::string display_str();
	std::string command_list();
	int get_state();
	void command(int);
	void command_str(std::string);
private:
	std::string postfix;
	double result;
};