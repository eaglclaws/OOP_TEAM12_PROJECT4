#pragma once
#ifndef _DESKCOMP_H_
#define _DESKCOMP_H_
#include<string>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class DeskComp
{
public:
	virtual ~DeskComp() = default;
	virtual int size_x() = 0;
	virtual int size_y() = 0;
	virtual std::string name_str() = 0;
	virtual std::string display_str() = 0;
	virtual std::string command_list() = 0;
	virtual int get_state() = 0;
	virtual void command(int) = 0;
	virtual void command_str(std::string) = 0;

protected:
	int state;
	int my_size_x;
	int my_size_y;
	std::string name;
};


#endif