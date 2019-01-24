#ifndef TABLE_SELECT_H
#define TABLE_SELECT_H

#include <QDialog>
#include <QTableWidget>
#include "HEAD.h"
#include <QTableWidgetItem>
#include<QStandardItemModel>
#include<bits/stdc++.h>
namespace Ui {
class table_select;
}

class table_select : public QDialog
{
    Q_OBJECT

public:
    explicit table_select(QWidget *parent = nullptr,Data* d=nullptr,QString name="");
    ~table_select();
    Data *d;
    QString name;
private slots:
    void on_select_clicked();

    void on_select_2_clicked();

    void reset(bool x);
    void on_pushButton_clicked();

private:
    vector <Room*> room;
    set <QString> city;
    set <QString> hotel;
    Ui::table_select *ui;
    QStandardItemModel *model;
};

#endif // TABLE_SELECT_H
