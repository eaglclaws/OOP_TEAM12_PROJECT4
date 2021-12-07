
#include "mycandle.hpp"

mycandle::mycandle() {
	this->mystate = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->liton = "";
	liton.append("***********-----\n");
	liton.append("***********   ll\n");
	liton.append("***********   ll\n");
	liton.append("              ll\n");
	liton.append("              ll\n");
	liton.append("              ll\n");
	liton.append("              ll\n");
	liton.append("      mmmmmmmmmm\n");
	liton.append("      mmmmmmmmmm\n");
	this->litoff = "";
	litoff.append("ooooooooooo-----\n");
	litoff.append("ooooooooooo   ll\n");
	litoff.append("ooooooooooo   ll\n");
	litoff.append("              ll\n");
	litoff.append("              ll\n");
	litoff.append("              ll\n");
	litoff.append("              ll\n");
	litoff.append("      mmmmmmmmmm\n");
	litoff.append("      mmmmmmmmmm\n");
}

int mycandle::size_x() {
	return my_size_x;
}

int mycandle::size_y() {
	return my_size_y;
}

std::string mycandle::name_str() {
	std::string name = "mycandle";
	return name;
}

std::string mycandle::display_str() {
	if (this->mystate == 0) {
		return "candle";
	}
	else if (this->mystate == 1) {
		return litoff;
	}
	else if (this->mystate == 2) {
		return liton;
	}
}

std::string mycandle::command_list() {
	std::string commands = "";
	commands.append("1. Select\n");
	commands.append("2. Lit on\n");
	commands.append("3. Lit off\n");
	commands.append("4. Exit\n");
	return commands;

}


int mycandle::get_state() {
	return this->mystate;
}

void mycandle::command(int n) {
	switch (n) {
	case 1:
		mystate = 1;
		my_size_x = 20;
		my_size_y = 20;
		break;
	case 2:
		mystate = 2;
		break;
	case 3:
		mystate = 1;
		break;
	case 4:
		mystate = 0;
		my_size_x = 10;
		my_size_y = 10;
		break;
	}
}



void mycandle::command_str(std::string s = "default") {//light는 키고 끄기만 하면 된다.

}



