#include "registerpage.h"
#include "ui_registerpage.h"
#include "user.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_LogBut_clicked()
{
    int i;
    user u;
    QString username = ui->RegUsername->text();
    QString password = ui->RegPass->text();
    QString email = ui->RegEmail->text();
    QString fullname = ui->RegFullName->text();
    QString age = ui->RegAge->text();
    i = u.Register(username,email,age,password,fullname);
    if(i==0){
        ui->RegisterOk->setText("Registration OK");
        ui->RegAge->clear();
        ui->RegUsername->clear();
        ui->RegPass->clear();
        ui->RegEmail->clear();
        ui->RegFullName->clear();
        ui->RegUsername->setFocus();
    }
    else if(i == -1){
        ui->RegisterOk->setText("Username already taken");
        ui->RegAge->clear();
        ui->RegUsername->clear();
        ui->RegPass->clear();
        ui->RegEmail->clear();
        ui->RegFullName->clear();
        ui->RegUsername->setFocus();
    }
    else if(i == -2){
        ui->RegisterOk->setText("Email already registed");
        ui->RegAge->clear();
        ui->RegUsername->clear();
        ui->RegPass->clear();
        ui->RegEmail->clear();
        ui->RegFullName->clear();
        ui->RegUsername->setFocus();
    }

}


void RegisterPage::on_BackButton_clicked()
{
    this->close();
}

