#include "Admin.h"
#include "table_hotel.h"
#include "table_book.h"
#include <QString>
Admin::Admin()
{
    d=new Data;
    d->load_from_file("hotel.txt");
}


Admin::~Admin()
{
    d->save_to_file("hotel.txt");
    delete d;
}

void Admin::user(QWidget *pa,QString s){
    pa->hide();
    d->load_bookinfo("bookinfo.txt");
    table_book xx(pa,s);
    xx.d=d;
    xx.tableupdate(d->all_book);
    if (!xx.exec()){
        pa->show();
    }
    d->save_bookinfo("bookinfo.txt");
}

void Admin::start(QWidget* pa){
    pa->hide();
    Table_hotel xx;
    xx.tableupdate(d->all_hotel);
    xx.d=d;
    xx.show();
    if (!xx.exec()){
        pa->show();
    }
}
