#ifndef _TESTMODEL_H_
#define _TESTMODEL_H_
#include "Model.hpp"

#include <vector>


class TestModel : Model
{
public:
	void update();
	vector<DeskComp> elements();
	void command(int cmdNum);
	void addDeskComp(DeskComp deskcomp)

private:
	View* view;
	vector<DeskComp> ele;

}

#endif