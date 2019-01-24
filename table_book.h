#ifndef TABLE_BOOK_H
#define TABLE_BOOK_H

#include <QDialog>
#include <QTableWidget>
#include "HEAD.h"
#include <QTableWidgetItem>
#include<QStandardItemModel>
namespace Ui {
class table_book;
}

class table_book : public QDialog
{
    Q_OBJECT

public:
    explicit table_book(QWidget *parent = nullptr ,QString="");
    ~table_book();
    void tableupdate(map <int,ptr_bok> & al);
    QString name;
    Data *d;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::table_book *ui;
    QStandardItemModel  *model;
};

#endif // TABLE_BOOK_H
