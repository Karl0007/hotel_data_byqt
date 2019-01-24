#pragma once
#include"HEAD.h"
#include"widget.h"
class Admin
{
public:
    friend class Data;
	Admin();
    ~Admin();
    void start(QWidget*);
    void user(QWidget*,QString);
private:
    Data *d;
};

