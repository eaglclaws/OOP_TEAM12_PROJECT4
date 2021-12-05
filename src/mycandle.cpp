#pragma once
#include "mycandle.hpp"

mycandle::mycandle() {
	this->mystate = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->liton = "***********-----/n***********   ll/n***********   ll/n              ll/n              ll\n              ll/n              ll/n      mmmmmmmmmm/n      mmmmmmmmmm/n";
	this->litoff = "ooooooooooo-----/nooooooooooo   ll/nooooooooooo   ll/n              ll/n              ll/n              ll/n              ll/n      mmmmmmmmmm/n      mmmmmmmmmm/n";
	//				***********-----       ooooooooooo-----
	//				***********   ll       ooooooooooo   ll
	//				              ll       ooooooooooo   ll
	//							  ll                     ll
	//							  ll                     ll
	//							  ll                     ll
	//					   mmmmmmmmmm            mmmmmmmmmm
	//					   mmmmmmmmmm            mmmmmmmmmm
	//					<liton>						<litoff>
	// '/n'은 개행문자로 쓰인겁니다!
}

int mycandle::state() {
	return this->mystate;
}



void mycandle::command_str(std::string s = "default") {//light는 키고 끄기만 하면 된다.
	if (this->mystate == 0) {
		this->mystate == 1;
	}
	else {
		this->mystate = 0;
	}
}




int mycandle::size_x() {
	return this->my_size_x;
}

int mycandle::size_y() {
	return this->my_size_y;
}

std::string mycandle::display_str() {
	if (this->mystate == 0) {
		return litoff;
	}
	else
		return liton;
}

