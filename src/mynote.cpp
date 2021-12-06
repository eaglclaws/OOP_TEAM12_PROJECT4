#include "mynote.hpp"


mynote::mynote() {
	this->state = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->name = "note";
}

int mynote::size_x() {
	return my_size_x;
}

int mynote::size_y() {
	return my_size_y;
}

std::string mynote::name_str() {
	return name;
}

std::string mynote::display_str() {
	if (this->state == 0) {
		std::string output = "��Ʈ";
		return output;
	}
	else if (this->state == 1) {
		std::string output = "";
		std::string lf = "/n";
		if (this->mynotes.empty()) {
			std::string emptyhandle = "��Ʈ�� ����ֽ��ϴ�!";
			return emptyhandle;
		}
		for (int i = 0; i < this->mynotes.size(); i++) {
			if (i == 0) {
				output.append(mynotes[i]);
				output.append("\n");
			}
		}
		return output; // ��� mynotes�� ����� string������ output�� �̾(�� ���� /n���� ���е�) ����
	}
	else if (this->state == 2) {
		std::string output = "���ο� note�� �Է��Ͻʽÿ�";
		return output;
	}
}

std::string mynote::command_list() {
	std::string commands = "";
	commands.append("1. Select\n");
	commands.append("2. Write\n");
	commands.append("3. Exit\n");
	return commands;
}

int mynote::get_state() {
	return this->state;
}

void mynote::command(int n) {
	switch (n) {
	case 1:
		state = 1;
		my_size_x = 20;
		my_size_y = 20;
		break;
	case 2:
		state = 2;
		break;
	case 3:
		state = 0;
		my_size_x = 10;
		my_size_y = 10;
		break;
	}
}



void mynote::command_str(std::string s = "default") { //0 = not selected, 1 = selected(show my notes), 2 = write mod(back to 1)
	this->mynotes.push_back(s); //���� ���� string�� �߰�.
	this->state = 1;//���� ���� state�� 1�� ������.
}
