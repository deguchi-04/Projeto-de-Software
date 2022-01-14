#include "newmovieadd.h"
#include "ui_newmovieadd.h"
#include "movie.h"
#include "mainpageadmin.h"

NewMovieAdd::NewMovieAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMovieAdd)
{
    ui->setupUi(this);
}

NewMovieAdd::~NewMovieAdd()
{
    delete ui;
}

void NewMovieAdd::on_submit_clicked()
{
    int i;
    Movie mo;
    QString mname = ui->MovieName->text();
    QString actors = ui->Actors->text();
    QString director = ui->Director->text();
    QString genre = ui->Genre->text();
    QString description = ui->description->text();
    QString image = ui->path->text();
    i= mo.MovieInsert(mname,image,actors,director, description, genre);
    qDebug() << "MOVIEEEE" << i;
    if(i==0){
        ui->SubOK->setText("OK");
        ui->MovieName->clear();
        ui->Actors->clear();
        ui->Director->clear();
        ui->Genre->clear();
        ui->path->clear();
        ui->description->clear();
    }
    else if(i==-1){
        ui->SubOK->setText("Movie already in database");
        ui->MovieName->clear();
        ui->Actors->clear();
        ui->Director->clear();
        ui->Genre->clear();
        ui->path->clear();
        ui->description->clear();
    }
    else{
        ui->SubOK->setText("ERRO");
    }
}


void NewMovieAdd::on_Back_clicked()
{
    this->close();
    mainpageadmin m;
    m.setModal(true);
    m.exec();
}

