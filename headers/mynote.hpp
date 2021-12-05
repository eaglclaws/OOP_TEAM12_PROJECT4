#pragma once
#include "DeskComp.hpp"
#include <string>
#include <vector>
using namespace std;

class mynote : public DeskComp
{
public:
	mynote();
	int state();
	void command_str(std::string);
	int size_x();
	int size_y();
	std::string display_str();
private:
	std::string buffer;
	vector<string> mynotes;
	std::string commands[1] = { "terminate" }; //받아야 하는 string : terminate(노트 내려놓기), note에 적을 string
};
