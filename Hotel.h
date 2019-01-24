#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
using namespace std;

class Hotel
{
public:
	friend class Data;
	friend class Room;
public:
	bool insert_room(const string &s);
	bool delete_room(const int & n);

	Hotel(const string & s,Data * d);
	~Hotel();

	const int & get_num() const;
	const string & get_name() const;
	const string & get_city() const;
	const string & get_position() const;
	const map<int, ptr_room> & get_room() const;
private:
	bool insert_room(const ptr_room & tmp);

public:
	map <int, ptr_room> room;
	Data * data;
	void Warning_no_such_room(int num);
	bool Warning_the_same_number(int num);
	int num;
	string hotel;
	string city;
	string position;
};

inline bool operator < (const ptr_hotel & a, const ptr_hotel & b);
