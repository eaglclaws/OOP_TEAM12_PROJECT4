#ifndef _DEBUGMODEL_H_
#define _DEBUGMODEL_H_

#include "Model.hpp"

class View;

class TestModel : public Model
{
	//Model virtual functions
public:
	void update();
	std::vector<DeskComp*> get_elements();
	void command(int);
	string command_list();
	//DebugModel Definition
private:
	View* view;
	std::vector<DeskComp*> elements;
	std::vector<DeskComp*> buffer;
	int state;
	
public:
	TestModel();
	~TestModel();
};
#endif