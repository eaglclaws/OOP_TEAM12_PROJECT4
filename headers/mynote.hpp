#pragma once
#include "DeskComp.hpp"
#include <string>
#include <vector>
using namespace std;

class mynote : public DeskComp
{
public:
	mynote();
	int size_x();
	int size_y();
	std::string name_str();
	std::string display_str();
	std::string command_list();
	int get_state();
	void command(int);
	void command_str(std::string);
private:
	std::string buffer;
	vector<string> mynotes;
	std::string commands[1] = { "terminate" }; //�޾ƾ� �ϴ� string : terminate(��Ʈ ��������), note�� ���� string
};
