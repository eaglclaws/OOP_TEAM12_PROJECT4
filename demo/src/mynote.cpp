#include "mynote.hpp"


mynote::mynote() {
	this->mystate = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
}

int mynote::state() {
	return this->mystate;
}

void mynote::command_str(std::string s = "default") { //0 = not selected, 1 = selected(show my notes), 2 = write mod(back to 1)
	if (this->mystate == 0) {
		this->mystate = 1;
	}
	else if (this->mystate == 1) {
		if (s == "terminate") this->mystate = 0; //note의 종료시 0으로
		else this->mystate = 2;
	}
	else if (this->mystate == 2) {//note의 write mode
		this->mynotes.push_back(s); //새로 받은 string의 추가.
		this->mystate = 1;//갱신 이후 state를 1로 돌린다.
	}
}

int mynote::size_x() {
	return this->my_size_x;
}

int mynote::size_y() {
	return this->my_size_y;
}

std::string mynote::display_str() {
	if (this->mystate == 0) {
		std::string output = "노트";
		return output;
	}
	else if (this->mystate == 1) {
		std::string output = "";
		std::string lf = "/n";
		if (this->mynotes.empty()) {
			std::string emptyhandle = "노트가 비어있습니다!";
			return emptyhandle;
		}
		for (int i = 0; i < this->mynotes.size(); i++) {
			if (i == 0) {
				output = output + this->mynotes[i];
			}
			else output = output + lf + this->mynotes[i];
		}
		return output; // 모든 mynotes에 저장된 string정보를 output에 이어서(각 줄은 /n으로 구분됨) 제공
	}
	else if (this->mystate == 2) {
		std::string output = "새로운 note를 입력하십시오";
		return output;
	}
}