#include "Hotel.h"



Hotel::Hotel(const string & s,Data * d)
{
	this->data = d;
    unsigned long long i = 0;
    this->num=0;
    this->hotel=this->city=this->position="";
    while (isdigit(s[i])) {
		this->num = this->num * 10 + s[i] - '0';
		++i;
	}
	++i;
	while (s[i] != ',') {
		this->hotel += s[i];
		++i;
	}
	++i;
	while (s[i] != ',') {
		this->city += s[i];
		++i;
	}
	++i;
	while (s[i] != '|') {
		this->position += s[i];
		++i;
	}
	++i;
	while ( i < s.length() ) {
        ptr_room tmp(new Room(s,i));
		tmp->set_hotel(this);
		insert_room(tmp);
	}

}

void Hotel::Warning_no_such_room(int n)
{
	cout<< n << "号房间不存在！" << endl;
}

bool Hotel::Warning_the_same_number(int n)
{
    return true;
	char x;
	cout << this->num << ":" << this->hotel << n <<"号房间信息已录入 是否要覆盖？ [y/n]" << endl;
	cin >> x;
	while (x != 'y' && x != 'n' && x != 'Y' && x != 'N') cin >> x;
	return x=='y' || x=='Y';
}

Hotel::~Hotel()
{
	cout << "delete" << this->num << endl;
	for (auto &i : this->room) {
		this->data->all_room.erase(i.second);
	}
}

const int & Hotel::get_num() const
{
	return this->num;
}

const string & Hotel::get_name() const
{
	return this->hotel;
}

const string & Hotel::get_city() const
{
	return this->city;
}

const string & Hotel::get_position() const
{
	return this->position;
}

const map<int, ptr_room> & Hotel::get_room() const
{
	return room;
}

bool Hotel::insert_room(const ptr_room & tmp)
{
	if ( this->room.count(tmp->get_num())) {
		if (!Warning_the_same_number(tmp->get_num())) {
			return false;
		}
		else {
			this->data->all_room.erase(this->room[tmp->get_num()]);
			room[tmp->get_num()]->modify_type(tmp->get_type());
			room[tmp->get_num()]->modify_price(tmp->get_price());
			this->data->all_room.insert(room[tmp->get_num()]);
		}
	}
	else {
		room[tmp->get_num()] = tmp;
		this->data->all_room.insert(tmp);
	}
	return true;
}

bool Hotel::insert_room(const string & s)
{
	ptr_room tmp(new Room(s));
	tmp->set_hotel(this);
	return insert_room(tmp);	
}

bool Hotel::delete_room(const int & n)
{
	if (this->room.count(n)) {
		this->data->all_room.erase(this->room[n]);
		this->room.erase(n);
		return true;
	}
	else {
		Warning_no_such_room(n);
		return false;
	}
}

inline bool operator<(const ptr_hotel & a, const ptr_hotel & b)
{
	return a->get_num() < b->get_num();
}
