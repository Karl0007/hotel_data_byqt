#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
#include<QString>
const vec_str nul = vec_str(0,"");
using namespace std;
class Data
{
public:
	friend class Room;
	friend class Hotel;
	friend class BookInfo;
    friend class Admin;
public:
	Data();
    ~Data();
    void load_bookinfo(const string &s);
    void save_bookinfo(const string &s);
	bool load_from_file(const string &s);
	bool save_to_file(const string &s);
	bool insert_hotel(const string &s);
	bool delete_hotel(const int &n);
	bool insert_room(const int &n, const string &s);
	bool delete_room(const int &n, const int &m);
	res_pair select_room(int low = 0,int high = 99999999,const vec_str & city = nul,const vec_str & hotel=nul,const vec_str & position=nul,const vec_str & type = nul);
	bool check_hotel(const int &n);
    pos_room ptr_to_pos(const Room * ptr);
	ptr_room pos_to_ptr(const pos_room & pos);
    Room* pos_to_ptr(const int & h,const int & r);
    bool insert_book(MyTime st,MyTime ed,Room * p,QString s);
	vec_str get_book_info();
	bool delete_book(const int & n);

public:
	//int num;
	bool check_string_in(const vec_str & vs,const string & s);
	bool Waring_the_same_number(int num);
	void Warning_no_hotel_numbuer(int num);
	map <int, ptr_hotel> all_hotel;
    set <ptr_room> all_room;
	map <int, ptr_bok> all_book;
};

