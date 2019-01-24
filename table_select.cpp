#include "table_select.h"
#include "ui_table_select.h"
#include <QStringList>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
table_select::table_select(QWidget *parent,Data * D ,QString Name) :
    QDialog(parent),
    ui(new Ui::table_select)
{
    ui->setupUi(this);
    this->d=D;
    this->name=Name;
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    model = new QStandardItemModel;
    city.insert("");
    hotel.insert("");
    for (auto i : d->all_room){
        city.insert(QString::fromStdString(i->get_hotel_city()));
        hotel.insert(QString::fromStdString(i->get_hotel_name()));
    }
    for (auto i : city){
        ui->city->addItems(QStringList()<<i);
    }
    for (auto i : hotel){
        ui->hotel->addItems(QStringList()<<i);
    }
    ui->low->setRange(0,999999);
    ui->low->setValue(0);
    ui->high->setRange(0,999999);
    ui->high->setValue(999999);
    ui->start->setDate(QDate(2019,1,1));
    ui->end->setDate(QDate(9102,1,1));
    ui->select_2->setEnabled(0);
    reset(1);
}

table_select::~table_select()
{
    delete ui;
    delete model;
}

void table_select::reset(bool x){
    ui->select_2->setEnabled(!x);
    ui->select->setEnabled(x);
    ui->start->setEnabled(x);
    ui->end->setEnabled(x);
    ui->low->setEnabled(x);
    ui->high->setEnabled(x);
    ui->city->setEnabled(x);
    ui->hotel->setEnabled(x);
}

void table_select::on_select_clicked()
{
    auto cmp=[=](const QString &s1,const string &s2)->bool{
        if (s1=="")return 1;
        if (s1.toStdString()==s2) return 1;
        return 0;
    };
    auto toMytime= [=](decltype (ui->start->date()) date)->MyTime{
        return MyTime(date.year(),date.month(),date.day());
    };
    auto conflict = [=](decltype (d->all_book) al,MyTime st,MyTime ed,QString n,int num1,int num2)->bool{
        for (auto i:al){
            cout << st.s << " "<< i.second->end_time.s <<endl;
            if (i.second->name==n) continue;
            if (num1!=i.second->room->get_hotel_num() || num2!=i.second->room->get_num()) continue;
            if ((st <= i.second->end_time &&  i.second->start_time <= ed) || (i.second->start_time <= ed && st<=i.second->end_time)){
                return true;
            }
        }
        return false;
    };
    model->clear();
    model->setColumnCount(6);

    model->setHeaderData(0,Qt::Horizontal,tr("酒店"));
    model->setHeaderData(1,Qt::Horizontal,tr("城市"));
    model->setHeaderData(2,Qt::Horizontal,tr("地区"));
    model->setHeaderData(3,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(4,Qt::Horizontal,tr("房型"));
    model->setHeaderData(5,Qt::Horizontal,tr("单价"));

    ui->tableView->setModel(model);
    int i=0;
    if (ui->low->value()>ui->high->value()) return;
    if (ui->start->date()>ui->end->date()) return;
    room.clear();
    for (auto k : d->all_room){
        if (!cmp(ui->city->currentText(),k->get_hotel_city())) continue;
        if (!cmp(ui->hotel->currentText(),k->get_hotel_name())) continue;
        if (ui->low->value()>k->get_price() || ui->high->value()<k->get_price()) continue;
        if (conflict(d->all_book,toMytime(ui->start->date()),toMytime(ui->end->date()),name,k->get_hotel_num(),k->get_num()))continue;
        model->setItem(i,0,new QStandardItem(QString::fromStdString(k->get_hotel_name())));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(k->get_hotel_city())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(k->get_hotel_position())));
        model->setItem(i,3,new QStandardItem(QString::number(k->get_num())));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(k->get_type())));
        model->setItem(i,5,new QStandardItem(QString::number(k->get_price())));
        room.push_back(&*k);
        i++;
    }
    if (model->rowCount()!=0){
        QModelIndex index = model->index(0,0);
        ui->tableView->setCurrentIndex(index);
        reset(0);
    }else{
        ui->select_2->setEnabled(0);
    }
}

void table_select::on_select_2_clicked()
{
    auto toMytime= [=](decltype (ui->start->date()) date)->MyTime{
        return MyTime(date.year(),date.month(),date.day());
    };
    auto id=room[ui->tableView->currentIndex().row()];
    d->insert_book(toMytime(ui->start->date()),toMytime(ui->end->date()),id,name);
    QMessageBox::about(this,"成功","预定成功");
    this->close();
}

void table_select::on_pushButton_clicked()
{
    reset(1);
    model->clear();
    room.clear();
}
