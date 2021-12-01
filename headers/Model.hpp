#ifndef _MODEL_H_
#define _MODEL_H_
#include "DeskComp.hpp"
#include <vector>




class Model
{
public:
	virtual void update();
	virtual vector<DeskComp> elements();
	virtual void command(int cmdNum);
	virtual void addDeskComp(DeskComp deskcomp);
private:


};

#endif
