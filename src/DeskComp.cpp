#include "DeskComp.hpp"
#include <stack>
#include <cctype>
#include <cmath>


mycalender::mycalender(int dat, int month, int year) {
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->day = day;
	this->month = month; //오늘날짜로 초기화!
	this->year = year;
	this->state = 0;  //0 = 선택되지 않은 상태 , 1 = selected -> show
	this->getdayname();
};

void mycalender::command_str(std::string s) {
	//state = 0 -> non selected, 1 = selected
	if (this->state == 0) {
		if (s == "update") { //state 가 0이고 argument가 i[date일때 날짜갱신
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
	//state에 따라 size가 달라질 수 있음
}

int mycalender::size_y() {
	return this->my_size_y;
	//state에 따라 size가 달라질 수 있음
}

int mycalender::states() {
	//return this->state;
}

std::string mycalender::display_str() {
	std::string days = "  day : " + this->day;
	std::string months = "  month : " + this->month;
	std::string years = "year : " + this->year;
	std::string output = years + months + days;
	std::string output2 = "달력";
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



void mycalender::isleapyear() { //윤년 check이후 month_day 재설정
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
	int selected_day = (5 + total_day) % 7; //21년 1월 1일은 금요일
	this->dayname = day_of_week[selected_day];
}
















mycalculator::mycalculator() {
	this->state = 0;
	this->my_size_x = 10;
	this->my_size_y = 10;
	this->result = 0;
}



void mycalculator::command_str(std::string s) { //state = 0 -> 선택 x, state = 1 -> 선택(입력받는 state) state = 2 -> result제공하는 state
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
		if (s == "terminate") { //계산기 종료
			this->state = 0;
			this->my_size_x = 10;
			this->my_size_y = 10;
		}
		else //계산기 유지
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
		return "계산기";
	}
	else if (this->state == 1) {
		return "식을 입력해 주십시오";
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
	// '/n'은 개행문자로 쓰인겁니다!
}

int mycandle::state() {
	return this->state;
}



void command_str(std::string s) {//light는 키고 끄기만 하면 된다.
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
		if (s == "terminate") this->state == 0; //note의 종료시 0으로
		else this->state == 2;
	}
	else if (this->state == 2) {//note의 write mode
		this->mynotes.push_back(s); //새로 받은 string의 추가.
		this->state == 1;//갱신 이후 state를 1로 돌린다.
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
		std::string output = "노트";
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
		return output; // 모든 mynotes에 저장된 string정보를 output에 이어서(각 줄은 /n으로 구분됨) 제공
	}
	else if (this->state == 2) {
		std::string output = "새로운 note를 입력하십시오";
		return output;
	}
}