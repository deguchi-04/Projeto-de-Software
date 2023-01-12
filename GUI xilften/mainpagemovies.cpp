#include "mainpagemovies.h"
#include "ui_mainpagemovies.h"

#include "movie.h"
#include "profilepage.h"
#include "mainwindow.h"
#include <QList>

mainpagemovies::mainpagemovies(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainpagemovies)
{
    ui->setupUi(this);

    ui->stackedWidget_3->setCurrentIndex(0);
    QByteArray array;
    QSqlQuery query;
    QList<QString> a;

    QList<float> b;

    QList<QPixmap> c;

    Movie mov;
    int n;
    QString m = MainWindow::name;
    QString welcome = QString("Welcome %1").arg(m);
    ui->Welcome_3->setText(welcome);

    ui->leaveC_2->setDisabled(1);
    connect(ui->com_2, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));

    if(query.exec("SELECT name, ROUND(classification,1), image FROM movie ORDER BY classification DESC LIMIT 10;")){
        while (query.next()) {
            array = query.value(2).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            a.append(query.value(0).toString());
            b.append(query.value(1).toFloat());
            c.append(pixmap);
        }
        QString aux0 = QString::number(b[0]);
        QString aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[0]);
        ui->movieTitle->setText(a[0]);
        ui->movie->setPixmap(c[0]);
        ui->classi->setText(aux);
        ui->total->setText(QString::number(n));


        aux0 = QString::number(b[1]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[1]);
        ui->total_2->setText(QString::number(n));
        ui->movieTitle_2->setText(a[1]);
        ui->movie_2->setPixmap(c[1]);
        ui->classi_2->setText(aux);

        aux0 = QString::number(b[2]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[2]);
        ui->total_3->setText(QString::number(n));
        ui->movieTitle_3->setText(a[2]);
        ui->movie_3->setPixmap(c[2]);
        ui->classi_3->setText(aux);

        n = mov.countRate(a[3]);
        ui->total_4->setText(QString::number(n));
        aux0 = QString::number(b[3]);
        aux = QString("%1/10").arg(aux0);
        ui->movieTitle_4->setText(a[3]);
        ui->movie_4->setPixmap(c[3]);
        ui->classi_4->setText(aux);

        aux0 = QString::number(b[4]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[4]);
        ui->total_5->setText(QString::number(n));
        ui->movieTitle_5->setText(a[4]);
        ui->movie_5->setPixmap(c[4]);
        ui->classi_9->setText(aux);

        aux0 = QString::number(b[5]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[5]);
        ui->total_6->setText(QString::number(n));
        ui->movieTitle_6->setText(a[5]);
        ui->movie_6->setPixmap(c[5]);
        ui->classi_10->setText(aux);

        aux0 = QString::number(b[6]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[6]);
        ui->total_7->setText(QString::number(n));
        ui->movieTitle_7->setText(a[6]);
        ui->movie_7->setPixmap(c[6]);
        ui->classi_11->setText(aux);

        aux0 = QString::number(b[7]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[7]);
        ui->total_8->setText(QString::number(n));
        ui->movieTitle_8->setText(a[7]);
        ui->movie_8->setPixmap(c[7]);
        ui->classi_12->setText(aux);

        aux0 = QString::number(b[8]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[8]);
        ui->total_9->setText(QString::number(n));
        ui->movieTitle_9->setText(a[8]);
        ui->movie_9->setPixmap(c[8]);
        ui->classi_13->setText(aux);

        aux0 = QString::number(b[9]);
        aux = QString("%1/10").arg(aux0);
        n = mov.countRate(a[9]);
        ui->total_10->setText(QString::number(n));
        ui->movieTitle_10->setText(a[9]);
        ui->movie_10->setPixmap(c[9]);
        ui->classi_14->setText(aux);

    }
}

mainpagemovies::~mainpagemovies()
{
    delete ui;
}

void mainpagemovies::onTextChanged(const QString &a_strString)
{
    ui->leaveC_2->setEnabled(!a_strString.isEmpty());
}

void mainpagemovies::on_ProfileButton_3_clicked()
{
    this->close();
    ProfilePage pro;
    pro.setModal(true);
    pro.exec();
}


void mainpagemovies::on_TopMovies_clicked()
{

    ui->stackedWidget_3->setCurrentIndex(0);
    ui->scrollArea->ensureVisible(0, 0,0,0);
}


void mainpagemovies::on_Catalog_clicked()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel;
    query.exec("SELECT name, genre, id, classification, description, actors, director from movie");
    model->setQuery(query);
    if(query.first()){
        ui->tableView_5->setModel(model);
        ui->stackedWidget_3->setCurrentIndex(2);
        ui->scrollArea->ensureVisible(0, 0,0,0);
        ui->tableView_5->setFocus();

    }
}


void mainpagemovies::on_GoButton_3_clicked()
{
    QString MovieName = ui->Search->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){

        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }
        else{
            ui->SearchOK->setText("We could not find this one");
        }
    }
}


void mainpagemovies::on_LogOut_clicked()
{
    this->close();
    MainWindow *main = new MainWindow();
    main->show();
}


void mainpagemovies::on_evalbutton_3_clicked()
{
    Movie mov;
    QString m = MainWindow::name;
    QString m2 = ui->Title_3->text();
    QString m3 = QString::number(ui->spinBox_4->value());
    QSqlQuery query;
    query.exec("SELECT * from eval where name = '"+m+"' and movieName = '"+m2+"' ");


    if(!query.first()){
        qDebug() << "aaa";
        query.exec("INSERT INTO eval (name, movieName, rate) values ('"+m+"', '"+m2+"', '"+m3+"') ");
        float result = mov.newMovieRate(m, ui->Title_3->text(), QString::number(ui->spinBox_4->value()));
        ui->classification->setText(QString::number(result));
        ui->currently_2->setText(m3);
    }

    else{
        qDebug() << "bbb";
        float result = mov.newMovieRate(m, ui->Title_3->text(), QString::number(ui->spinBox_4->value()));
        ui->classification->setText(QString::number(result));
        ui->currently_2->setText(m3);
    }
}


void mainpagemovies::on_leaveC_2_clicked()
{
    QSqlQuery query;
    QString m = MainWindow::name;
    QString movieName = ui->Title_3->text();
    QString comm = ui->com_2->text();
    if(query.exec("INSERT INTO comment (`name`, `movieName`, `comment`) values ('"+m+"', '"+movieName+"', '"+comm+"') ")){
       qDebug() << "comment OK";
       ui->com_2->clear();
       ui->commentOK_2->setText("Comment Submited");
    }

}


void mainpagemovies::on_seeAllC_clicked()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel;
    QString movieName = ui->Title_3->text();
    query.exec("SELECT name, comment from comment where movieName = '"+movieName+"' ");
    model->setQuery(query);
    if(query.first()){
        ui->tableView_6->setModel(model);
        ui->scrollArea->ensureVisible(0, 0,0,0);

    }
    ui->stackedWidget_3->setCurrentIndex(3);
    ui->scrollArea->ensureVisible(0, 0,0,0);
}


void mainpagemovies::on_delete_4_clicked()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel;
    QString m = MainWindow::name;
    QString movieName = ui->Title_3->text();
    query.exec("SELECT * from comment where movieName = '"+movieName+"' and name = '"+m+"' ");
    model->setQuery(query);
    if(query.first()){
        ui->tableView_7->setModel(model);


    }
    ui->stackedWidget_3->setCurrentIndex(4);
    ui->scrollArea->ensureVisible(0, 0,0,0);
}


void mainpagemovies::on_back_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->scrollArea->ensureVisible(0, 0,0,0);
}


void mainpagemovies::on_delete_5_clicked()
{
    QSqlQuery query, query2, query3;
    QSqlQueryModel *model = new QSqlQueryModel;
    QString m = MainWindow::name;
    QString movieName = ui->Title_3->text();
    QString value = QString::number(ui->spinBox_5->value());
    query.exec("DELETE FROM comment where name= '"+m+"' and id= '"+value+"' ");
    query2.exec("SELECT * from comment where movieName = '"+movieName+"' and name = '"+m+"' ");
    query3.exec("SET @num :=0 ");
    query3.exec("update comment set id = @num := (@num+1) ");
    query3.exec("ALTER TABLE comment AUTO_INCREMENT = 1 ");
    model->setQuery(query2);
    ui->tableView_7->setModel(model);
    qDebug() << model->rowCount();
    query.exec("SELECT * from comment where movieName = '"+movieName+"' and name = '"+m+"' ");
    model->setQuery(query);
    ui->tableView_6->setModel(model);

}


void mainpagemovies::on_back_4_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
    ui->scrollArea->ensureVisible(0, 0,0,0);
}


void mainpagemovies::on_movieTitle_clicked()
{
    QString MovieName = ui->movieTitle->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_2_clicked()
{
    QString MovieName = ui->movieTitle_2->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_3_clicked()
{
    QString MovieName = ui->movieTitle_3->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_4_clicked()
{
    QString MovieName = ui->movieTitle_4->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_5_clicked()
{
    QString MovieName = ui->movieTitle_5->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_6_clicked()
{
    QString MovieName = ui->movieTitle_6->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_7_clicked()
{
    QString MovieName = ui->movieTitle_7->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_8_clicked()
{
    QString MovieName = ui->movieTitle_8->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_9_clicked()
{
    QString MovieName = ui->movieTitle_9->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}


void mainpagemovies::on_movieTitle_10_clicked()
{
    QString MovieName = ui->movieTitle_10->text();
    QString m = MainWindow::name;
    QByteArray array;
    QSqlQuery query, query2;
    query2.exec("SELECT rate from eval where name = '"+m+"' and movieName = '"+MovieName+"' ");
    if(query2.first()){
        ui->currently_2->setText(query2.value(0).toString());
    }
    if(query.exec("SELECT * from movie where name = '"+MovieName+"'")){
        if(query.first()){
            array =query.value(7).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            ui->SearchedMovieCover->setPixmap(pixmap);
            ui->Title_3->setText(query.value(0).toString());
            ui->description_3->setText(query.value(4).toString());
            ui->Actor_3->setText(query.value(5).toString());
            ui->Director_3->setText(query.value(6).toString());
            ui->genre->setText(query.value(1).toString());
            ui->classification->setText(query.value(3).toString());
            ui->Search->clear();
            ui->stackedWidget_3->setCurrentIndex(1);
            ui->SearchOK->setText(" ");
            ui->scrollArea->ensureVisible(0, 0,0,0);
        }

    }
}

