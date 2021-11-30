#ifndef _DESKCOMP_H_
#define _DESKCOMP_H_
#include<string>

class DeskComp
{
	public:
		virtual int size_x();
		virtual int size_y();
		virtual std::string display_str();
		virtual int state();
		virtual void command();
};

#endif
