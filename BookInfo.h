#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
#include<QString>
using namespace std;

struct MyTime {
	string s;
	int year, month, day;
	MyTime(const string & s);

	MyTime(int a=2019, int b=1, int c=1);
};
int operator - (const MyTime &a, const MyTime & b);
bool operator < (const MyTime &a, const MyTime &b);
bool operator == (const MyTime &a, const MyTime &b);
bool operator <= (const MyTime &a, const MyTime &b);

class BookInfo
{
public:
	BookInfo();
	~BookInfo();
    BookInfo(string name,int num,int h,int r,MyTime st,MyTime ed,Data *d);
public:
    QString name;
	MyTime start_time;
	MyTime end_time;
	Room * room;
	int price;
	int num;
};

