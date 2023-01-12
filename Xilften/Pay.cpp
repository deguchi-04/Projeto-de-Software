#include <string>
#include "Pay.h"

int Pay::donate(MYSQL *con, string username, int value){
    MYSQL_ROW row;
    MYSQL_RES *res;
    int newValue, aux;
    string result;
    string query = "SELECT donated FROM users WHERE username='"+username+"';"; 
    mysql_query(con, query.c_str());
    res=mysql_store_result(con);
    row=mysql_fetch_row(res);

    aux = stoi(row[0]);
    newValue = aux + value;
    result = to_string(newValue);

    string query2 = "UPDATE users SET donated= '"+result+"' WHERE username='"+username+"';"; 
    mysql_query(con, query2.c_str());
    return newValue;
}