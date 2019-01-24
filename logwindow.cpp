#include "logwindow.h"
#include "ui_logwindow.h"
#include "widget.h"
#include <QMessageBox>
#include<QDebug>

logwindow::logwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logwindow)
{
    this->setWindowFlag(Qt::WindowCloseButtonHint,false);
    ui->setupUi(this);
    ui->login->setText(tr("确认"));
}

logwindow::~logwindow()
{
    delete ui;
}

void logwindow::setinfo(std::string info){
    std::string tmp;
    tmp=info+"：";
    ui->lable->setText(tr(tmp.data()));
    tmp="请输入"+info;
    ui->line->setPlaceholderText(tr(tmp.data()));
}

void logwindow::setpassword(bool x){
    if (x){
        ui->line->setEchoMode(QLineEdit::Password);
    }else{
        ui->line->setEchoMode(QLineEdit::Normal);
    }
}

void logwindow::on_admin_clicked()
{
}

void logwindow::on_login_clicked()
{
        s=ui->line->text();
        emit sendsignal(s);
        //qDebug() << s;
        ui->line->clear();
        this->close();
}
