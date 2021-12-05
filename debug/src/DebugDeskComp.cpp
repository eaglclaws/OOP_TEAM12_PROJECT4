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
std::string DebugDeskComp::command_list()
{
	std::string commands = "";
	commands.append("1. Grow\n");
	commands.append("2. Shrink\n");
	commands.append("3. Exit");
	return commands;
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
void DebugDeskComp::command_str(std::string) {}
//DebugDeskComp implementation
DebugDeskComp::DebugDeskComp(int n)
{
	name = "DebugItem" + std::to_string(n);
	x = 1;
	y = 1;
}
