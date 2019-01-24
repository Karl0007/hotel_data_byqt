#include "widget.h"
#include "logwindow.h"
#include "HEAD.h"
#include"hoteltable.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    qDebug() << 123;
    w.show();
    return a.exec();
/*    if (log_win.exec() == QDialog::Accepted ){
        w.show();
        return a.exec();

    }else{
        return 0;
    }*/
}
