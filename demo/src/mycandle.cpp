#include "mycandle.hpp"

mycandle::mycandle() {
	this->mystate = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->liton = "***********-----\n***********   ll\n***********   ll\n              ll\n              ll\n              ll\n              ll\n      mmmmmmmmmm\n      mmmmmmmmmm\n";
	this->litoff = "ooooooooooo-----\nooooooooooo   ll\nooooooooooo   ll\n              ll\n              ll\n              ll\n              ll\n      mmmmmmmmmm\n      mmmmmmmmmm\n";
	//				***********-----       ooooooooooo-----
	//				***********   ll       ooooooooooo   ll
	//				              ll       ooooooooooo   ll
	//							  ll                     ll
	//							  ll                     ll
	//							  ll                     ll
	//					   mmmmmmmmmm            mmmmmmmmmm
	//					   mmmmmmmmmm            mmmmmmmmmm
	//					<liton>						<litoff>
	// '/n'Àº °³Çà¹®ÀÚ·Î ¾²ÀÎ°Ì´Ï´Ù!
}

int mycandle::get_state() {
	return this->mystate;
}



void mycandle::command_str(std::string s = "default") {//light´Â Å°°í ²ô±â¸¸ ÇÏ¸é µÈ´Ù.
	if (this->mystate == 0) {
		this->mystate = 1;
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
//오류 방지
std::string mycandle::name_str() { return "mycandle"; }
std::string mycandle::command_list() { return mystate == 0 ? "0. 켜짐\n" : "0. 꺼짐\n"; }
void mycandle::command(int) {}
mycandle::~mycandle() {}
