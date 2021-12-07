#include <iostream>
#include <sstream>
#include "TextView.hpp"
#include "DeskComp.hpp"
#include "Model.hpp"

//Virtual functions from View.hpp
void TextView::draw()
{
	std::vector<std::vector<std::string>> objects;
	for(int i = 0; i < model->get_elements().size(); i++)
	{
		objects.push_back(draw_text(model->get_elements()[i]));
	}
	for(int i = 0; i < objects.size(); i++)
	{
		std::string horizontal = "#";
		int max_len = 0;
		for(int j = 0; j < objects[i].size(); j++) max_len = max_len < objects[i][j].length() ? objects[i][j].length() : max_len;
		horizontal.append(max_len + 2, '-');
		horizontal += "#";
		std::cout << horizontal << std::endl;
		for(int j = 0; j < objects[i].size(); j++)
		{
			std::cout << "| " << objects[i][j] << " |" << std::endl;
		}
		std::cout << horizontal << std::endl;
	}
}
void TextView::refresh()
{
	draw();
}

//TextView implementation
//private
std::vector<std::string> TextView::draw_text(DeskComp* component)
{
	std::vector<std::string> return_vec;
	std::istringstream iss(component->display_str());
	std::string line;
	while(std::getline(iss, line))
	{
		return_vec.push_back(line);
	}
	return return_vec;
}
//public
TextView::TextView(Model* model)
{
	this->model = model;
}
