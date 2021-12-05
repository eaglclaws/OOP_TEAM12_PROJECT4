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
	int size_x();
	int size_y();
	virtual std::string display_str() = 0;
	virtual int state() = 0;
	virtual void command_str(std::string) = 0;
protected:
	int mystate;
	int my_size_x;
	int my_size_y;
};


#endif
