#include <iostream>
#include <sstream>
#include "TextView.hpp"
#include "DeskComp.hpp"

//Virtual functions from View.hpp
void TextView::draw()
{
	std::vector<std::vector<std::string>> lines;
	std::string display;
	for(std::vector<DeskComp>::iterator it = model->elements().begin(); it != model->elements().end(); it++)
	{
		lines.push_back(draw_text(*it));
	}
	bool able = true;
	int index = 0;
	int newline = 2;
	while(able)
	{
		able = false;
		for(std::vector<std::vector<std::string>>::iterartor it = lines.begin(); it != lines.end(); it++)
		{
			able = able || index < it->size();
			if(!(index < it->size())) continue;
			display.append(it->at(index));
		}
		index++;
	}
	std::cout << display << std::endl;
}
void TextView::refresh()
{
	draw();
}

//TextView implementation
//private
std::vector<std::string> TextView::draw_text(const DeskComp& component)
{
	int x = component.size_x();
	int y = component.size_y();
	int height = 0;
	int width = 0;
	std::stringstream s(component.display_string());
	std::string line;
	std::vector<std::string> out;
	std::vector<std::string> ret;
	std::string draw_out;
	while(std::getline(s, line))
	{
		out.push_back(line);
	}
	height = out.size();
	for(std::vector<std::string>::iterator it = out.begin(); it != out.end(); it++)
	{
		if(width < it->length()) width = it->length();
	}
	draw_out.push_back(this->corner); draw_out.append(width, this->horizontal); draw_out.push_back(this->corner);
	ret.push_back(draw_out);
	for(std::vector<std::string>::iterator it = out.begin(); it != out.end(); it++)
	{
		std::string draw_temp;
		int whitespaces = width - it->length();
		draw_temp.push_back(this->left_vert); draw_out.append(whitespaces/2, ' ');
		draw_temp.append(*it);
		draw_temp.append(whitespaces - whitespaces/2, ' '); draw_out.push_back(this->right_vert);
		ret.push_back(draw_out);
	}
	ret.push_back(draw_out);
	return ret;
}
//public
TextView::TextView(Model* model)
{
	this->model = model;
}
