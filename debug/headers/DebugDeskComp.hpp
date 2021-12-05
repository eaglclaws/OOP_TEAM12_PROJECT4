#ifndef _DEBUGDESKCOMP_H_
#define _DEBUGDESKCOMP_H_

#include "DeskComp.hpp"

class DebugDeskComp: public DeskComp
{
	//DeskComp virtual functions
	public:
	int size_x();
	int size_y();
	std::string name_str();
	std::string display_str();
	std::string command_list();
	int get_state();
	void command(int n);
	void command_str(std::string);
	//DebugDeskComp definition
	private:
	int state;
	int x;
	int y;
	std::string name;
	std::string build_display();
	std::string list_commands();
	
	public:
	DebugDeskComp(int n);
};
#endif
