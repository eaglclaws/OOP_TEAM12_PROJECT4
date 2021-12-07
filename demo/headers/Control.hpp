#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "DeskComp.hpp"

class Control
{
	void init();
	void command(int);
	void refresh();
	void push(DeskComp);
};
#endif
