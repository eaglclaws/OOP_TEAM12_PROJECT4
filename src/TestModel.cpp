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
}

*/

void TestModel::update() {

}

vector<DeskComp> TestModel::elements()
{
	return ele;
}

void TestModel::command(int cmdNum)
{
	ele(cmdNum).command();
}

void TestModel::addDeskComp(DeskComp* deskcomp) {
	ele.push_back(deskcomp);
}


TestModel::TestModel(View* view, vector<DeskComp> ele) {
	this->view = view;
	this->elements = ele;
}





