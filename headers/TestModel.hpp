#ifndef _TESTMODEL_H_
#define _TESTMODEL_H_
#include "Model.hpp"

#include <vector>


class TestModel : Model
{
public:
	void selectUpdate();
	vector<DeskComp> elements();
	void command(int cmdNum);
	void addDeskComp(DeskComp deskcomp)

private:
	View* view;
	vector<DeskComp> ele;
	
	//DeskComp �� �� ��ҵ��� ȭ�鿡 ǥ�õǾ�� �ϴ��� �ƴ����� �����ִ� vector
	//1�ϰ�� ��������ϰ�, 0�� ��� �����ؾ���.
	vector<int> compState;
}

#endif