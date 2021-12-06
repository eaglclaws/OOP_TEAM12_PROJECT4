#ifndef _TESTMODEL_H_
#define _TESTMODEL_H_
#include "Model.hpp"

#include <vector>


class TestModel : Model
{
public:
	void selectUpdate(); //선택 된 것 제외하고 전부 안보이게 설정
	void backUpdate();//화면 뒤로 가서 다시 전부 보이게 설정
	vector<DeskComp> elements();
	void command(int cmdNum);
	void addDeskComp(DeskComp deskcomp)

private:
	View* view;
	vector<DeskComp> ele;
	
	//DeskComp 의 각 요소들이 화면에 표시되어야 하는지 아닌지를 보여주는 vector
	//1일경우 보여줘야하고, 0일 경우 생략해야함.
	vector<int> compState;
}

#endif