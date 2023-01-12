#include "user.h"
#include <QString>
#include <QtSql>
#include <QDebug>


user::user()
{


}

int user::LogIN(QString username, QString password)
{
    QSqlQuery query;
    if(query.exec("SELECT username, password from users where username = '"+username+"' and password = '"+password+"' ")){
        int cnt = 0;
        while(query.next()){
            cnt ++;
        }
        if(cnt > 0){
           return 0;
        }
        else{
            return 1;
        }
    }
return 1;
}

int user::Register(QString username, QString email, QString age, QString password, QString fullname){
    QSqlQuery query;
    int i =0, p =0;
    query.exec("SELECT username from users");
    while(query.next()){
        if(QString::compare(username, query.value(i).toString(), Qt::CaseInsensitive) == 0){
            return -1;
        }
        else{
            continue;
        }
    }
    query.exec("SELECT mail from users");
    while(query.next()){
        if(QString::compare(email, query.value(p).toString(), Qt::CaseInsensitive) == 0){
            return -2;
        }
        else{
            continue;
        }
    }
    query.prepare("INSERT INTO users (username, mail, name, age, password, donated) VALUES ('"+username+"', '"+email+"', '"+fullname+"','"+age+"', '"+password+"', '0')");
    if(query.exec()){
        return 0;
    }
    else {
         qDebug() << "Erro ao inserir";
    }
    return 1;

}
