#include "changepass.h"
#include "ui_changepass.h"
#include <QMessageBox>
#include <QtSql>
#include "mainwindow.h"

ChangePass::ChangePass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePass)
{
    ui->setupUi(this);
}

ChangePass::~ChangePass()
{
    delete ui;
}

void ChangePass::on_Back_clicked()
{
    this->close();
}


void ChangePass::on_Confirm_clicked()
{
    QSqlQuery query;
    QString atualPass = ui->atualPass->text();
    QString username = ui->username->text();
    QString newPass = ui->newPass->text();
    QString m = MainWindow::name;

    query.exec("SELECT username, password from users where username = '"+m+"'");
    if(query.first()){
        QString u = query.value(0).toString();
        QString p = query.value(1).toString();
        if(u == username && p == atualPass){
            qDebug() << "OK";
            QMessageBox::StandardButton res = QMessageBox::question(this, "", "Are u sure?", QMessageBox::Yes|QMessageBox::No);
            if(res == QMessageBox::Yes){
                query.exec("UPDATE users SET password = '"+newPass+"' where username = '"+username+"' ");
                ui->changeOK->setText("Change OK");
            }
            else{
                qDebug() << "NAo mudou";
            }

        }
        else{
            ui->changeOK->setText("Actual Password Incorrect");
            ui->atualPass->clear();
            ui->username->clear();
            ui->newPass->clear();
            ui->username->setFocus();
        }
    }
}

