#ifndef HOTELTABLE_H
#define HOTELTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QTableView>
#include <QTableWidgetItem>
#include "HEAD.h"
class Hoteltable : public QWidget
{
    Q_OBJECT
public:
    explicit Hoteltable(QWidget *parent = nullptr);
    ~Hoteltable();
    void tableupdate(map <int,ptr_hotel> & al);
signals:

public slots:

private:

    QTableWidget * table;
};

#endif // HOTELTABLE_H
