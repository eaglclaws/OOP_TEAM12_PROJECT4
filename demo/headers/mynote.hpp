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
	std::string commands[1] = { "terminate" }; //�޾ƾ� �ϴ� string : terminate(��Ʈ ��������), note�� ���� string
};
