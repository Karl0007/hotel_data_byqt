#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QDialog>
#include <string>

namespace Ui {
class logwindow;
}

class logwindow : public QDialog
{
    Q_OBJECT

public:
    explicit logwindow(QWidget *parent = nullptr);
    ~logwindow();
    void setinfo(std::string lab);

    void setpassword(bool);

private slots:
    void on_admin_clicked();

    void on_login_clicked();

private:
    Ui::logwindow *ui;
    QString s;
signals:
    void sendsignal(QString);
};

#endif // LOGWINDOW_H
