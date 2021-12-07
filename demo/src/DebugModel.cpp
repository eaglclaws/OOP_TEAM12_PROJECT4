#include "DebugModel.hpp"
#include "TextView.hpp"
#include "mycandle.hpp"
#include "mycalender.hpp"
#include "mynote.hpp"
#include "mycalculator.hpp"

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
		//elements[state - 1]->command_str("");
		if(elements[state - 1]->get_state() == 0) state = 0;
	}
}

//DebugModel implementation
DebugModel::DebugModel()
{
	view = new TextView(this);
	int i;
	//for(i = 0; i < 14; i++)
	//{
	//	elements.push_back(new mycandle());
	//}
	elements.push_back(new mycalculator());
	elements.push_back(new mycalender(2021, 12, 7));
	elements.push_back(new mynote());
	elements.push_back(new mycandle());
	state = 0;
	update();
}
DebugModel::~DebugModel()
{
	delete view;
}
