#ifndef CLASSES
#define CLASSES
#include <string>
#include <list>
class PassTicket {
protected:
	int sex;
	int year;
	int month;
	int day;
	std::string passticket = "";
public:
	virtual std::string pass_generate() = 0;
};

class PASS_MIEM : public PassTicket {
public:
	PASS_MIEM(int sex, int year, int month, int day) {
		this->sex   = (sex == 1) ? 8 : 4;
		this->year  = year;
		this->month = month;
		this->day   = day;
	}
	std::string pass_generate() override final;
};

class PASS_MGTU : public PassTicket {
public:
	PASS_MGTU(int sex, int year, int month, int day) {
		this->sex = sex;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	std::string pass_generate() override final;
};

void Help();
void GetResultFromConsole();
void GetResultFromConsole(const char * nametofile, bool is_name_file);
void GetResultFromFile(const char * namefromfile);
void GetResultFromFile(const char * namefromfile, const char * nametofile, bool is_name_file);
#endif