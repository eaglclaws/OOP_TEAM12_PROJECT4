#include "DeskComp.hpp"
#include <stack>
#include <cctype>
#include <cmath>


mycalender::mycalender(int dat, int month, int year) {
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->day = day;
	this->month = month; //���ó�¥�� �ʱ�ȭ!
	this->year = year;
	this->state = 0;  //0 = ���õ��� ���� ���� , 1 = selected -> show
	this->getdayname();
};

void mycalender::command_str(std::string s) {
	//state = 0 -> non selected, 1 = selected
	if (this->state == 0) {
		if (s == "update") { //state �� 0�̰� argument�� i[date�϶� ��¥����
			this->day = this->day + 1;
			if (this->day > days[month + 1])
			{
				this->day = 1;
				if (this->month == 12) { this->month = 1; this->year = this->year + 1; this->isleapyear(); }
				else this->month = this->month + 1;
			}
			this->getdayname();
		}
		else this->state = 1;
		this->my_size_x - = 20;
		this->my_size_y = 20;
	}
	else if (this->state == 1) {
		this->my_size_x = 10;
		this->my_size_y = 10;
		this->state = 0;
	}
}

int mycalender::size_x() {
	return this->my_size_x;
	//state�� ���� size�� �޶��� �� ����
}

int mycalender::size_y() {
	return this->my_size_y;
	//state�� ���� size�� �޶��� �� ����
}

int mycalender::states() {
	//return this->state;
}

std::string mycalender::display_str() {
	std::string days = "  day : " + this->day;
	std::string months = "  month : " + this->month;
	std::string years = "year : " + this->year;
	std::string output = years + months + days;
	std::string output2 = "�޷�";
	if (this->state == 0) {
		return output2;
	}
	if (this->state == 1) {
		return output;
	}
}

int mycalender::state() {
	return this->state;
}



void mycalender::isleapyear() { //���� check���� month_day �缳��
	int yearcheck = this->year;
	if ((yearcheck % 4 == 0 && yearcheck % 100 != 0) || (yearcheck % 400 == 0))
		this->days[1] = 29;
	else this->days[1] = 28;
}

void mycalender::getdayname() {
	int total_day = 0;
	for (int i = i; i < this->month; i++) {
		total_day = total_day + days[i - 1];
	}
	total_day = total_day + this->day - 1;
	int selected_day = (5 + total_day) % 7; //21�� 1�� 1���� �ݿ���
	this->dayname = day_of_week[selected_day];
}
















mycalculator::mycalculator() {
	this->state = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->result = 0;
}



void mycalculator::command_str(std::string s) { //state = 0 -> ���� x, state = 1 -> ����(�Է¹޴� state) state = 2 -> result�����ϴ� state
	stack<char> calstack;
	stack<double> numstack;
	double answer = 0;
	double root = 0;
	double a, b;
	if (this->state == 0) {
		state = state + 1;
		this->my_size_x = 20;
		this->my_size_y = 20;
	}
	else if (this->state == 1) {
		this->state = 2;
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
	}
	else if (this->state == 2) {
		if (s == "terminate") { //���� ����
			this->state = 0;
			this->my_size_x = 10;
			this->my_size_y = 10;
		}
		else //���� ����
			this->state = 1;
	}
}


int mycalculator::size_x() {
	return my_size_x;
}

int mycalculator::size_y() {
	return my_size_y;
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

int mycalander::state() {
	return this->state;
}


mycandle::mycandle() {
	this->state = 0;
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
	// '/n'�� ���๮�ڷ� ���ΰ̴ϴ�!
}

int mycandle::state() {
	return this->state;
}



void command_str(std::string s) {//light�� Ű�� ���⸸ �ϸ� �ȴ�.
	if (this->state == 0) {
		this->state == 1;
	}
	else {
		this->state = 0;
	}
}




int mycandle::size_x() {
	return this->my_size_x;
}

int mycandle::size_y() {
	return this->my_size_y;
}

std::string mycandle::display_str() {
	if (this->state == 0) {
		return litoff;
	}
	else
		return liton;
}




mynote::mynote() {
	this->state = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
}

int mynote::state() {
	return this->state;
}

void command_str(std::string s) { //0 = not selected, 1 = selected(show my notes), 2 = write mod(back to 1)
	if (this->state == 0) {
		this->state = 1;
	}
	else if (this->state == 1) {
		if (s == "terminate") this->state == 0; //note�� ����� 0����
		else this->state == 2;
	}
	else if (this->state == 2) {//note�� write mode
		this->mynotes.push_back(s); //���� ���� string�� �߰�.
		this->state == 1;//���� ���� state�� 1�� ������.
	}
}

int mynote::size_x() {
	return this->my_size_x;
}

int mynote::size_y() {
	return this->my_size_y;
}

std::string mynote::display_str() {
	if (this->state == 0) {
		std::string output = "��Ʈ";
		return output;
	}
	else if (this->state == 1) {
		std::string output = "";
		std::string lf = "/n";
		for (int i = 0; i < this->mynotes.size(); i++) {
			if (i == 0) {
				output = output + this->mynotes[i];
			}
			else output = output + lf + this->mynotes[i];
		}
		return output; // ��� mynotes�� ����� string������ output�� �̾(�� ���� /n���� ���е�) ����
	}
	else if (this->state == 2) {
		std::string output = "���ο� note�� �Է��Ͻʽÿ�";
		return output;
	}
}