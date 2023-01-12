#ifndef USER_H
#define USER_H

#include <string>

#define ZERO 0
#define NO 0
#define TRUE 1

using namespace std;
class User{
    private:
        string name;
        string email;
        string password;
        int age;
        int id;
        int donated;
    public:
        void newUser(MYSQL *con, string nome, string mail, string age, string pass, string fullname);
        void searchUser();
        int Log(MYSQL * con, string name, string password);
        void changPass();
        void evalMovie(MYSQL *con, string name, string movieName, string rate);
        int countUsers();
        void showUsers(MYSQL *con);
        void deleteAccount(MYSQL *con, string name);
};
#endif
