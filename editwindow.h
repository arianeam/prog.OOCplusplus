#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QString>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class editwindow;
}

class editwindow : public QDialog
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr, QString id = NULL);
    ~editwindow();

private slots:
    void on_GravarBtn_clicked();

    void on_ObraLineEdit_textChanged(const QString &arg1);

private:
    Ui::editwindow *ui;
};

#endif // EDITWINDOW_H