#ifndef _MODEL_H_
#define _MODEL_H_
#include <vector>
#include "DeskComp.hpp"

class Model
{
	public:
		virtual void update();
		virtual vector<DeskComp> elements();
		virtual void command(int);
};

#endif
