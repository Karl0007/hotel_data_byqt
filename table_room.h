#ifndef TABLE_ROOM_H
#define TABLE_ROOM_H

#include <QDialog>
#include <QTableWidget>
#include "HEAD.h"
#include <QTableWidgetItem>
#include<QStandardItemModel>
namespace Ui {
class table_room;
}

class table_room : public QDialog
{
    Q_OBJECT

public:
    friend class Hotel;
    explicit table_room(QWidget *parent = nullptr);
    ~table_room();
    void tableupdate(map <int,ptr_room> & al);
    Data *d;
    Hotel *h;
private slots:
    void on_addroom_clicked();

    void on_deletroom_clicked();

private:
    Ui::table_room *ui;
    QStandardItemModel  *model;
};

#endif // TABLE_ROOM_H
