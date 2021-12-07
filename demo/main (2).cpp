#include <iostream>
#include "DebugModel.hpp"

int main()
{
	std::cout << "\n======생성 테스트...=====\n";
	Model* model = new DebugModel();
	std::cout << "\n======...생성 테스트======\n";

	std::cout << "\n======commnad 테스트...======\n";
	model->command(1);
	std::cout << "\n======1번 요소 선택...=====\n";
	model->update();
	std::cout << "\n======불 켜기======\n";
	model->command(0);
	model->update();
	std::cout << "\n=====다시 전체 뷰=====\n";
	model->command(3);
	model->update();
}
