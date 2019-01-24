#include "table_room.h"
#include "ui_table_room.h"
#include <QStringList>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QMessageBox>
table_room::table_room(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table_room)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
    model->setColumnCount(3);

    model->setHeaderData(0,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(1,Qt::Horizontal,tr("价格"));
    model->setHeaderData(2,Qt::Horizontal,tr("房型"));
    ui->tableView->setModel(model);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setVisible(true);
}

table_room::~table_room()
{
    delete ui;
    delete model;
}

void table_room::tableupdate(map <int,ptr_room> & al){
    ui->tableView->show();
    model->clear();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(1,Qt::Horizontal,tr("价格"));
    model->setHeaderData(2,Qt::Horizontal,tr("房型"));
    ui->tableView->setModel(model);
    int i=0;
    for (auto k : al){
        model->setItem(i,0,new QStandardItem(QString::number(k.first)));
        model->setItem(i,1,new QStandardItem(QString::number(k.second->get_price())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(k.second->get_type())));
        i++;
    }
    if (model->rowCount()!=0){
        QModelIndex index = model->index(0,0);
        ui->tableView->setCurrentIndex(index);
    }
}
void table_room::on_deletroom_clicked()
{
    if (model->rowCount()==0){
        QMessageBox::warning(this,tr("警告"),tr("没有可以删除的房间"),tr("确认"));
        return;
    }
    int cr=ui->tableView->currentIndex().row();
    int id=model->item(cr,0)->text().toInt();
    h->delete_room(id);
    tableupdate(h->room);
}

void table_room::on_addroom_clicked()
{
    QString res="";
    bool ok = false;
    int num = QInputDialog::getInt(this,tr( "房间号" ),tr( "请输入房间号" ),0,1,99999,1,&ok);
    if (ok) {
        res=res + QString::number(num) + ',';
        ok=0;
        if (h->room.count(num)){
            if (QMessageBox::question(this,"房间号冲突","该房间号已存在，是否替换？")!=QMessageBox::Yes) return;
        }
    }else return;
    num = QInputDialog::getInt(this,tr( "价格" ),tr( "请输入价格" ),0,1,99999,1,&ok);
    if (ok) {
        res=res + QString::number(num);
        ok=0;
    }else return;
    QString text = QInputDialog::getText(this,tr( "房型" ),tr( "请输入房型" ),QLineEdit::Normal,QString::null,&ok);
    if ( ok && !text.isEmpty() ) res+=','+text+'|',ok=0; else return;
    d->insert_room(h->get_num(),res.toStdString());
    tableupdate(h->room);
}
