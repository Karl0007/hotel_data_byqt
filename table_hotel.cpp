#include "table_hotel.h"
#include "ui_table_hotel.h"
#include <QStringList>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QMessageBox>
#include"table_room.h"
Table_hotel::Table_hotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table_hotel)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
    model->setColumnCount(5);

    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("酒店"));
    model->setHeaderData(2,Qt::Horizontal,tr("城市"));
    model->setHeaderData(3,Qt::Horizontal,tr("地区"));
    model->setHeaderData(4,Qt::Horizontal,tr("房间个数"));
    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(true);
}

Table_hotel::~Table_hotel()
{
    delete ui;
    delete model;
}

void Table_hotel::tableupdate(map <int,ptr_hotel> & al){
    ui->tableView->show();
    model->clear();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,tr("编号"));
    model->setHeaderData(1,Qt::Horizontal,tr("酒店"));
    model->setHeaderData(2,Qt::Horizontal,tr("城市"));
    model->setHeaderData(3,Qt::Horizontal,tr("地区"));
    model->setHeaderData(4,Qt::Horizontal,tr("房间个数"));
    ui->tableView->setModel(model);
    int i=0;
    for (auto k : al){
        model->setItem(i,0,new QStandardItem(QString::number(k.first)));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(k.second->get_name())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(k.second->get_city())));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(k.second->get_position())));
        model->setItem(i,4,new QStandardItem(QString::number(k.second->get_room().size())));
        i++;
    }
    if (model->rowCount()!=0){
        QModelIndex index = model->index(0,0);
        ui->tableView->setCurrentIndex(index);
    }
}

void Table_hotel::on_deletehotel_clicked()
{
    if (model->rowCount()==0){
        QMessageBox::warning(this,tr("警告"),tr("没有可以删除的酒店"),tr("确认"));
        return;
    }
    int cr=ui->tableView->currentIndex().row();
    int id=model->item(cr,0)->text().toInt();
    d->delete_hotel(id);
    tableupdate(d->all_hotel);
    cout << id;
}

void Table_hotel::on_addhotel_clicked()
{
    QString res="";
    bool ok = false;
    int num = QInputDialog::getInt(this,tr( "编号" ),tr( "请输入编号" ),0,0,9999,1,&ok);
    if (ok) {
        res=res + QString::number(num);
        ok=0;
        if (d->all_hotel.count(num)){
            if (QMessageBox::question(this,"编号冲突","该编号已存在，是否替换？")!=QMessageBox::Yes) return;
        }
    }else return;
    QString text = QInputDialog::getText(this,tr( "酒店" ),tr( "请输入酒店名称" ),QLineEdit::Normal,QString::null,&ok);
    if ( ok && !text.isEmpty() ) res+=','+text,ok=0; else return;
    text = QInputDialog::getText(this,tr( "城市" ),tr( "请输入所在城市" ),QLineEdit::Normal,QString::null,&ok);
    if ( ok && !text.isEmpty() ) res+=','+text,ok=0; else return;
    text = QInputDialog::getText(this,tr( "位置" ),tr( "请输入具体位置" ),QLineEdit::Normal,QString::null,&ok);
    if ( ok && !text.isEmpty() ) res+=','+text,ok=0; else return;
    res+='|';
    d->insert_hotel(res.toStdString());
    tableupdate(d->all_hotel);

}

void Table_hotel::on_addroom_clicked()
{
    if (model->rowCount()==0){
        QMessageBox::warning(this,tr("警告"),tr("没有可以修改的酒店"),tr("确认"));
        return;
    }
    int cr=ui->tableView->currentIndex().row();
    int id=model->item(cr,0)->text().toInt();
    table_room tr;
    tr.d=d;
    tr.h=&*d->all_hotel[id];
    tr.tableupdate(tr.h->room);
    tr.show();
    if (!tr.exec()){}
    tableupdate(d->all_hotel);
}
