#ifndef _TEXTVIEW_H_
#define _TEXTVIEW_H_

#include <string>
#include <vector>
#include "View.hpp"

class Model;
class DeskComp;

class TextView: public View
{
	//View virtual functions
	public:
	void draw();
	void refresh();
	TextView(Model*);

	//TextView definition
	private:
	Model* model;
	std::vector<std::string> draw_text(DeskComp*);
};
#endif
