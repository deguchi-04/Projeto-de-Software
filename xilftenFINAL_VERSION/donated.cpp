#include "donated.h"
#include <QtSql>

int donated::don(QString username, int value)
{
        int newValue =0, resultInt;
        QString result;
        QSqlQuery query, query2;
        query.exec("SELECT donated FROM users WHERE username='"+username+"' ");
        if(query.first()) {
            resultInt = query.value(0).toInt();
            newValue = resultInt + value;
            result = QString::number(newValue);

        }
        query2.exec("UPDATE users SET donated= '"+result+"' WHERE username='"+username+"'");
        return newValue;
}
