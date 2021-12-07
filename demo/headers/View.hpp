#ifndef _VIEW_H_
#define _VIEW_H_
class View
{
	public:
		virtual void draw() = 0;
		virtual void refresh() = 0;
		virtual ~View() = default;
};
#endif
