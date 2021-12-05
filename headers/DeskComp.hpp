#ifndef _DESKCOMP_H_
#define _DESKCOMP_H_
#include<string>

class DeskComp
{
	public:
		virtual ~DeskComp() = default;
		virtual int size_x() = 0;
		virtual int size_y() = 0;
		virtual std::string name_str() = 0;
		virtual std::string display_str() = 0;
		virtual std::string command_str() = 0;
		virtual int get_state() = 0;
		virtual void command(int) = 0;
};

#endif
