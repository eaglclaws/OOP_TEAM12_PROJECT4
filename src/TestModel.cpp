#include <iostream>
#include<vector>
#include "TestModel.hpp"
#include "DeskComp.hpp"

/*
TestModel();
vector<DeskComp> elements();

private:
	View* view;
	vector<DeskComp> ele;
	vector<int> compState;
}

*/

void TestModel::selectUpdate(int selectedDeskCompNum) {
	//선택 된 것 제외하고 전부 안보이게 설정
	for (int i = 0; i < ele.size(); i++) {
		if (i == selectedDeskCompNum) continue;
		compState(i) = 0;
	}
}

void TestModel::backUpdate(int selectedDeskCompNum) {
	//화면 뒤로 가서 다시 전부 보이게 설정
	for (int i = 0; i < ele.size(); i++) {
		compState(i) = 1;
	}
}



vector<DeskComp> TestModel::elements()
{
	return ele;
}

void TestModel::command_str(int cmdNum, string s)
{
	update(cmdNum);
	ele(cmdNum).command(s);
	
}

void TestModel::addDeskComp(DeskComp* deskcomp) {
	ele.push_back(deskcomp);
	compState.push_back(0);
}


TestModel::TestModel(View* view, vector<DeskComp> ele) {
	this->view = view;
	this->elements = ele;
}





