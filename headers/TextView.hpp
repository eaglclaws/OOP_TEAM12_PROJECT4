#ifndef _TEXTVIEW_H_
#define _TEXTVIEW_H_

#include <string>

class Model;
class DeskComp;

class TextView: View
{
	//View virtual functions
	public:
	void draw();
	void refresh();

	//TextView definition
	private:
	Model* model;
	std::string draw_text(const DeskComp&);
};
#endif
