#include "hoteltable.h"
#include"HEAD.h"
Hoteltable::Hoteltable(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,500,500);
    table=new QTableWidget(this);
    table->setGeometry(0,0,500,500);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::ExtendedSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void Hoteltable::tableupdate(map <int,ptr_hotel> & al){
    table->setColumnCount(al.size());
    table->setRowCount(5);

}
Hoteltable::~Hoteltable(){
    delete table;
}
