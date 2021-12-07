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
	int max_lines = 0;
	int col = 5;
	for(int i = 0; i < objects.size(); i++) max_lines = max_lines < objects[i].size() ? objects[i].size() : max_lines;
	for(int i = 0; i < objects.size(); i+=col)
	{
		for(int j = 0; j < max_lines; j++)
		{
			for(int k = i; (k < i + col) && (k < objects.size()); k++)
			{
				if(j >= objects[k].size())
				{
					std::cout << std::string(objects[k][0].length(), ' ');
				}
				else
				{
					std::cout << objects[k][j];
				}
			}
			std::cout << std::endl;
		}
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
	std::istringstream iss(component->name_str());
	std::string h = "#";
	int max_len = 0;
	std::string line;
	while(std::getline(iss, line))
	{
		max_len = max_len < line.length() ? line.length() : max_len;
		return_vec.push_back("# " + line + " #");
	}
	h.append(max_len + 2, '=');
	h += "#";
	return_vec.insert(return_vec.begin(), h);
	return_vec.push_back(h);
	return return_vec;
}
//public
TextView::TextView(Model* model)
{
	this->model = model;
}
