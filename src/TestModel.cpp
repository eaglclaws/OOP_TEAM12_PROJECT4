#include "TestModel.hpp"
#include "TextView.hpp"
#include "mycandle.hpp"
#include "Model.hpp"

//Model virtual functions
void TestModel::update()
{
	view->refresh();
}


std::vector<DeskComp*> TestModel::get_elements()
{
	if (state == 0) return elements;
	else
	{
		buffer.clear();;
		buffer.push_back(elements[state - 1]);
		return buffer;
	}
}
void TestModel::command(int n)
{
	if (n > elements.size()) {
		state = 0;
	}
	else if (state == 0) state = n;
	else {
		elements[state - 1]->command(n);
		elements[state - 1]->command_str("");
		if (elements[state - 1]->get_state() == 0) state = 0;
	}
	

}


string TestModel::command_list(){
	string s = "| ";
	if (state > elements.size()) {
		for (int i = 0; i < elements.size(); i++) {
			s += elements[i]->name_str();
			s += " | ";
		}
	}
	else {
		s = elements[state]->name_str();

	}
	return s;
}


//DebugModel implementation
TestModel::TestModel()
{
	view = new TextView(this);
	int i;
	for (i = 0; i < 2; i++)
	{
		elements.push_back(new mycandle());
	}
	state = 0;
	update();
}
TestModel::~TestModel()
{
	delete view;
}
