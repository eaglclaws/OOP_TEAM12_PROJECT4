#ifndef _MODEL_H_
#define _MODEL_H_
#include "DeskComp.hpp"
#include <vector>




class Model
{
public:
	virtual void selectUpdate();
	virtual void backUpdate();//화면 뒤로 가서 다시 전부 보이게 설정
	virtual vector<DeskComp> elements();
	virtual void command(int cmdNum);
	virtual void addDeskComp(DeskComp deskcomp);
private:


};

#endif
