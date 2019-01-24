#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"logwindow.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_admin_clicked();

    void on_user_clicked();

    void getstring(QString);

private:
    Ui::Widget *ui;
    logwindow *s1;
    QString tmpstr;
signals:
    void sendsignal(QString);
};

#endif // WIDGET_H
