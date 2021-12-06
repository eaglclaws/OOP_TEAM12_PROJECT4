#pragma once
#include "mycandle.hpp"

mycandle::mycandle() {
	this->state = 0;
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
	this->name = "candle";
}

int mycandle::size_x() {
	return my_size_x;
}

int mycandle::size_y() {
	return my_size_y;
}

std::string mycandle::name_str() {
	return name;
}

std::string mycandle::display_str() {
	if (this->state == 0) {
		return litoff;
	}
	else
		return liton;
}

std::string mycandle::command_list() {
	std::string commands = "";
	commands.append("1. Lit on\n");
	commands.append("2. Lit off\n");
	return commands;

}


int mycandle::get_state() {
	return this->state;
}

void mycandle::command(int n) {
	switch (n) {
	case 1:
		state = 1;
		break;
	case2:
		state = 0;
	}
}



void mycandle::command_str(std::string s = "default") {//light는 키고 끄기만 하면 된다.

}



