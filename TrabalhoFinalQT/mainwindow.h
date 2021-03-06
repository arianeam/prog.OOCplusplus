#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QtWidgets>
#include "configwindow.h"
#include "addwindow.h"
#include "loginwindow.h"
#include "editwindow.h"
#include "Banco_de_dados.h"
#include "Usuario.h"
#include "Livro.h"

namespace Ui {
class Mainwindow;
}

class Mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = nullptr, Banco_de_dados* b = NULL, Usuario* us = NULL );
    ~Mainwindow();

    Banco_de_dados* bd;
    Usuario* user;
    Livro livro;

private slots:

    void on_addBtn_clicked();

    void on_listarBtn_clicked();

    void on_pesquisaBtn_clicked();

    void on_excluirBtn_clicked();

    void on_sairBtn_clicked();

    void on_editarBtn_clicked();

    void on_pesquisarlineEdit_textChanged(const QString &arg1);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void insere_linha(int linha);

    void formato_tabela();

    void on_configBtn_clicked();

private:
    Ui::Mainwindow *ui;
};

#endif // MAINWINDOW_H
