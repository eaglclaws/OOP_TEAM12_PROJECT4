#include "DebugDeskComp.hpp"

//DeskComp virtual functions
int DebugDeskComp::size_x()
{
	return x;
}
int DebugDeskComp::size_y()
{
	return y;
}
std::string DebugDeskComp::name_str()
{
	return name;
}
std::string DebugDeskComp::display_str()
{
	std::string display = "";
	display.append(name);
	display.append("\n");
	display.append("Line1\n");
	display.append("Line2\n");
	display.append("Line3\n");
	display.append(name);
	return display;
}
std::string DebugDeskComp::command_str()
{
	std::string command_list = "";
	command_list.append("1. Grow\n");
	command_list.append("2. Shrink\n");
	command_list.append("3. Exit");
	return command_list;
}
int DebugDeskComp::get_state()
{
	return state;
}
void DebugDeskComp::command(int n)
{
	switch(n)
	{
		case 1 :
		state = 1;
		x += 1;
		y += 1;
		break;

		case 2 :
		state = 1;
		if (x > 1 && y > 1)
		{
			x -= 1;
			y -= 1;
		}
		break;

		case 3 :
		default :
		state = 0;
	}
}
//DebugDeskComp implementation
DebugDeskComp::DebugDeskComp(int n)
{
	name = "DebugItem" + std::to_string(n);
	x = 1;
	y = 1;
}
