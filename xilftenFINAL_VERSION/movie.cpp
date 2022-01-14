#include "movie.h"
#include<string>
#include <QFileDialog>


Movie::Movie()
{


}
int Movie::searchMovie(QString MovieName, QPixmap q){
    QByteArray array;
    QSqlQuery query;
    if(query.exec("SELECT image from poster where name = '"+MovieName+"' ")){
        if(query.first()){
            array = query.value(0).toByteArray();
            QPixmap pixmap = QPixmap();
            pixmap.loadFromData(array);
            q = pixmap;
            return 0;
        }
        else{
             return -1;
        }
    }
return -1;
}

int Movie::MovieInsert(QString name, QString image, QString actor, QString director, QString description, QString genre){

    QSqlQuery query;
    int i = 0;
    QFile file(image);
    file.open(QIODevice::ReadOnly);
    QByteArray bytes = file.readAll();


    query.exec("SELECT name from movie");
    while(query.next()){
        if(QString::compare(name, query.value(i).toString(), Qt::CaseInsensitive) == 0){
            return -1;
        }
        else{
            continue;
        }
    }

    query.prepare(" insert into movie (name,genre, classification, description, actors, director, image) values ('"+name+"', '"+genre+"', '0','"+description+"','"+actor+"', '"+director+"', (:img))  ");
    query.bindValue(":img", QVariant(bytes));
    if(query.exec()){
        return 0;
    }
    else {
         qDebug() << "Erro ao inserir";
         return 1;
    }
    return 1;
}


float Movie::newMovieRate(QString &username, QString movieName, QString rate){
    float newGeralRate;
    QString aux;
    QSqlQuery query, query2, query3, query4, query5;
    float previousUserRate, totalUsers = 1, actualSumRate =0 , newRate;


    query.exec("SELECT rate FROM eval where name='"+username+"' AND movieName = '"+movieName+"'");
    if(query.first()){
        previousUserRate = query.value(0).toFloat();
    }
    else{
        previousUserRate = 0;
    }



    query4.exec("UPDATE eval SET rate = '"+rate+"' WHERE name='"+username+"' AND movieName='"+movieName+"'");


    query2.exec("Select count(*) from eval where  movieName = '"+movieName+"'");
    if(query2.first()){
        totalUsers = query2.value(0).toInt();
    }


    query3.exec("SELECT SUM(rate) FROM eval where movieName= '"+movieName+"'");
    if(query3.first()) {
        actualSumRate = query3.value(0).toInt();

    }


    newRate = rate.toInt();

    newGeralRate = ((actualSumRate) - previousUserRate + newRate)/totalUsers;
    aux = QString::number(newGeralRate);

    query5.exec("UPDATE movie SET classification= '"+aux+"' WHERE name='"+movieName+"'");

    return newGeralRate;

}

int Movie::countRate(QString movieN){
    QSqlQuery query;
    int n = 0;
    query.exec("SELECT count(*) from eval where movieName = '"+movieN+"' ");
    if(query.first()){
        n = query.value(0).toInt();
        return n;
    }
    else{
        return -1;
    }

}


