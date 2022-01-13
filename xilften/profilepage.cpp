#include "profilepage.h"
#include "ui_profilepage.h"
#include "mainwindow.h"
#include <QtSql>
#include "mainpagemovies.h"
#include "movie.h"
#include "donated.h"
#include "changepass.h"
#include <QMessageBox>

ProfilePage::ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfilePage)
{
    ui->setupUi(this);
    QString m = MainWindow::name;
    QSqlQuery query;
    query.exec("SELECT * from users where username = '"+m+"' ");
    if(query.first()){
        ui->user->setText(query.value(1).toString());
        ui->mail->setText(query.value(2).toString());
        ui->name->setText(query.value(3).toString());
        ui->age->setText(query.value(4).toString());
        QString aux0 = QString::number(query.value(6).toInt());
        QString aux = QString("%1 moneys").arg(aux0);
        ui->donated->setText(aux);

    }
}

ProfilePage::~ProfilePage()
{
    delete ui;
}

void ProfilePage::on_Back_clicked()
{
    this->close();
    mainpagemovies pag;
    pag.setModal(true);
    pag.exec();
}


void ProfilePage::on_Donate_clicked()
{
    donated myDon;
    QString username = ui->user->text();
    int TotalDon, value = ui->box->value();
    QMessageBox::StandardButton res = QMessageBox::question(this, "", "Are u sure you want to donate this amount?", QMessageBox::Yes|QMessageBox::No);
    if(res == QMessageBox::Yes){
        TotalDon = myDon.don(username,value);
        QString aux0 = QString::number(TotalDon);
        QString aux = QString("%1 moneys").arg(aux0);
        ui->donated->setText(aux);
        QString aux2 = QString::number(TotalDon);
        QString au3 = QString("Congrats, you already donated %1 moneys to Xilften, thank you").arg(aux2);

        QMessageBox::question(this, "", au3, QMessageBox::NoButton);
    }
    else {
        qDebug() << "Nao doado";
    }
}


void ProfilePage::on_DelProf_clicked()
{
    QSqlQuery query;

    QString m = MainWindow::name;

    QMessageBox::StandardButton res = QMessageBox::question(this, "", "Are u sure?", QMessageBox::Yes|QMessageBox::No);

    if(res == QMessageBox::Yes){
        query.exec("DELETE FROM eval where name= '"+m+"' ");
        query.exec("DELETE FROM users where username= '"+m+"' ");
        query.exec("ALTER TABLE users AUTO_INCREMENT = 1 ");
        this->close();
        MainWindow *main = new MainWindow();
        main->show();
    }
    else {
        qDebug() << "Nao deletado";
    }
}


void ProfilePage::on_change_clicked()
{
    ChangePass c;
    c.setModal(true);
    c.exec();
}


void ProfilePage::on_LogOut_clicked()
{
    this->close();
    MainWindow *main = new MainWindow();
    main->show();
}

