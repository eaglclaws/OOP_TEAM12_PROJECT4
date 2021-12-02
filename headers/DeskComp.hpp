#ifndef _DESKCOMP_H_
#define _DESKCOMP_H_
#include<string>
#include<stack>
#include<queue>
#include<vector>

class DeskComp
{
	public:
		int size_x();
		int size_y();
		virtual std::string display_str();
		virtual int state();
		virtual void command_str(std::string);
	protected:
		int state; 
		int my_size_x;
		int my_size_y;
};

class mycalculator : public DeskComp
{ 
public :
	mycalculator();
	void command_str(std::string);
	std::string display_str();
	int state();
	int size_x();
	int size_y();
private :
	std::string postfix;
	double result;
};



class mycalender : public DestkComp
{
public :
	mycalender(int,int,int);
	void command_str(std::string);
	std::string display_str();
	int state();
	int size_x();
	int size_y();
private:
	int year;
	int month;
	int day;
	std::string dayname;
	int[] days = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	std::string[] day_of_week = { "sun","mon","tue","wed","thu","fri","sat" };
	void isleapyear();
	void getdayname();
};

class mycandle : public DeskComp
{
public :
	mycandle();
	int state();
	void command_str(std::string);
	int size_x();
	int size_y();
	std::string display_str();
private :
	std::string liton;
	std::string litoff;
};

class mynote : public DeskComp
{
public:
	mynote();
	int state();
	void command_str(std::string);
	int size_x();
	int size_y();
	std::string display_str();
private:
	std::string buffer;
	vector<string> mynotes;
};




#endif
