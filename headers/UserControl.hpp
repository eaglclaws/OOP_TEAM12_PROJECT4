#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "DeskComp.hpp"
#include "Control.hpp"

class UserControl
{
	UserControl::Control();
	void command(int);
	void refresh();
	void push(DeskComp);
};
#endif
