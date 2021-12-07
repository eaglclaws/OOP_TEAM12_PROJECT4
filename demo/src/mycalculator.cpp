#include <math.h>#include <math.h>#include <math.h>
#include "mycalculator.hpp"


mycalculator::mycalculator() {
	this->mystate = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->result = 0;
}

int mycalculator::size_x() {
	return my_size_x;
}

int mycalculator::size_y() {
	return my_size_y;
}

std::string mycalculator::name_str() {
	std::string name = "mycalculator";
	return name;
}

std::string mycalculator::display_str() {
	if (this->mystate == 0) {
		return "계산기";
	}
	else if (this->mystate == 1) {
		return "식을 입력해 주십시오";
	}
	else if (this->mystate == 2) {
		return std::to_string(this->result);
	}
}

std::string mycalculator::command_list() {
	std::string commands = "";
	commands.append("1. Select (write your expression)\n");
	commands.append("2. Exit");
	//1 이후 command_str로 식 받을예정
	return commands;
}

int mycalculator::get_state() {
	return mystate;
}

void mycalculator::command(int n) {
	switch (n) {
	case 1:
		mystate = 1;
		my_size_x = 20;
		my_size_y = 20;
		break;
	case 2:
		mystate = 0;
		my_size_x = 10;
		my_size_y = 10;
	}
}






void mycalculator::command_str(std::string s = "default") { //state = 0 -> 선택 x, state = 1 -> 선택(입력받는 state) state = 2 -> result제공하는 state
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
	this->mystate = 2;
}


