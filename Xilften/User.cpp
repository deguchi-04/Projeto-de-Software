#include <string>
#include "User.h"

using namespace std;

void User::newUser(MYSQL *con, string nome, string mail, string age, string pass, string fullname){
    string query2 = "ALTER TABLE users AUTO_INCREMENT = 1;"; 
    mysql_query(con, query2.c_str());
    string query = "INSERT INTO users (username, mail, name, age, password, donated) VALUES ('"+nome+"', '"+mail+"', '"+fullname+"','"+age+"', '"+pass+"', '0');"; 
    mysql_query(con, query.c_str());
    
}

int User::Log(MYSQL * con, string name, string password){
    MYSQL_ROW row;
    MYSQL_RES *res;
    string query = "SELECT password FROM users WHERE username='"+name+"';"; 
    mysql_query(con, query.c_str());
    res=mysql_store_result(con);
    row=mysql_fetch_row(res);
    if (row == NULL){
        return -2;
    }
    else{
        if(password == row[0]) 
        {
            return 0;
        }
        else{
            return -1;
        }
        return 0;
    }
}

void User::showUsers(MYSQL *con){
     MYSQL_RES *res; 
     MYSQL_ROW row;	// the results rows (array)
     // get the results from executing commands
        res = mysql_perform_query(con, "select * from users;");

        //std::cout << ("Database Output:\n") << std::endl;

        while ((row = mysql_fetch_row(res)) != NULL){
            // the below row[] parametes may change depending on the size of the table and your objective
            std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | "  << endl << endl;
            
        }
}

void User::deleteAccount(MYSQL *con, string name){
    string query3 = "DELETE FROM eval WHERE name='"+name+"';"; 
    mysql_query(con, query3.c_str());
    string query = "DELETE FROM users WHERE username='"+name+"';"; 
    mysql_query(con, query.c_str());
    string query2 = "ALTER TABLE users AUTO_INCREMENT = 1;"; 
    mysql_query(con, query2.c_str());
}
