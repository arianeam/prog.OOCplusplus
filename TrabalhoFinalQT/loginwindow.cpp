#include "loginwindow.h"
#include "ui_loginwindow.h"

 static QSqlDatabase bd_acervo = QSqlDatabase::addDatabase("QSQLITE");
 static int errosLogin = 0;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    bd_acervo.setDatabaseName("C:/Users/PICHAU/Documents/programas_QT/acervo_livros/acervo.db");

    if(!bd_acervo.open())
    {

      ui->statuslabel->setText("Erro ao abrir o banco de dados!");

    }else{
         ui->statuslabel->clear();
    }

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_clicked()
{
    QString username = ui->loginlineEdit->text();
    QString senha = ui->senhalineEdit->text();

    if(!bd_acervo.isOpen()){
        qDebug()<<"Banco de dados não foi aberto!";
        return;
    }

    QSqlQuery query;

    if(query.exec("select * from tb_login where login='"+username+"' and senha='"+senha+"'")){

        int cont = 0;

        while(query.next())
        {
            cont++;
        }

        if(cont>0){
            QMessageBox::information(this,"","Login efetuado com sucesso!");
            this->close();
            errosLogin = 0;
            principalwindow p;
            p.setModal(true);
            p.exec();
        }else{
            errosLogin++;
             QMessageBox::information(this,"","Login inválido!");
            ui->senhalineEdit->clear();
            ui->loginlineEdit->clear();
            ui->loginlineEdit->setFocus();
            if(errosLogin==5)
            {
                ui->statuslabel->setText("5 erros consecutivos! Aguarde 5 min! ");
                ui->pushButton->hide();
                QTimer::singleShot(300000, ui->pushButton, SLOT(show()));

            }

        }

    }

}
