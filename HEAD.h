#pragma once
#include<bits/stdc++.h>
using namespace std;
struct MyTime;
class Hotel;
typedef shared_ptr<Hotel> ptr_hotel;
typedef weak_ptr<Hotel> weak_hotel;
class Room;
typedef shared_ptr<Room> ptr_room;
typedef weak_ptr<Room> weak_room;
class Data;
typedef vector<string> vec_str;
typedef pair<int, int> pos_room;
typedef pair<vec_str, vector<Room*>> res_pair;
class BookInfo;
typedef shared_ptr<BookInfo> ptr_bok;
class comparclass;

#include"Hotel.h"
#include"Room.h"
#include"Data.h"
#include"BookInfo.h"
#include"Admin.h"
using namespace std;
