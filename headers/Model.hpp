#ifndef _MODEL_H_
#define _MODEL_H_
#include <vector>
#include "DeskComp.hpp"

class Model
{
	public:
		virtual void update() = 0;
		virtual std::vector<DeskComp*> get_elements() = 0;
		virtual void command(int) = 0;
		virtual ~Model() = default;
};

#endif
