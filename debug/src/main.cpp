#include "DebugModel.hpp"
#include <iostream>

int main()
{
	DebugModel model = DebugModel();
	std::cout << "===Command Test Begin===\n";
	std::cout << "Enter Command = 2, Expected Behavior: Only Display DebugItem2\n";
	std::cout << "[Model State = 2]\n\n";
	model.command(2);
	model.update();
	std::cout << "Enter Command = 1, Expected Behavior: DebugItem2 (size_x, size_y) = (2, 2)\n";
	std::cout << "[Model state = 2, DebugItem2 state = 1]\n\n";
	model.command(1);
	model.update();
	std::cout << "Enter Command = 3, Expected Behavior: Display all DebugItems again\n";
	std::cout << "[Model state = 0, DebugItem2 state = 0]\n\n";
	model.command(3);
	model.update();
	std::cout << "===Command Test End===\n";
}
