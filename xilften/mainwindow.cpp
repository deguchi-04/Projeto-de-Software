#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QtSql>
#include "user.h"
#include "mainpagemovies.h"
#include "registerpage.h"
#include "admin.h"
#include "mainpageadmin.h"

static QSqlDatabase DB = QSqlDatabase::addDatabase("QMYSQL");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB.setHostName("db.fe.up.pt");
    DB.setDatabaseName("up201802575");
    DB.setUserName("up201802575");
    DB.setPassword("Y1a2mVSGD");
    if (DB.open())
    {
        qDebug() << "Connected!";
    }
    else
    {
        qDebug() << "Failed to connect.";
        ui->LogOk->setText("You not are connected to VPN!! ");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::name = 0;

void MainWindow::on_LogBut_clicked()
{
    QString username = ui->username->text();
    QString password = ui->Pass->text();
    MainWindow::name = username;
    user u;
    Admin a;
    int i;
    if(DB.isOpen()){
        qDebug() << "DB open";
        if(QString::compare(username, "admin", Qt::CaseInsensitive) == 0){
            if(a.Admission(password) == 0){
                this->close();
                mainpageadmin mainPagA;
                mainPagA.setModal(true);
                mainPagA.exec();
            }
        }

        i = u.LogIN(username, password);
        if(i == 0){
            this->close();
            mainpagemovies mainPag;
            mainPag.setModal(true);
            mainPag.exec();
        }
        else{
            ui->LogOk->setText("Wrong username or password");
        }
    }
    else{
        qDebug() << "DB not opened";
        ui->LogOk->setText("You not are connected to VPN!! ");

    }


}


void MainWindow::on_RegBut_clicked()
{
    RegisterPage reg;
    reg.setModal(true);
    reg.exec();
}

