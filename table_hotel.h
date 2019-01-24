#ifndef TABLE_HOTEL_H
#define TABLE_HOTEL_H

#include <QDialog>
#include <QTableWidget>
#include "HEAD.h"
#include <QTableWidgetItem>
#include<QStandardItemModel>
namespace Ui {
class Table_hotel;
}

class Table_hotel : public QDialog
{
    Q_OBJECT

public:
    explicit Table_hotel(QWidget *parent = nullptr);
    ~Table_hotel();
    void tableupdate(map <int,ptr_hotel> & al);
    Data *d;
private slots:
    void on_deletehotel_clicked();

    void on_addhotel_clicked();

    void on_addroom_clicked();

private:
    Ui::Table_hotel *ui;
    QStandardItemModel  *model;
};

#endif // TABLE_HOTEL_H
