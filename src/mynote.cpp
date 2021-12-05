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
		if (s == "terminate") this->mystate = 0; //note�� ����� 0����
		else this->mystate = 2;
	}
	else if (this->mystate == 2) {//note�� write mode
		this->mynotes.push_back(s); //���� ���� string�� �߰�.
		this->mystate = 1;//���� ���� state�� 1�� ������.
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
		std::string output = "��Ʈ";
		return output;
	}
	else if (this->mystate == 1) {
		std::string output = "";
		std::string lf = "/n";
		if (this->mynotes.empty()) {
			std::string emptyhandle = "��Ʈ�� ����ֽ��ϴ�!";
			return emptyhandle;
		}
		for (int i = 0; i < this->mynotes.size(); i++) {
			if (i == 0) {
				output = output + this->mynotes[i];
			}
			else output = output + lf + this->mynotes[i];
		}
		return output; // ��� mynotes�� ����� string������ output�� �̾(�� ���� /n���� ���е�) ����
	}
	else if (this->mystate == 2) {
		std::string output = "���ο� note�� �Է��Ͻʽÿ�";
		return output;
	}
}