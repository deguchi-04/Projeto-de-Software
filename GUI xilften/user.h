#ifndef USER_H
#define USER_H
#include <QString>


class user
{
public:
    user();
    int LogIN(QString username, QString password);
    int Register(QString username, QString email, QString age, QString password, QString fullname);
};

#endif // USER_H
