#include "widget.h"
#include "ui_widget.h"
#include"logwindow.h"
#include "HEAD.h"
#include <QDebug>
#include<QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    s1=new logwindow(this);
    connect(s1,SIGNAL(sendsignal(QString)),this,SLOT(getstring(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //logwindow *log = new logwindow(this);
    //log->show();
    QMessageBox::about(this,tr("酒店管理V0.1"),tr("      by karl07 \n 陈盛恺 181860007"));
}

void Widget::on_admin_clicked()
{
    s1->setpassword(1);
    s1->setinfo("管理员密码");
    s1->show();
    if (!s1->exec()){
        if (tmpstr == "admin"){
            QMessageBox::about(this,tr("登录成功"),tr("密码正确"));
            Admin x;
            x.start(this);
        }else{
            QMessageBox::warning(this,tr("警告"),tr("密码错误"),tr("确认"));
        }
        tmpstr="";
    }
}

void Widget::on_user_clicked()
{
    s1->setpassword(0);
    s1->setinfo("用户名");
    s1->show();
    if (!s1->exec()){
        if (tmpstr!=""){
            Admin x;
            x.user(this,tmpstr);
        }else{
            QMessageBox::warning(this,tr("警告"),tr("用户名为空"),tr("确认"));
        }
        tmpstr="";
    }
}

void Widget::getstring(QString s){
    tmpstr=s;
    qDebug()<< s;
}
