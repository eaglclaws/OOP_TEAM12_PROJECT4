#include "DebugModel.hpp"
#include "DebugView.hpp"
#include "DebugDeskComp.hpp"

//Model virtual functions
void DebugModel::update()
{
	view->refresh();
}
std::vector<DeskComp*> DebugModel::get_elements()
{
	if(state == 0) return elements;
	else
	{
		buffer.clear();;
		buffer.push_back(elements[state - 1]);
		return buffer;
	}
}
void DebugModel::command(int n)
{
	if(n > elements.size()) state = 0;
	else if(state == 0) state = n;
	else
	{
		elements[state - 1]->command(n);
		if(elements[state - 1]->get_state() == 0) state = 0;
	}
}

//DebugModel implementation
DebugModel::DebugModel()
{
	view = new DebugView(this);
	int i;
	for(i = 0; i < 3; i++)
	{
		elements.push_back(new DebugDeskComp(i));
	}
	state = 0;
	update();
}
DebugModel::~DebugModel()
{
	delete view;
}
