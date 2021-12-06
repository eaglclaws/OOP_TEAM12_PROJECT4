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
	//���� �� �� �����ϰ� ���� �Ⱥ��̰� ����
	for (int i = 0; i < ele.size(); i++) {
		if (i == selectedDeskCompNum) continue;
		compState(i) = 0;
	}
}

void TestModel::backUpdate(int selectedDeskCompNum) {
	//ȭ�� �ڷ� ���� �ٽ� ���� ���̰� ����
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





