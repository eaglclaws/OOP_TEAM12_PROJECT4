#ifndef _TESTMODEL_H_
#define _TESTMODEL_H_
#include "Model.hpp"

class View;

class TestModel: Model
{
	public:
	TestModel();
	vector<DeskComp> elements();

	private:
	View* view;
	vector<DeskComp> ele;
}

#endif
