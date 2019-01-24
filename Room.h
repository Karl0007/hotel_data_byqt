#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
using namespace std;

class Room
{
public:
	friend class Data;
	friend class Hotel;
public:
	Room(const int & num,const int & price,const string & type);
    Room(const string & s, unsigned long long &i);
	Room(const string & s);

	~Room();
	
	const int & get_price() const;
	const string & get_type() const;
	const int & get_num() const;
	const Hotel* get_hotel() const;
	friend bool operator == (const ptr_room & a, const ptr_room & b);
	const string & get_hotel_name() const;
	const string & get_hotel_position() const;
	const string & get_hotel_city() const;
	const int & get_hotel_num() const;
	string get_data() const;

private:
	void modify_price(int x);
	void modify_type(const string &s);
	void set_hotel(Hotel * h);


private:
	Hotel * hotel;
	string type;
	int price;
	int num;
};


bool operator < (const Room & a, const Room & b);

bool operator < (const ptr_room & a, const ptr_room & b);

