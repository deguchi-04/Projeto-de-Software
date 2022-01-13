#ifndef MOVIE_H
#define MOVIE_H
#include <QString>
#include <QtSql>
#include <QDebug>
#include <QList>

struct queryResult{
    QString name;
    float classification;
   QPixmap poster;
};

class Movie
{
public:
    Movie();
    int searchMovie(QString name, QPixmap q);
    queryResult TopTen();
    int MovieInsert(QString name, QString image, QString actor, QString director, QString description, QString genre);
    float newMovieRate(QString &username, QString movieName, QString rate);
    int countRate(QString movieN);
};

#endif // MOVIE_H
