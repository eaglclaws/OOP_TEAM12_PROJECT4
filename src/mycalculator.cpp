#pragma once
#include "mycalculator.hpp"


mycalculator::mycalculator() {
	this->state = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->result = 0;
	this->name = "calculator";
}

int mycalculator::size_x() {
	return my_size_x;
}

int mycalculator::size_y() {
	return my_size_y;
}

std::string mycalculator::name_str() {
	return name;
}

std::string mycalculator::display_str() {
	if (this->state == 0) {
		return "����";
	}
	else if (this->state == 1) {
		return "���� �Է��� �ֽʽÿ�";
	}
	else if (this->state == 2) {
		return std::to_string(this->result);
	}
}

std::string mycalculator::command_list() {
	std::string commands = "";
	commands.append("1. Select\n");
	commands.append("2. Exit");
	//1 ���� command_str�� �� ��������
	return commands;
}

int mycalculator::get_state() {
	return state;
}

void mycalculator::command(int n) {
	switch (n) {
	case 1:
		state = 1;
		my_size_x = 20;
		my_size_y = 20;
		break;
	case 2:
		state = 0;
		my_size_x = 10;
		my_size_y = 10;
	}
}






void mycalculator::command_str(std::string s = "default") { //state = 0 -> ���� x, state = 1 -> ����(�Է¹޴� state) state = 2 -> result�����ϴ� state
	stack<char> calstack;
	stack<double> numstack;
	double answer = 0;
	double root = 0;
	double a, b;
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i])) {
			if (i != 0 && isdigit(s[i - 1])) {
				this->postfix.pop_back();
			}
			this->postfix.push_back(s[i]);
			this->postfix.push_back(' ');
		}
		else {
			if (s[i] == '(') {
				calstack.push(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!calstack.empty() && (calstack.top() == '*' || calstack.top() == '/'))
				{
					this->postfix.push_back(calstack.top());
					this->postfix.push_back(' ');
					calstack.pop();
				}
				calstack.push(s[i]);
			}
			else if (s[i] == ')') {
				while (!calstack.empty() && calstack.top() != '(') {
					this->postfix.push_back(calstack.top());
					this->postfix.push_back(' ');
					calstack.pop();
				}
				calstack.pop();
			}
			else if (s[i] == '+' || s[i] == '-') {
				while (!calstack.empty() && calstack.top() != '(') {
					this->postfix.push_back(calstack.top());
					this->postfix.push_back(' ');
					calstack.pop();
				}
				calstack.push(s[i]);
			}
		}
	}
	while (!calstack.empty()) {
		this->postfix.push_back(calstack.top());
		this->postfix.push_back(' ');
		calstack.pop();
	}
	for (int i = 0; i < this->postfix.length(); i++) {
		if (isdigit(this->postfix[i])) {
			int checker = i;
			while (isdigit(postfix[i]))
			{
				i = i + 1;
			}
			i = i - 1;
			int diff = i - checker;
			for (diff; diff != 0; diff--) {
				double num = postfix[i - diff] - '0';
				root = root + num * pow(10, diff);
			}
			root = root + (postfix[i] - '0');
			numstack.push(root);
			root = 0;
		}
		else if (postfix[i] == ' ')continue;
		else {
			a = numstack.top();
			numstack.pop();
			b = numstack.top();
			numstack.pop();
			switch (postfix[i]) {
			case '+':
				answer = b + a;
				numstack.push(answer);
				break;
			case '-':
				answer = b - a;
				numstack.push(answer);
				break;
			case '*':
				answer = b * a;
				numstack.push(answer);
				break;
			case '/':
				answer = b / a;
				numstack.push(answer);
				break;
			}
		}
	}
	this->result = answer;
	this->state = 2;
}


