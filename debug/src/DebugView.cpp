#include <iostream>
#include "DebugView.hpp"
#include "DebugModel.hpp"
#include "DebugDeskComp.hpp"

//View virtual functions
void DebugView::draw()
{
	std::cout << draw_string << std::endl;
}
void DebugView::refresh()
{
	build_draw_string();
	draw();
}

//DebugView definition
std::string DebugView::debug_info(DeskComp* it)
{
	std::string return_str = "===DeskComp Object Begin===\n";
	std::string size_x = std::to_string(it->size_x());
	std::string size_y = std::to_string(it->size_y());
	std::string state = std::to_string(it->get_state());
	std::string name = it->name_str();
	std::string display = it->display_str();
	std::string command = it->command_str();

	return_str += "(size_x, size_y) = (" + size_x + ", " + size_y + ")\n";
	return_str += "current_state = " + state + "\n";
	return_str += "name = " + name + "\n";
	return_str += "display_str start\n" + display + "\ndisplay_str end\n";
	return_str += "command_str start\n" + command + "\ncommand_str end\n";
	return_str += "===DeskComp Object End===\n"; 
	return return_str;
}
void DebugView::build_draw_string()
{
	std::vector<DeskComp*>::iterator it;
	std::string proto_draw_string = "===Debug View Begin===\n";
	//for(it = model->get_elements().begin(); it != model->get_elements().end(); it++)
	for(int i = 0; i < model->get_elements().size(); i++)
	{
		proto_draw_string += "\n";
		proto_draw_string += debug_info(model->get_elements()[i]);
		proto_draw_string += "\n";
	}
	
	proto_draw_string += "===Debug View End===\n";
	draw_string = proto_draw_string;
}
DebugView::DebugView(Model* model)
{
	this->model = model;
	draw_string = "";
}
DebugView::~DebugView() { }
