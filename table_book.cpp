#include "table_book.h"
#include "ui_table_book.h"
#include <QStringList>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QMessageBox>
#include "HEAD.h"
#include "table_select.h"
table_book::table_book(QWidget *parent,QString s) :
    QDialog(parent),
    ui(new Ui::table_book)
{
    ui->setupUi(this);
    ui->name->setText(s);
    name=s;
    model = new QStandardItemModel();
    model->setColumnCount(9);

    model->setHeaderData(0,Qt::Horizontal,tr("订单编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("酒店"));
    model->setHeaderData(2,Qt::Horizontal,tr("城市"));
    model->setHeaderData(3,Qt::Horizontal,tr("地区"));
    model->setHeaderData(4,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(5,Qt::Horizontal,tr("房型"));
    model->setHeaderData(6,Qt::Horizontal,tr("总价"));
    model->setHeaderData(7,Qt::Horizontal,tr("起始时间"));
    model->setHeaderData(8,Qt::Horizontal,tr("终止时间"));
    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(true);
}

table_book::~table_book()
{
    delete ui;
    delete model;
}

void table_book::tableupdate(map <int,ptr_bok> & al){
    ui->tableView->show();
    model->clear();
    model->setColumnCount(9);

    model->setHeaderData(0,Qt::Horizontal,tr("订单编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("酒店"));
    model->setHeaderData(2,Qt::Horizontal,tr("城市"));
    model->setHeaderData(3,Qt::Horizontal,tr("地区"));
    model->setHeaderData(4,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(5,Qt::Horizontal,tr("房型"));
    model->setHeaderData(6,Qt::Horizontal,tr("总价"));
    model->setHeaderData(7,Qt::Horizontal,tr("起始时间"));
    model->setHeaderData(8,Qt::Horizontal,tr("终止时间"));
    ui->tableView->setModel(model);

    int i=0;
    cout << al.size();
    for (auto k : al){
        if (k.second->name != name) continue;
        model->setItem(i,0,new QStandardItem(QString::number(k.first)));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(k.second->room->get_hotel_name())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(k.second->room->get_hotel_city())));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(k.second->room->get_hotel_position())));
        model->setItem(i,4,new QStandardItem(QString::number(k.second->room->get_num())));
        model->setItem(i,5,new QStandardItem(QString::fromStdString(k.second->room->get_type())));
        model->setItem(i,6,new QStandardItem(QString::number(k.second->price)));
        model->setItem(i,7,new QStandardItem(QString::fromStdString(k.second->start_time.s)));
        model->setItem(i,8,new QStandardItem(QString::fromStdString(k.second->end_time.s)));
        i++;
    }
    if (model->rowCount()!=0){
        QModelIndex index = model->index(0,0);
        ui->tableView->setCurrentIndex(index);
    }
}

void table_book::on_pushButton_2_clicked()
{
    if (model->rowCount()==0){
        QMessageBox::warning(this,tr("警告"),tr("没有可以删除的订单"),tr("确认"));
        return;
    }
    int cr=ui->tableView->currentIndex().row();
    int id=model->item(cr,0)->text().toInt();
    d->delete_book(id);
    tableupdate(d->all_book);
}

void table_book::on_pushButton_clicked()
{
    table_select xx(this,d,name);
    if (!xx.exec()){}
    tableupdate(d->all_book);
}
