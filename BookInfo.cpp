#include "BookInfo.h"
#include<QString>



BookInfo::BookInfo()
{
}

BookInfo::BookInfo(string name,int num,int h,int r,MyTime st,MyTime ed,Data * d)
{
    this->name=QString::fromStdString(name);
    this->num=num;
    this->room=d->pos_to_ptr(h,r);
    this->start_time=st;
    this->end_time=ed;
    this->price=(ed-st)*this->room->get_price();
}

BookInfo::~BookInfo()
{
}

bool operator < (const MyTime &a, const MyTime &b) {
	return a.year < b.year || a.month < b.month && a.year == b.year || a.day < b.day && a.month == b.month && a.year == b.year;
}
bool operator == (const MyTime &a, const MyTime &b) {
	return a.year == b.year && a.month == b.month && a.day == b.day;
}
bool operator <= (const MyTime &a, const MyTime &b) {
	return a<b || a==b;
}

int operator - (const MyTime &a, const MyTime & b) {
	int ans = 0;
	auto check_year = [](int i)->bool {return i % 4 == 0 && i % 100 != 0 || i % 400 == 0; };
	for (int i = b.year; i <= a.year - 1; i++) {
		if (check_year(i)) {
			ans += 366;
		}
		else {
			ans += 365;
		}
	}

	auto cal_day = [=](int year, int mon, int day)->int {
		int d[13]{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (check_year(year)) d[2] = 29;
		int res = 0;
		for (int i = 1; i < mon; i++) {
			res += d[i];
		}
		res += day;
		return res;
	};
	ans = ans + cal_day(a.year, a.month, a.day) - cal_day(b.year, b.month, b.day);
	return ans;
}


MyTime::MyTime(const string & s)
{
	this->year = this->day = this->month = 0;
	int i = 0;
	while (isdigit(s[i])) {
		this->year = this->year * 10 + s[i]-'0';
		++i;
	}
	++i;
	while (isdigit(s[i])) {
		this->month = this->month * 10 + s[i]-'0';
		++i;
	}
	++i;
	while (isdigit(s[i])) {
		this->day = this->day * 10 + s[i]-'0';
		++i;
	}
	this->s = std::to_string(this->year) + "/" + std::to_string(this->month) + "/" + std::to_string(this->day);
}

MyTime::MyTime(int a, int b, int c)
{
	this->year = a;
	this->month = b;
	this->day = c;
	this->s = std::to_string(a) + "/" + std::to_string(b) + "/" + std::to_string(c);
}
