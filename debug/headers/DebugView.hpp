#ifndef _DEBUGVIEW_H_
#define _DEBUGVIEW_H_

#include <string>
#include "View.hpp"
#include "Model.hpp"

class DeskComp;

class DebugView: public View
{
	//View virtual functions
	public:
	void draw();
	void refresh();
	
	//DebugView definition
	private:
	Model* model;
	std::string draw_string;
	std::string debug_info(DeskComp*);
	void build_draw_string();	

	public:
	DebugView(Model* model);
	~DebugView();
};
#endif
