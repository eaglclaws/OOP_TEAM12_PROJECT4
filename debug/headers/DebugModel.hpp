#ifndef _DEBUGMODEL_H_
#define _DEBUGMODEL_H_

#include "Model.hpp"

class View;

class DebugModel: Model
{
	//Model virtual functions
	public:
	void update();
	std::vector<DeskComp*> get_elements();
	void command(int);

	//DebugModel Definition
	private:
	View* view;
	std::vector<DeskComp*> elements;
	std::vector<DeskComp*> buffer;
	int state;

	public:
	DebugModel();
	~DebugModel();
};
#endif
